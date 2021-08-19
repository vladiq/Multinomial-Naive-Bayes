#include "nbc.hpp"
#include <cmath>

std::vector<std::string> Parse(std::string& text);

void NaiveBayesClassifier::Train(const size_t train_docs_number) {
    for (size_t i = 0; i < train_docs_number; ++i) {
        document doc;
        std::string input_text;
        std::cin >> doc.class_n;
        std::cin.ignore();
        std::getline(std::cin, input_text);
        doc.text_vec = Parse(input_text);
        train_docs.push_back(doc);
        categories[doc.class_n].total_docs++;
        categories[doc.class_n].total_words += doc.text_vec.size();

        for (auto word : doc.text_vec) {
            categories[doc.class_n].word_count[word]++;
        }
    }

    std::unordered_set<std::string> unique_words;
    for (int i = 0; i <= 1; ++i) {
        for (auto iter = categories[i].word_count.begin(); iter != categories[i].word_count.end(); ++iter) {
            unique_words.insert(iter->first);
        }
    }
    size_t unique_words_number = unique_words.size();

    for (int i = 0; i <= 1; ++i) {
        categories[i].prior_prob = (long double)categories[i].total_docs / train_docs_number;
        categories[i].prob_word_not_found = 1.0 / (long double)(categories[i].total_words + unique_words_number);
    }

    for (auto it = unique_words.begin(); it != unique_words.end(); ++it) {
        for (auto i = 0; i <= 1; ++i) {
            auto iter = categories[i].word_count.find(*it);
            if (iter == categories[i].word_count.end()) {
                categories[i].cond_prob[*it] = categories[i].prob_word_not_found;
            } else {
                categories[i].cond_prob[*it] = (long double)(1.0 + categories[i].word_count[*it]) / (categories[i].total_words + unique_words_number);
            }
        }
    }
}

int NaiveBayesClassifier::Test(const std::vector<std::string>& test_doc) {
    long double predicted_prob_for_class[2];
    for (int i = 0; i <= 1; ++i) {
        predicted_prob_for_class[i] = std::log(categories[i].prior_prob);
        for (auto word : test_doc) {
            auto iter = categories[i].cond_prob.find(word);
            if (iter == categories[i].cond_prob.end()) {
                predicted_prob_for_class[i] += std::log(categories[i].prob_word_not_found);
            } else {
                predicted_prob_for_class[i] += std::log(categories[i].cond_prob[word]);
            }
        }
    }
    if (predicted_prob_for_class[0] >= predicted_prob_for_class[1]) {
        return 0;
    }
    return 1;
}

std::vector<std::string> Parse(std::string& text) {
    for (size_t i = 0; i < text.size(); i++) {
        if (std::isupper(text[i])) {
            text[i] = std::tolower(text[i]);
        } else if (std::ispunct(text[i]) && text[i] != '\'') {
            text[i] = ' ';
        }
    }
    std::istringstream ss{text};
    using StrIt = std::istream_iterator<std::string>;
    std::vector<std::string> container{StrIt{ss}, StrIt{}};
    return container;
}
