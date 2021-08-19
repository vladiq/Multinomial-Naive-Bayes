#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

struct document {
    std::vector<std::string> text_vec;
    int class_n;
};

struct category {
    std::unordered_map<std::string, long double> cond_prob;
    std::unordered_map<std::string, size_t> word_count;
    long double prob_word_not_found;
    long double prior_prob;
    size_t total_words = 0;
    size_t total_docs = 0;
};

class NaiveBayesClassifier {
public:
    NaiveBayesClassifier(){};
    void Train(const size_t train_docs_number);
    int Test(const std::vector<std::string>& test_doc);
private:
    std::vector<document> train_docs;
    std::unordered_map<int, category> categories;
};
