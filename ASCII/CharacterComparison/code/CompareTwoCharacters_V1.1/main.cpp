 /**
 * @file CharAsciiCompareSOLID.cpp
 * @brief Compares two characters based on ASCII values using SOLID principles.
 * @author 
 * Nitish Singh
 */

#include "CharInput.hpp"
#include "AsciiPrinter.hpp"
#include "AsciiComparator.hpp"

int main() {
    CharInput input;
    char ch1 = input.getChar("first");
    char ch2 = input.getChar("second");

    IPrinter* printer = new AsciiPrinter();
    IComparator* comparator = new AsciiComparator(printer);
    comparator->compare(ch1, ch2);

    delete comparator;
    delete printer;
    return 0;
}
