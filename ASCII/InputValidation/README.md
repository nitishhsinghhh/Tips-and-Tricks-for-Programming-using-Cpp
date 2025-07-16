# Validating Input Data in C++ Programming
ASCII, which stands for American Standard Code for Information Interchange, is a character encoding standard used in computers and communication equipment to represent text and control characters. In the context of validating input, ASCII can be used to convert characters to their corresponding numeric values.

When a character is input by the user, it is represented in the computer's memory as a numeric value based on the ASCII encoding. For example, the character '0' has an ASCII value of 48, '1' has a value of 49, and so on up to '9' with a value of 57.

In the provided code snippet, the input character is converted to a numeric value by subtracting the ASCII value of '0' (48) from the input character's ASCII value. This conversion allows the program to work with numeric values directly and perform validation based on the input range from 1 to 9.

By leveraging ASCII values in this manner, the program can efficiently validate user input and ensure that it meets the specified criteria without explicitly checking each possible character input. This approach simplifies the validation process by relying on the inherent numeric representation of characters in the ASCII encoding scheme.

## C++ Program: Validate Single-Character Numeric Input (1–9) with Assertions and Modular Design

```cpp
/**
 * @file main.cpp
 * @author Nitish Singh
 * @brief Program to validate a single-digit input between 1 and 9.
 * @details
 * This program accepts a single character input from the user and checks whether it represents
 * a valid digit between 1 and 9. It uses the Single Responsibility Principle by separating
 * validation logic and input/output handling into different classes. The program also includes
 * test cases and assertions to verify correctness.
 *
 * @email me.singhnitish@yandex.com
 */

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

/**
 * @class IValidator
 * @brief Interface for input validation.
 */
class IValidator {
public:
    /**
     * @brief Validates the input number.
     * @param input The integer to validate.
     * @return true if input is valid, false otherwise.
     */
    virtual bool validate(int input) const = 0;
    virtual ~IValidator() = default;
};

/**
 * @class InputValidator
 * @brief Validates if a number is between 1 and 9.
 */
class InputValidator : public IValidator {
public:
    /**
     * @brief Checks if the input is within the valid range.
     * @param input The number to validate.
     * @return true if input is between 1 and 9, false otherwise.
     */
    bool validate(int input) const override {
        return input >= 1 && input <= 9;
    }
};

/**
 * @class IInputHandler
 * @brief Interface for handling input.
 */
class IInputHandler {
public:
    /**
     * @brief Handles user or test input.
     */
    virtual void handleInput() = 0;
    virtual ~IInputHandler() = default;
};

/**
 * @class TestInputHandler
 * @brief Handles predefined test inputs for validation.
 */
class TestInputHandler : public IInputHandler {
private:
    IValidator& validator;
    std::vector<std::string> testInputs;

public:
    /**
     * @brief Constructor for TestInputHandler.
     * @param val Reference to a validator object.
     * @param inputs A list of test input strings.
     */
    TestInputHandler(IValidator& val, const std::vector<std::string>& inputs)
        : validator(val), testInputs(inputs) {}

    /**
     * @brief Processes each test input and prints validation results.
     */
    void handleInput() override {
        for (const auto& input_str : testInputs) {
            std::cout << "Input: " << input_str << std::endl;

            if (input_str.length() == 1 && isdigit(input_str[0])) {
                int input_num = input_str[0] - '0';
                bool result = validator.validate(input_num);
                std::cout << (result ? "Valid input: " : "Invalid input: ") << input_num << std::endl;
            } else {
                std::cout << "Invalid input size or format: " << input_str << std::endl;
            }

            std::cout << std::endl;
        }
    }
};

/**
 * @brief Runs unit tests on InputValidator using assertions.
 */
void runValidatorTests() {
    InputValidator validator;

    assert(validator.validate(1) == true);
    assert(validator.validate(5) == true);
    assert(validator.validate(9) == true);
    assert(validator.validate(0) == false);
    assert(validator.validate(10) == false);
    assert(validator.validate(-3) == false);

    std::cout << "All validator tests passed!\n\n";
}

/**
 * @brief Main function to run tests and demonstrate input handling.
 * @return int Exit status.
 */
int main() {
    runValidatorTests();  

    InputValidator validator;

    std::vector<std::string> testCases = {
        "10",  // Invalid size
        "9",   // Valid
        "1",   // Valid
        "0",   // Invalid
        "J"    // Invalid format
    };

    TestInputHandler testHandler(validator, testCases);
    testHandler.handleInput();

    return 0;
}
```

