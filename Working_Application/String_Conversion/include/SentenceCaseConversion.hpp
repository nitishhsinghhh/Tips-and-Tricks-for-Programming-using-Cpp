#ifndef SENTENCECASECONVERSION_HPP
#define SENTENCECASECONVERSION_HPP

#include "IStringConversion.hpp"

class SentenceCaseConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // SENTENCECASECONVERSION_HPP