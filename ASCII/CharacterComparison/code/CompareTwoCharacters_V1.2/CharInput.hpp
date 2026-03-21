#ifndef CHARINPUT_HPP
#define CHARINPUT_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

/**
 * @class CharInput
 * @brief Handles user input of characters.
 */
class CharInput {
public:
    char getChar(const string& label) {
        char ch;
        cout << "Enter " << label << " character: ";
        cin >> ch;
        return ch;
    }
};

#endif