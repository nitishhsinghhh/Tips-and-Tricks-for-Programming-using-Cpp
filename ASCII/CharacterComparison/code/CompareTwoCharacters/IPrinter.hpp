#ifndef IPRINTER_HPP
#define IPRINTER_HPP

#include <iostream>
#include <string>

/**
 * @interface IPrinter
 * @brief Interface for printing ASCII values and comparison results.
 */
class IPrinter {
public:
    virtual void printAscii(char ch) = 0;
    virtual void printComparison(char a, char b) = 0;
    virtual ~IPrinter() = default;
};

#endif