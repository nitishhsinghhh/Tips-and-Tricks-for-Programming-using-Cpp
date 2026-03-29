#ifndef LEETSPEAKCONVERSION_HPP
#define LEETSPEAKCONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

class LeetSpeakConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // LEETSPEAKCONVERSION_HPP