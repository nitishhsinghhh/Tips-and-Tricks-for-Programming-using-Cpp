/**
Author: Nitish Singh
Date: February 12, 2024
Email ID: me.singhnitish@yandex.com

Problem Statement:
This program demonstrates a simple application that sorts and converts two strings to integers, and then determines the smallest and largest numbers to output to the console.

Solution:
The program consists of two classes:
1. StringConverter: Responsible for sorting and converting a string to an integer.
2. InputHandler: Responsible for handling user input and output.

The main function drives the program by using instances of StringConverter to convert strings to integers and then determine the smallest and largest numbers to be output.

Additional Information:
- The StringConverter class sorts the input string and converts it to an integer, handling negative numbers as well.
- The InputHandler class creates instances of StringConverter to convert strings and determines the smallest and largest numbers for output.

Note: 
- The line sort(input_str.begin(), input_str.end()); is using the std::sort algorithm to sort the characters in the input_str string in 
  ascending order. Here's a breakdown of this line:
  
  input_str: This is the input string to be sorted. It contains the characters that need to be arranged in ascending order.
  input_str.begin(): This is a method of the string class that returns an iterator pointing to the beginning of the string.
  input_str.end(): This is a method of the string class that returns an iterator pointing to the end of the string.
  std::sort: This is the standard library algorithm used to sort the elements in a range defined by the iterators.

- When std::sort is called with the iterators input_str.begin() and input_str.end(), it rearranges the characters within the specified 
  range (from the beginning to the end of the string) into ascending order according to their ASCII values. After this line is executed, 
  the input_str string will have its characters sorted in ascending order.
**/

#include <iostream>
#include <algorithm>
#include <string>

// This class is responsible for sorting and converting a string to an integer
class StringConverter {
public:
	StringConverter(std::string str) : input_str(str) {}
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
	std::string input_str;
};

// class is responsible for handling user input and output
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
		std::cout << "The smallest number is " << num2 << std::endl, 
		std::cout << "The largest number is " << num1 << std::endl;
	}
};

int main() {
	InputHandler handler;
	handler.handle();
	system("pause");
}
/*
The smallest number is 12356
The largest number is 56789
Press any key to continue . . .
*/
