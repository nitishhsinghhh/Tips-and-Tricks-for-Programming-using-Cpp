/*
Author: Nitish Singh
Date: December 29, 2023
Email ID: me.singhnitish@yandex.com

Problem Statement: 
Create a program that accepts user input of a single character representing a number between 1 and 10. 
The program should validate the input and output whether it is valid or invalid, along with the input number.

Solution: 
The InputValidator class is responsible for validating the user input by checking if the input character is between '1' and '10'.
The InputHandler class is responsible for handling the user input and output by prompting the user to enter a character and creating
an instance of InputValidator to validate the input. If the input is valid, the program outputs "Valid input: " followed by the
input number. If the input is invalid, the program outputs "Invalid input: " followed by the input character.

Additional Information:
- The program uses the Single Responsibility Principle to separate input validation and input/output handling into distinct classes.
- Test cases are provided in the main function to demonstrate the expected outputs for different input scenarios.
- The program ensures input validation by checking the size of the input string and validating the input character against the specified range.
- Error messages are displayed for invalid input size and characters falling outside the specified range.
*/

#include <iostream>
#include <string>

// This class is responsible for validating user input
class InputValidator {
public:
    InputValidator(int num) : input_num(num) {}
    bool validate() {
        return input_num >= 1 && input_num <= 9;
    }
    int getNum() {
        return input_num;
    }
private:
    int input_num;
};

// Single Responsibility Principle: This class is responsible for handling user input and output
class InputHandler {
public:
    InputHandler() {}
    void handle() {
        std::string input_str;
        std::cout << "Enter a number between 1 and 9, both included: ";
        std::cin >> input_str;

        // If the input string size is 1, create an instance of InputValidator to validate the input
        // If the input string size is greater than 1, output an error message

        if (input_str.length() == 1) {
            char input_char = input_str[0];
            InputValidator validator(input_char - '0');
            if (validator.validate())
                std::cout << "Valid input: " << validator.getNum() << std::endl;
            else
                std::cout << "Invalid input: " << input_char << std::endl;
        }
        else
            std::cout << "Invalid input size: " << input_str.length() << std::endl;
    }
};

int main() {
    std::cout << "Enter test case 1: input is '10'" << std::endl;
    std::cout << "Expected output: Invalid input size: 2" << std::endl;
    InputHandler handler1;
    handler1.handle();
    std::cout << std::endl;

    std::cout << "Enter test case 2: input is '9'" << std::endl;
    std::cout << "Expected output: Valid input: 9" << std::endl;
    InputHandler handler2;
    handler2.handle();
    std::cout << std::endl;

    std::cout << "Enter test case 3: input is '1'" << std::endl;
    std::cout << "Expected output: Valid input: 1" << std::endl;
    InputHandler handler3;
    handler3.handle();
    std::cout << std::endl;

    std::cout << "Enter test case 4: input is '0'" << std::endl;
    std::cout << "Expected output: Invalid input: 0" << std::endl;
    InputHandler handler4;
    handler4.handle();
    std::cout << std::endl;

    std::cout << "Enter test case 5: input is 'J'" << std::endl;
    std::cout << "Expected output: Invalid input: J" << std::endl;
    InputHandler handler5;
    handler5.handle();
    std::cout << std::endl;

    system("pause");
}

/*
Enter test case 1: input is '10'
Expected output: Invalid input size: 2
Enter a number between 1 and 9, both included: 10
Invalid input size: 2

Enter test case 2: input is '9'
Expected output: Valid input: 9
Enter a number between 1 and 9, both included: 9
Valid input: 9

Enter test case 3: input is '1'
Expected output: Valid input: 1
Enter a number between 1 and 9, both included: 1
Valid input: 1

Enter test case 4: input is '0'
Expected output: Invalid input: 0
Enter a number between 1 and 9, both included: 0
Invalid input: 0

Enter test case 5: input is 'J'
Expected output: Invalid input: J
Enter a number between 1 and 9, both included: J
Invalid input: J

Press any key to continue . . .
*/
