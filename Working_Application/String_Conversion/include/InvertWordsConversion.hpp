#ifndef INVERTWORDSCONVERSION_HPP
#define INVERTWORDSCONVERSION_HPP

#include "IStringConversion.hpp"
#include <string>

class InvertWordsConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // INVERTWORDSCONVERSION_HPP