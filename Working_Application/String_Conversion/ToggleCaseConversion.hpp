#ifndef TOGGLECASECONVERSION_HPP
#define TOGGLECASECONVERSION_HPP

#include "IStringConversion.hpp"
#include <cctype>

class ToggleCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override {
        std::string result = input;

        for (auto& c : result) {
            if (std::islower(static_cast<unsigned char>(c)))
                c = std::toupper(static_cast<unsigned char>(c));
            else if (std::isupper(static_cast<unsigned char>(c)))
                c = std::tolower(static_cast<unsigned char>(c));
        }
        return result;
    }
};

#endif // TOGGLECASECONVERSION_HPP