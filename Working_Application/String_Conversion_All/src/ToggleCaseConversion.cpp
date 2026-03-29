#include "ToggleCaseConversion.hpp"
#include <cctype>

std::string ToggleCaseConversion::convert(const std::string& input) const {
    std::string result = input;

    for (auto &c : result) {
        if (std::islower(static_cast<unsigned char>(c)))
            c = std::toupper(static_cast<unsigned char>(c));
        else if (std::isupper(static_cast<unsigned char>(c)))
            c = std::tolower(static_cast<unsigned char>(c));
    }

    return result;
}