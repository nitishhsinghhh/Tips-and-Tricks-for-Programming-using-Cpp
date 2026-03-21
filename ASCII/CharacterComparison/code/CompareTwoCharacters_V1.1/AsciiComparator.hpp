#pragma once
#include "IComparator.hpp"

/**
 * @class AsciiComparator
 * @brief Compares two characters and delegates printing.
 */
class AsciiComparator : public IComparator {
public:
    /**
     * @brief Constructor with dependency injection.
     * @param p Pointer to a printer object.
     */

    void compare(char a, char b) override {
        printer->printAscii(a);
        printer->printAscii(b);
        printer->printComparison(a, b);
    }
};
