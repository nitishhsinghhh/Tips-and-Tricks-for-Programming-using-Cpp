# Sorting and Converting Strings to Integers (Basic Version)
```cpp
/**
 * @file StringSorterAndConverter.cpp
 * @author Nitish Singh
 * @brief A program that sorts and converts strings to integers, then finds the smallest and largest.
 *
 * @details
 * This program demonstrates a simple application that:
 * - Sorts two numeric strings
 * - Converts them to integers
 * - Determines and prints the smallest and largest values
 */

#include <iostream>
#include <algorithm>
#include <string>

/**
 * @class StringConverter
 * @brief Sorts a string and converts it to an integer.
 *
 * This class handles sorting of a string and converting it to an integer.
 * It also handles negative numbers if the string starts with a '-'.
 */
class StringConverter {
public:
    /**
     * @brief Constructor to initialize the input string.
     * @param str The string to be sorted and converted.
     */
    StringConverter(std::string str) : input_str(str) {}

    /**
     * @brief Sorts the string and converts it to an integer.
     * @return The integer value of the sorted string.
     */
    int convert() {
        std::sort(input_str.begin(), input_str.end());
        int result = 0, sign = 1, i = 0;
        if (input_str[0] == '-') {
            sign = -1;
            i = 1;
        }
        for (; i < input_str.length(); i++)
            result = result * 10 + (input_str[i] - '0');
        return result * sign;
    }

private:
    std::string input_str; ///< The input string to be processed
};

/**
 * @class InputHandler
 * @brief Handles the logic for comparing two converted strings.
 *
 * This class creates instances of StringConverter, converts the strings,
 * and determines the smallest and largest values.
 */
class InputHandler {
public:
    /**
     * @brief Default constructor.
     */
    InputHandler() {}

    /**
     * @brief Handles the conversion and comparison of two strings.
     */
    void handle() {
        std::string str1 = "65321", str2 = "98765";

        // Convert strings to integers
        StringConverter converter1(str1);
        StringConverter converter2(str2);
        int num1 = converter1.convert();
        int num2 = converter2.convert();

        // Determine and display smallest and largest
        if (num1 < num2)
            std::swap(num1, num2);

        std::cout << "The smallest number is " << num2 << std::endl;
        std::cout << "The largest number is " << num1 << std::endl;
    }
};

/**
 * @brief Main function to execute the program.
 * @return Exit status.
 */
int main() {
    InputHandler handler;
    handler.handle();
    system("pause");
    return 0;
}
```

## Key Features:
- Uses StringConverter to sort a string and convert it to an integer.
- Uses InputHandler to create two hardcoded strings ("65321" and "98765"), convert them, and print the smallest and largest.
- No error handling or user input.
- Uses int for conversion.

## Limitations:
- No input validation.
- No exception handling.
- Limited to small integer values.

# Sorting and Converting Strings with Overflow Handling

```cpp/**
 * @file StringSortAndCompare.cpp
 * @author Nitish Singh
 * @brief Sorts and converts two strings to integers, then outputs the smallest and largest.
 *
 * @details
 * This program demonstrates a simple application that:
 * - Sorts two numeric strings
 * - Converts them to integers
 * - Determines and prints the smallest and largest values
 * 
 * It also includes a note about the maximum size of integers that can be represented in 32-bit and 64-bit systems.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <climits>

/**
 * @class StringConverter
 * @brief Sorts a string and converts it to an integer.
 *
 * This class handles:
 * - Sorting digits in descending order
 * - Validating numeric characters
 * - Handling negative signs
 * - Checking for integer overflow
 */
class StringConverter {
public:
    /**
     * @brief Constructor to initialize the input string.
     * @param str The string to be sorted and converted.
     */
    StringConverter(std::string str) : input_str(str) {}

    /**
     * @brief Sorts the string and converts it to an integer.
     * @return The integer value of the sorted string.
     * @throws std::invalid_argument if the string contains non-numeric characters or overflows int.
     */
    int convert() {
        int sign = 1, i = 0;
        if (input_str[0] == '-') {
            sign = -1;
            i = 1;
        }

        int count[10] = { 0 };
        for (; i < input_str.length(); i++) {
            if (input_str[i] < '0' || input_str[i] > '9')
                throw std::invalid_argument("Input string contains non-numeric characters");
            count[input_str[i] - '0']++;
        }

        int result = 0;
        for (int j = 9; j >= 0; j--) {
            for (int k = 0; k < count[j]; k++) {
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && j > INT_MAX % 10))
                    throw std::invalid_argument("Input string exceeds maximum value that can be represented by an int");
                result = result * 10 + j;
            }
        }

        return result * sign;
    }

private:
    std::string input_str; ///< The input string to be processed
};

/**
 * @class InputHandler
 * @brief Handles the logic for comparing two converted strings.
 *
 * This class creates instances of StringConverter, converts the strings,
 * and determines the smallest and largest values.
 */
class InputHandler {
public:
    /**
     * @brief Default constructor.
     */
    InputHandler() {}

    /**
     * @brief Handles the conversion and comparison of two strings.
     */
    void handle() {
        std::string str1 = "65321", str2 = "98765";

        // Convert strings to integers
        StringConverter converter1(str1);
        StringConverter converter2(str2);
        int num1 = converter1.convert();
        int num2 = converter2.convert();

        // Determine and display smallest and largest
        if (num1 < num2)
            std::swap(num1, num2);

        std::cout << "The smallest number is " << num2 << std::endl;
        std::cout << "The largest number is " << num1 << std::endl;
    }
};

/**
 * @brief Main function to execute the program.
 * @return Exit status.
 */
int main() {
    std::cout << "*** Note: The maximum size of the input string that can be converted to an int is limited by the maximum value that can be represented by an int. ***" << std::endl << std::endl;
    std::cout << "\tFor a signed 32-bit int, this is 2,147,483,647." << std::endl;
    std::cout << "\tFor a signed 64-bit int, this is 9,223,372,036,854,775,807." << std::endl << std::endl;

    InputHandler handler;
    handler.handle();

    system("pause");
    return 0;
}
```
## Key Features:
- Builds on Program 1 by adding:
- Overflow checks using INT_MAX.
- Input validation for non-numeric characters.
- Still uses hardcoded strings.
- Uses int for conversion.
- Includes a note about 32-bit and 64-bit integer limits.

