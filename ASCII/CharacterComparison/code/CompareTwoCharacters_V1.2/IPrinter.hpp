#include <iostream>
#include <string>

#ifndef IPRINTER_HPP
#define IPRINTER_HPP

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