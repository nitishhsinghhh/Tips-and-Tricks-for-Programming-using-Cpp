#ifndef CAPITALIZEWORDSCONVERSION_HPP
#define CAPITALIZEWORDSCONVERSION_HPP

#include "IStringConversion.hpp"
#include <sstream>
#include <cctype>

class CapitalizeWordsConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override {
        std::istringstream iss(input);
        std::string word, result;

        while (iss >> word) {
            if (!result.empty()) result += " ";
            word[0] = std::toupper(static_cast<unsigned char>(word[0]));
            for (size_t i = 1; i < word.size(); ++i)
                word[i] = std::tolower(static_cast<unsigned char>(word[i]));

            result += word;
        }
        return result;
    }
};

#endif // CAPITALIZEWORDSCONVERSION_HPP