/*
Author: Nitish Singh
Date: December 29, 2023
Email ID: me.singhnitish@yandex.com

Problem Statement:
This program demonstrates a simple application that converts two input strings to long integers, determines the smallest and largest numbers, and handles potential input errors.

Solution:
The program consists of two classes:
1. StringConverter: Responsible for converting a string to a long integer and handling potential input errors.
2. InputHandler: Responsible for handling user input and output.

The main function drives the program by using instances of StringConverter to convert strings to long integers, determine the smallest and largest numbers, and handle potential input errors.

Additional Information:
- The StringConverter class converts the input strings to long integers and checks for non-numeric characters and input size constraints.
- The InputHandler class gets user input, handles potential input errors, and outputs the smallest and largest numbers to the console.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <climits>

class StringConverter {
public:
	StringConverter(std::string str) : input_str(str) {}
	long convert() {
		int sign = 1, i = 0;
		if (input_str[0] == '-') {
			sign = -1;
			i = 1;
		}
		int count[10] = { 0 };
		for (; i < input_str.length(); i++) {
			if (input_str[i] < '0' || input_str[i] > '9')
				throw std::invalid_argument("Input std::string contains non-numeric characters");
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
	std::string input_str;
};

// Single Responsibility Principle: This class is responsible for handling user input and output
class InputHandler {
public:
	InputHandler() {}
	void handle() {
		std::string str1, str2;
		std::cout << "The maximum valid input that can be converted is: " << LONG_MAX << std::endl;
		std::cout << "Enter the first number: ";
		std::cin >> str1;
		std::cout << "Enter the second number: ";
		std::cin >> str2;

		if (str1.length() > std::to_string(LONG_MAX).length() || str2.length() > std::to_string(LONG_MAX).length())
			throw std::invalid_argument("Input std::string exceeds maximum size that can be converted to a long");
		// Create instances of StringConverter to convert the strings to longs
		StringConverter converter1(str1);
		StringConverter converter2(str2);
		long num1 = converter1.convert(), num2 = converter2.convert();
		// Determine the smallest and largest numbers and output them to the console
		if (num1 < num2)
			std::swap(num1, num2);
		std::cout << "The smallest number is " << num2 << std::endl;
		std::cout << "The largest number is " << num1 << std::endl;
	}
};

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

/*
The maximum valid input that can be converted is: 2147483647
Enter the first number: 23223
Enter the second number: 667676
The smallest number is 33222
The largest number is 776666
*/
