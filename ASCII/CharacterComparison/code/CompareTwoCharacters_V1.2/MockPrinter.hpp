#ifndef MOCKPRINTER_HPP
#define MOCKPRINTER_HPP

#include "IPrinter.hpp"
#include <vector>
#include <string>

class MockPrinter : public IPrinter {
public:
    std::vector<std::string> logs;

    void printAscii(char ch) override {
        logs.push_back("ASCII:" + std::to_string(static_cast<int>(ch)));
    }

    void printComparison(char a, char b) override {
        if (a == b)
            logs.push_back("Equal");
        else if (a < b)
            logs.push_back("A before B");
        else
            logs.push_back("B before A");
    }
};

#endif