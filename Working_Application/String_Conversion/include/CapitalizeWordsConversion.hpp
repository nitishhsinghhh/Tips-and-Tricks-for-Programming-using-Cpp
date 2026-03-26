#ifndef CAPITALIZEWORDSCONVERSION_HPP
#define CAPITALIZEWORDSCONVERSION_HPP

#include "IStringConversion.hpp"

class CapitalizeWordsConversion : public IStringConversion {
public:
    std::string convert(const std::string& input) const override;
};

#endif // CAPITALIZEWORDSCONVERSION_HPP