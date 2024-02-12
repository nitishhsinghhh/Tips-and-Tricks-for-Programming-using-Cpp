/**
Author: Nitish Singh
Date: February 12, 2024
Email ID: me.singhnitish@yandex.com

Problem Statement: 
This program demonstrates a simple application that sorts and converts two strings to integers and outputs the smallest and largest numbers to the console.

Solution: 
The program consists of two classes:
1. StringConverter: Responsible for sorting and converting a string to an integer.
2. InputHandler: Responsible for handling user input and output.

The main function provides information about the maximum size of the input string that can be converted to an int and uses instances of StringConverter to convert the strings to integers and determine the smallest and largest numbers for output.

Additional Information:
- The StringConverter class sorts the input string and converts it to an integer, handling negative numbers as well.
- The InputHandler class creates instances of StringConverter to convert strings and determines the smallest and largest numbers for output.
**/

#include <iostream>
#include <algorithm>
#include <string>

// This class is responsible for sorting and converting a string to an integer
class StringConverter {
public:
	StringConverter(std::string str) : input_str(str) {}
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
	std::string input_str;
};

// Single Responsibility Principle: This class is responsible for handling user input and output
class InputHandler {
public:
	InputHandler() {}
	void handle() {
		std::string str1 = "65321", str2 = "98765";
		// Create instances of StringConverter to convert the strings to integers
		StringConverter converter1(str1);
		StringConverter converter2(str2);
		int num1 = converter1.convert(), num2 = converter2.convert();
		// Determine the smallest and largest numbers and output them to the console
		if (num1 < num2)
			std::swap(num1, num2);
		std::cout << "The smallest number is " << num2 << std::endl, std::cout << "The largest number is " << num1 << std::endl;
	}
};

int main() {
	std::cout << "*** Note: The maximum size of the input string that can be converted to an int is limited by the maximum value that can be represented by an int. ***" << std::endl << std::endl;
	std::cout << "\tFor a signed 32-bit int, this is 2,147,483,647." << std::endl;
	std::cout << "\tFor a signed 64-bit int, this is 9,223,372,036,854,775,807." << std::endl << std::endl;
	std::cout << std::endl;
	InputHandler handler;
	handler.handle();
	system("pause");
}

/*
*** Note: The maximum size of the input string that can be converted to an int is limited by the maximum value that can be represented by an int. ***

        For a signed 32-bit int, this is 2,147,483,647.
        For a signed 64-bit int, this is 9,223,372,036,854,775,807.


The smallest number is 65321
The largest number is 98765
Press any key to continue . . .
*/
