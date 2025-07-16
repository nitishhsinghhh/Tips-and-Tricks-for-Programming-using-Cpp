# CharAdder Application

**Author: Nitish Singh** <br>
**Email: me.singhnitish@yandex.com**

---

## 📌 Overview

This project demonstrates a simple C++ application that performs addition of numeric character strings. It includes two versions:

1. **Basic Version (v1.0)**: Adds two hardcoded character digits.

```cpp
/**
 * @file CharAdder.cpp
 * @author Nitish Singh
 * @brief Adds two numeric characters and outputs their sum.
 * @details
 * This program demonstrates a simple class `CharAdder` that takes two characters
 * representing digits ('0' to '9'), converts them to integers, adds them, and
 * displays the result. The program assumes valid numeric character input.
 *
 * @email me.singhnitish@yandex.com
 */

#include <iostream>

/**
 * @class CharAdder
 * @brief Adds two character digits by converting them to integers.
 */
class CharAdder {
public:
    /**
     * @brief Constructor to initialize the two characters.
     * @param c1 First character digit.
     * @param c2 Second character digit.
     */
    CharAdder(char c1, char c2) : char1(c1), char2(c2) {}

    /**
     * @brief Adds the numeric values of the two characters.
     * @return The integer sum of the two characters.
     */
    int add() {
        int num1 = char1 - '0';
        int num2 = char2 - '0';
        return num1 + num2;
    }

private:
    char char1; ///< First character digit
    char char2; ///< Second character digit
};

/**
 * @brief Main function to demonstrate the CharAdder class.
 * @return int Exit status.
 */
int main() {
    char c1 = '3', c2 = '7';
    CharAdder adder(c1, c2);
    int sum = adder.add();
    std::cout << "The sum of " << c1 << " and " << c2 << " is " << sum << std::endl;
    system("pause");
    return 0;
}
```
2. **Extended Version (v1.1)**: Accepts user input, validates it, and performs addition
```cpp
/*
/**
 * @file CharAdderApp.cpp
 * @author Nitish Singh
 * @date December 29, 2023
 * @brief Validates user input, adds two character strings, and outputs the sum.
 * @details
 * This program demonstrates a simple application that:
 * - Validates user input using the InputValidator class.
 * - Adds two numeric strings using the CharAdder class.
 * - Handles user interaction via the UserInput class.
 * 
 * The program ensures that both inputs are numeric and within the range [1, 3998].
 * It then converts the strings to integers and prints their sum.
 * 
 * @note Roman numeral support is not included.
 * @email me.singhnitish@yandex.com
 */

#include <iostream>
#include <string>

/**
 * @class InputValidator
 * @brief Validates if a string contains only digits and is within the range [1, 3998].
 */
class InputValidator {
public:
    /**
     * @brief Constructor to initialize the input string.
     * @param s The input string to validate.
     */
    InputValidator(std::string s) : input_str(s) {}

    /**
     * @brief Validates the input string.
     * @return true if the string is numeric and within range, false otherwise.
     */
    bool validate() {
        if (input_str.empty())
            return false;

        int input_num = 0;
        for (char c : input_str) {
            if (c < '0' || c > '9')
                return false;
            input_num = input_num * 10 + (c - '0');
        }
        return input_num >= 1 && input_num < 3999;
    }

private:
    std::string input_str; ///< Stores the input string
};

/**
 * @class CharAdder
 * @brief Adds two numeric strings after converting them to integers.
 */
class CharAdder {
public:
    /**
     * @brief Constructor to initialize the two strings.
     * @param c1 First numeric string.
     * @param c2 Second numeric string.
     */
    CharAdder(const std::string& c1, const std::string& c2) : char1(c1), char2(c2) {}

    /**
     * @brief Adds the two numeric strings.
     * @return The integer sum of the two strings.
     */
    int add() {
        int num1 = 0, num2 = 0;
        for (char c : char1)
            num1 = num1 * 10 + (c - '0');
        for (char c : char2)
            num2 = num2 * 10 + (c - '0');
        return num1 + num2;
    }

private:
    std::string char1; ///< First numeric string
    std::string char2; ///< Second numeric string
};

/**
 * @class UserInput
 * @brief Handles user input from the console.
 */
class UserInput {
public:
    /**
     * @brief Prompts the user and reads input.
     * @param message The message to display to the user.
     * @return The input string entered by the user.
     */
    std::string getInput(std::string message) {
        std::string input;
        std::cout << message;
        std::cin >> input;
        return input;
    }
};

/**
 * @brief Main function to run the program.
 * @return int Exit status.
 */
int main() {
    UserInput userInput;

    std::string input_str1 = userInput.getInput("Enter first input between 0 to 3999, both excluded: ");
    InputValidator inputValidator1(input_str1);
    if (!inputValidator1.validate()) {
        std::cout << "Invalid input: " << input_str1 << std::endl;
        system("pause");
        return -1;
    }

    std::string input_str2 = userInput.getInput("Enter second input between 0 to 3999, both excluded: ");
    InputValidator inputValidator2(input_str2);
    if (!inputValidator2.validate()) {
        std::cout << "Invalid input: " << input_str2 << std::endl;
        system("pause");
        return -1;
    }

    CharAdder adder(input_str1, input_str2);
    int sum = adder.add();
    std::cout << "The sum of " << input_str1 << " and " << input_str2 << " is " << sum << std::endl;

    system("pause");
    return 0;
}
```
---

## 🧩 Components

### 1. `InputValidator`  
Validates that the input string:
- Contains only numeric characters.
- Represents a number between **1 and 3998** (inclusive).

### 2. `CharAdder`  
Adds two numeric strings by:
- Converting each character to its integer value.
- Summing the resulting integers.

### 3. `UserInput`  
Handles user interaction by:
- Prompting the user for input.
- Returning the entered string.

---

### Valid Input Example
Enter first input between 0 to 3999, both excluded: 1234
Enter second input between 0 to 3999, both excluded: 4321
The sum of 1234 and 4321 is 5555

## Invalid Input Examples
### Non-numeric input:
Enter first input between 0 to 3999, both excluded: abc
Invalid input: abc

### Out-of-range input:
Enter first input between 0 to 3999, both excluded: 4000
Invalid input: 4000