### Key Features:
- Uses an interface-based validator (IValidator) that validates integers.
- Implements unit testing using assert() in runValidatorTests().
- Uses a TestInputHandler class to simulate and validate multiple test inputs.
- Focuses on test automation and modular validation.
- Does not include manual user input; it's designed for automated testing.

## C++ Program: Validate Single-Character Numeric Input (1–9) with Interactive Input and SOLID Design

```cpp
/**
 * @file SingleDigitValidator.cpp
 * @author Nitish Singh
 * @brief Validates a single-character input representing a number between 1 and 9.
 * @details
 * This program prompts the user to enter a single character representing a digit between 1 and 9.
 * It validates the input and prints whether it is valid or invalid. The design follows SOLID principles
 * and includes a test class to simulate multiple input scenarios.
 *
 * @email me.singhnitish@yandex.com
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * @interface IValidator
 * @brief Interface for input validation.
 */
class IValidator {
public:
    virtual bool validate() = 0;
    virtual int getValue() = 0;
    virtual ~IValidator() = default;
};

/**
 * @class DigitValidator
 * @brief Validates if a single character represents a digit between 1 and 9.
 */
class DigitValidator : public IValidator {
private:
    char input_char;
    int value;

public:
    /**
     * @brief Constructor to initialize input character.
     * @param ch The input character.
     */
    DigitValidator(char ch) : input_char(ch), value(0) {}

    /**
     * @brief Validates if the character is a digit between '1' and '9'.
     * @return true if valid, false otherwise.
     */
    bool validate() override {
        if (isdigit(input_char)) {
            value = input_char - '0';
            return value >= 1 && value <= 9;
        }
        return false;
    }

    /**
     * @brief Returns the numeric value of the input character.
     * @return Integer value.
     */
    int getValue() override {
        return value;
    }
};

/**
 * @class InputHandler
 * @brief Handles user input and delegates validation.
 */
class InputHandler {
public:
    /**
     * @brief Prompts user for input and validates it.
     */
    void handle() {
        std::string input_str;
        std::cout << "Enter a number between 1 and 9, both included: ";
        std::cin >> input_str;

        if (input_str.length() == 1) {
            char input_char = input_str[0];
            DigitValidator validator(input_char);
            if (validator.validate())
                std::cout << "Valid input: " << validator.getValue() << std::endl;
            else
                std::cout << "Invalid input: " << input_char << std::endl;
        } else {
            std::cout << "Invalid input size: " << input_str.length() << std::endl;
        }
    }
};

/**
 * @class InputTest
 * @brief Runs predefined test cases for validation.
 */
class InputTest {
private:
    std::vector<std::string> testCases;

public:
    /**
     * @brief Initializes test cases.
     */
    InputTest() {
        testCases = {"10", "9", "1", "0", "J"};
    }

    /**
     * @brief Runs all test cases and prints results.
     */
    void run() {
        for (const auto& input_str : testCases) {
            std::cout << "Test input: " << input_str << std::endl;

            if (input_str.length() == 1) {
                char input_char = input_str[0];
                DigitValidator validator(input_char);
                if (validator.validate())
                    std::cout << "Valid input: " << validator.getValue() << std::endl;
                else
                    std::cout << "Invalid input: " << input_char << std::endl;
            } else {
                std::cout << "Invalid input size: " << input_str.length() << std::endl;
            }

            std::cout << std::endl;
        }
    }
};

/**
 * @brief Main function to run test suite and optionally handle user input.
 * @return int Exit status.
 */
int main() {
    std::cout << "Running predefined test cases:\n" << std::endl;
    InputTest tester;
    tester.run();

    std::cout << "Now accepting manual input:\n" << std::endl;
    InputHandler handler;
    handler.handle();

    return 0;
}
```

### Key Features:
- Uses an interface-based validator (IValidator) that validates characters.
- Implements a DigitValidator class that converts and validates a single character.
- Includes an InputTest class to simulate test cases.
- Accepts manual input from the user after running test cases.
- Focuses on interactive validation and runtime input handling.