## Improvements Over Program 1:
- Safer conversion with overflow protection.
- More robust error checking.
- Better user guidance via console messages.

## Limitations:
- Still no user input.
- Limited to int range.

# Full User Input with Long Integer Support

```cpp/**
 * @file StringToLongConverter.cpp
 * @author Nitish Singh
 * @brief Converts two input strings to long integers and determines the smallest and largest.
 *
 * @details
 * This program:
 * - Accepts two numeric strings from the user
 * - Converts them to long integers
 * - Handles invalid input and overflow
 * - Outputs the smallest and largest values
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <climits>

/**
 * @class StringConverter
 * @brief Converts a numeric string to a long integer after sorting digits in descending order.
 *
 * This class:
 * - Validates that the string contains only digits (and an optional leading '-')
 * - Sorts digits in descending order
 * - Converts the result to a long integer
 * - Checks for overflow
 */
class StringConverter {
public:
    /**
     * @brief Constructor to initialize the input string.
     * @param str The string to be converted.
     */
    StringConverter(std::string str) : input_str(str) {}

    /**
     * @brief Converts the string to a long integer.
     * @return The converted long integer.
     * @throws std::invalid_argument if the string contains non-numeric characters or overflows.
     */
    long convert() {
        int sign = 1, i = 0;
        if (input_str[0] == '-') {
            sign = -1;
            i = 1;
        }

        int count[10] = { 0 };
        for (; i < input_str.length(); i++) {
            if (input_str[i] < '0' || input_str[i] > '9')
                throw std::invalid_argument("Input string contains non-numeric characters");
            count[input_str[i] - '0']++;
        }

        long result = 0;
        for (int j = 9; j >= 0; j--) {
            for (int k = 0; k < count[j]; k++) {
                if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && j > LONG_MAX % 10))
                    throw std::invalid_argument("Input string exceeds maximum value that can be represented by a long");
                result = result * 10 + j;
            }
        }

        return result * sign;
    }

private:
    std::string input_str; ///< The input string to be processed
};

/**
 * @class InputHandler
 * @brief Handles user input, conversion, and output.
 *
 * This class:
 * - Prompts the user for input
 * - Validates and converts input using StringConverter
 * - Displays the smallest and largest values
 */
class InputHandler {
public:
    /**
     * @brief Default constructor.
     */
    InputHandler() {}

    /**
     * @brief Handles the input, conversion, and output process.
     * @throws std::invalid_argument if input is invalid or exceeds size limits.
     */
    void handle() {
        std::string str1, str2;
        std::cout << "The maximum valid input that can be converted is: " << LONG_MAX << std::endl;
        std::cout << "Enter the first number: ";
        std::cin >> str1;
        std::cout << "Enter the second number: ";
        std::cin >> str2;

        if (str1.length() > std::to_string(LONG_MAX).length() || str2.length() > std::to_string(LONG_MAX).length())
            throw std::invalid_argument("Input string exceeds maximum size that can be converted to a long");

        StringConverter converter1(str1);
        StringConverter converter2(str2);
        long num1 = converter1.convert();
        long num2 = converter2.convert();

        if (num1 < num2)
            std::swap(num1, num2);

        std::cout << "The smallest number is " << num2 << std::endl;
        std::cout << "The largest number is " << num1 << std::endl;
    }
};

/**
 * @brief Main function to execute the program.
 * @return Exit status.
 */
int main() {
    InputHandler input_handler;
    try {
        input_handler.handle();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    system("pause");
    return 0;
}
```

## Key Features:
- Accepts user input for both strings.
- Uses long instead of int to support larger numbers.

## Validates:
- Input length against LONG_MAX.
- Non-numeric characters.
- Overflow during conversion.
- Uses try-catch to handle exceptions gracefully.

## Improvements Over Program 2:
- Accepts dynamic input from the user.
- Supports larger values using long.
- Fully robust with exception handling and input validation.

# Summary Table

| Feature                  | Program 1   | Program 2           | Program 3               |
|--------------------------|-------------|----------------------|--------------------------|
| Input Type               | Hardcoded   | Hardcoded            | User input               |
| Data Type Used           | int         | int                  | long                     |
| Sorting                  | Yes         | Yes                  | Yes                      |
| Overflow Handling        | ❌          | ✅ (INT_MAX)         | ✅ (LONG_MAX)            |
| Non-Numeric Validation   | ❌          | ✅                   | ✅                       |
| Exception Handling       | ❌          | ✅ (basic)           | ✅ (full try-catch)      |
| User Guidance / Notes    | ❌          | ✅ (int size info)   | ✅ (long size info)      |
