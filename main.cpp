#include "nbc.hpp"

std::vector<std::string> Parse(std::string& text);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t train_docs_number, test_docs_number;
    std::cin >> train_docs_number;
    std::cin >> test_docs_number;
    if (train_docs_number == 0 || test_docs_number == 0) {
        return 0;
    }

    NaiveBayesClassifier nbc;
    nbc.Train(train_docs_number);

    std::vector<std::string> test_doc;
    std::string input_text;
    for (size_t i = 0; i < test_docs_number; ++i) {
        if (!std::getline(std::cin, input_text)) {
            return 0;
        }
        test_doc = Parse(input_text);
        std::cout << nbc.Test(test_doc) << std::endl;
    }

    return 0;
}