## C++ Program: Validate Single-Character Numeric Input (1–3999)
```cpp
/**
 * @file RomanIntegerValidator.cpp
 * @author Nitish Singh
 * @brief Validates user input as an integer between 1 and 3999.
 * @details
 * This program prompts the user to enter a number between 1 and 3999 (inclusive).
 * It validates whether the input is a valid integer in that range and outputs the result.
 * The design follows SOLID principles by separating validation and input/output responsibilities.
 * Currently, only integer input is supported; Roman numeral support can be added later.
 *
 * @email me.singhnitish@yandex.com
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * @interface IValidator
 * @brief Interface for input validation.
 */
class IValidator {
public:
    /**
     * @brief Validates the input string.
     * @return true if valid, false otherwise.
     */
    virtual bool validate() = 0;

    /**
     * @brief Returns the parsed integer value if valid.
     * @return Integer representation of input.
     */
    virtual int getValue() = 0;

    virtual ~IValidator() = default;
};

/**
 * @class IntegerValidator
 * @brief Validates if a string represents an integer between 1 and 3999.
 */
class IntegerValidator : public IValidator {
private:
    std::string input_str;
    int value;

public:
    /**
     * @brief Constructor to initialize input string.
     * @param input The user input string.
     */
    IntegerValidator(const std::string& input) : input_str(input), value(0) {}

    /**
     * @brief Validates if the input is a valid integer in the range [1, 3999].
     * @return true if valid, false otherwise.
     */
    bool validate() override {
        if (input_str.empty()) return false;

        for (char c : input_str) {
            if (!isdigit(c)) return false;
        }

        value = std::stoi(input_str);
        return value >= 1 && value <= 3999;
    }

    /**
     * @brief Returns the parsed integer value.
     * @return Integer value of the input.
     */
    int getValue() override {
        return value;
    }
};

/**
 * @class InputHandler
 * @brief Handles user input and delegates validation.
 */
class InputHandler {
private:
    IValidator& validator;

public:
    /**
     * @brief Constructor to inject a validator.
     * @param val Reference to a validator object.
     */
    InputHandler(IValidator& val) : validator(val) {}

    /**
     * @brief Handles input validation and prints the result.
     */
    void handle() {
        if (validator.validate()) {
            std::cout << "Valid input: " << validator.getValue() << std::endl;
        } else {
            std::cout << "Invalid input." << std::endl;
        }
    }
};

/**
 * @class ValidatorTest
 * @brief Runs predefined test cases for validation.
 */
class ValidatorTest {
private:
    std::vector<std::string> testInputs;

public:
    /**
     * @brief Constructor to initialize test cases.
     */
    ValidatorTest() {
        testInputs = {
            "0",        // Invalid
            "3999",     // Valid
            "MCMXCIX",  // Invalid (Roman numeral)
            "MMCMXCIX", // Invalid (Roman numeral)
            "123",      // Valid
            "4000",     // Invalid
            "abc",      // Invalid
            "",         // Invalid
            "007",      // Valid (interpreted as 7)
        };
    }

    /**
     * @brief Runs all test cases and prints results.
     */
    void runTests() {
        for (const auto& input : testInputs) {
            std::cout << "Test input: " << input << std::endl;
            IntegerValidator validator(input);
            InputHandler handler(validator);
            handler.handle();
            std::cout << std::endl;
        }
    }
};

/**
 * @brief Main function to run test suite.
 * @return int Exit status.
 */
int main() {
    ValidatorTest testSuite;
    testSuite.runTests();
    return 0;
}
```

## Key Features:
- Uses an interface-based validator (IValidator) that abstracts the validation logic for different input types.
- Implements an IntegerValidator class that validates whether a string represents a valid integer between 1 and 3999.
- Includes a ValidatorTest class to simulate and run multiple predefined test cases.
- Separates input handling using the InputHandler class, which delegates validation and displays results.
- Focuses on test-driven validation and modular design, making it easy to extend (e.g., to support Roman numerals in the future).
- Handles edge cases such as empty strings, non-digit characters, and out-of-range values.
- Follows SOLID principles, especially the Single Responsibility and Open/Closed principles, for clean and maintainable code.

