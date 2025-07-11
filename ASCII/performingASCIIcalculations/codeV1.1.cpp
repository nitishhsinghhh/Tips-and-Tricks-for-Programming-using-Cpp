/*
Author: Nitish Singh
Date: December 29, 2023
Email ID: me.singhnitish@yandex.com

Problem Statement: 
This program demonstrates a simple application that validates user input, adds two character strings, and outputs the sum.

Solution: 
The program consists of three classes:
1. InputValidator: Responsible for validating user input.
2. CharAdder: Responsible for adding two character strings.
3. UserInput: Responsible for getting user input from the console.

The main function drives the program by using instances of InputValidator to validate user input and then using CharAdder to add the validated input.

Additional Information:
- The InputValidator class checks if the input string contains only numeric characters and is within the range of 1 to 3998.
- The CharAdder class converts the character strings to integers and adds them together.
- The UserInput class gets input from the user and returns the input as a string.

Note: 
The line InputValidator(std::string s) : input_str(s) {} is a constructor for the InputValidator class. Let's break down this line:

InputValidator(std::string s): This part defines the constructor for the InputValidator class. It takes a parameter of type std::string, 
denoted as s. This means that when an object of the InputValidator class is created, it can be initialized with a string input.

: input_str(s) {}: This part is the initializer list. It is used to initialize the member variable input_str of the InputValidator class 
with the value of the parameter s passed to the constructor. This allows the member variable input_str to be set to the value of the string input when an object of InputValidator is created.
*/
#include<iostream>
#include<string>

// Class to validate user input
class InputValidator {
public:
	InputValidator(std::string s) : input_str(s) {} // parameterized Constructor to initialize input string
	bool validate() {
		if (input_str.empty())
			return false;
		int input_num = 0;
		for (char c : input_str) {
			if (c < '0' || c > '9')
				return false;
			input_num = input_num * 10 + (c - '0');
		}
		return input_num >= 1 && input_num < 3999; // Validate that input is between 1 and 3998
	}
private: 
	std::string input_str; // Store the input string for debugging
};

// Class to add two character strings
class CharAdder {
public:
	CharAdder(const std::string& c1, const std::string&c2) : char1(c1), char2(c2) {}	// parameterized Constructor
	int add() {
		int num1 = 0, num2 = 0;
		for (char c : char1)
			num1 = num1 * 10 + (c - '0');
		for (char c : char2)
			num2 = num2 * 10 + (c - '0');
		return num1 + num2;
	}
private:
	std::string char1, char2;
};

// Class to get user input
class UserInput {
public:
	std::string getInput(std::string message) {
		std::string input;
		std::cout << message;
		std::cin >> input;
		return input;
	}
};

// Main function to run the program
int main() {
	UserInput userInput;
	std::string input_str1 = userInput.getInput("Enter first input between 0 to 3999, both excluded: ");
	InputValidator inputValidator1(input_str1);
	if (inputValidator1.validate() != true) {
		std::cout << "Invalid input: " << input_str1 << std::endl;
		system("pause");
		return -1;
	}

	std::string input_str2 = userInput.getInput("Enter second input between 0 to 3999, both excluded: ");
	InputValidator inputValidator2(input_str2);
	if (inputValidator2.validate() != true) {
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

/*
Enter first input between 0 to 3999, both excluded: 566
Enter second input between 0 to 3999, both excluded: 566
The sum of 566 and 566 is 1132
Press any key to continue . . .
*/
