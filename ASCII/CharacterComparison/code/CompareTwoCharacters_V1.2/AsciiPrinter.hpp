#ifndef ASCIIPRINTER_HPP
#define ASCIIPRINTER_HPP

#include <iostream>
#include "IPrinter.hpp"

using std::cout;
using std::endl;

/**
 * @class AsciiPrinter
 * @brief Prints ASCII values and comparison results.
 */
class AsciiPrinter : public IPrinter {
public:
    void printAscii(char ch) override {
        cout << "ASCII of '" << ch << "' is " << static_cast<int>(ch) << endl;
    }

    void printComparison(char a, char b) override {
        if (a == b)
            cout << "Both characters are equal.\n";
        else if (a < b)
            cout << a << " comes before " << b << " in ASCII order.\n";
        else
            cout << b << " comes before " << a << " in ASCII order.\n";
    }
};

#endif