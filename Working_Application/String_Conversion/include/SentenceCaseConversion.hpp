#ifndef SENTENCECASECONVERSION_HPP
#define SENTENCECASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <cctype>

class SentenceCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override {
        if (input.empty()) return input;

        std::string result = input;
        result[0] = std::toupper(static_cast<unsigned char>(result[0]));

        for (size_t i = 1; i < result.size(); ++i)
            result[i] = std::tolower(static_cast<unsigned char>(result[i]));

        return result;
    }
};

#endif // SENTENCECASECONVERSION_HPP