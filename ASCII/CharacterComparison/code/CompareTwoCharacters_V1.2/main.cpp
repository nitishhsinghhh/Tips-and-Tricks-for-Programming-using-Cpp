#include "CharInput.hpp"
#include "AsciiPrinter.hpp"
#include "AsciiComparator.hpp"

/**
 * @brief Compare two characters using a printer.
 */
void compareChars(char ch1, char ch2, IPrinter* printer) {
    IComparator* comparator = new AsciiComparator(*printer);
    comparator->compare(ch1, ch2);
    delete comparator;
}

int main() {
    CharInput input;
    char ch1 = input.getChar("first");
    char ch2 = input.getChar("second");

    IPrinter* printer = new AsciiPrinter();
    compareChars(ch1, ch2, printer);
    delete printer;

    return 0;
}