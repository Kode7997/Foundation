#include <iostream>
#include <string>
#include <vector>

bool isAlphaNum(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

std::string cleanString(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (isAlphaNum(c)) {
            result += c;
        }
    }
    return result;
}

std::vector<std::string> splitString(const std::string& input) {
    std::vector<std::string> words;
    std::string word;
    for (char c : input) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) { // last word
        words.push_back(word);
    }
    return words;
}

int main() {
    std::string input = "Hello, World! 123";
    std::string cleaned = cleanString(input);
    std::vector<std::string> words = splitString(cleaned);
    
    std::cout << "Cleaned and Split Words:" << std::endl;
    for (const std::string& word : words) {
        std::cout << word << std::endl;
    }
    
    return 0;
}
