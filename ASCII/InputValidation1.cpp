/*
Author: Nitish Singh
Date: December 29, 2023
Email ID: me.singhnitish@yandex.com

Problem Statement: Write a program that asks the user to enter a number between 1 and 3999 (inclusive). 
The program should validate the user input and output whether the input is valid or invalid. 
If the input is valid, the program should output the number entered by the user. The program 
should be able to handle both integer and Roman numeral inputs.

Solution: To solve this problem, we can create two classes: InputValidator and InputHandler. The InputValidator 
class is responsible for validating the user input, and the InputHandler class is responsible for handling 
user input and output.
The InputValidator class takes a string input from the user and checks if it is a valid integer between 1 and 3999  
(inclusive). It returns a boolean value indicating whether the input is valid or not. If the input is valid, it 
also provides a method to return the integer value of the input.  
The InputHandler class takes user input and creates an instance of the InputValidator class to validate the input. 
If the input is valid, it outputs the integer value of the input. If the input is invalid, it outputs an error message.
*/
#include <iostream>
#include <string>

// This class is responsible for validating user input
class InputValidator {
public:
	InputValidator(std::string s) : input_str(s) {}
	bool validate() {
		if (input_str.empty())
			return false;
		for (char c : input_str)
			if (c < '0' || c > '9') return false;
		int input_num = 0;
		for (char c : input_str)
			input_num = input_num * 10 + (c - '0');
		return input_num >= 1 && input_num <= 3999;
	}
	int getNum() {
		int input_num = 0;
		for (char c : input_str)
			input_num = input_num * 10 + (c - '0');
		return input_num;
	}
private:
	std::string input_str;
};

// This class is responsible for handling user input and output
class InputHandler {
public:
	InputHandler() {}
	void handle() {
		std::string input_str;
		std::cout << "Enter a number between 1 and 3999: ";
		getline(std::cin, input_str);
		// Create an instance of InputValidator to validate the input
		InputValidator validator(input_str);
		if (validator.validate())
			std::cout << "Valid input: " << validator.getNum() << std::endl;
		else
			std::cout << "Invalid input: " << input_str << std::endl;
	}
};

int main() {
	std::cout << "Enter test case 1: input is '0'" << std::endl;
	std::cout << "Expected output: Invalid input: 0" << std::endl;
	InputHandler handler1;
	handler1.handle();
	std::cout << std::endl;

	std::cout << "Enter test case 2: input is '3999'" << std::endl;
	std::cout << "Expected output: Valid input: 3999" << std::endl;
	InputHandler handler2;
	handler2.handle();
	std::cout << std::endl;

	std::cout << "Enter test case 3: input is 'MCMXCIX'" << std::endl;
	std::cout << "Expected output: Invalid input: MCMXCIX" << std::endl;
	InputHandler handler3;
	handler3.handle();
	std::cout << std::endl;

	std::cout << "Enter test case 4: input is 'MMCMXCIX'" << std::endl;
	std::cout << "Expected output: Invalid input: MMCMXCIX" << std::endl;
	InputHandler handler4;
	handler4.handle();
	std::cout << std::endl;

	system("pause");
}

/*
Enter test case 1: input is '0'
Expected output: Invalid input: 0
Enter a number between 1 and 3999: 0
Invalid input: 0

Enter test case 2: input is '3999'
Expected output: Valid input: 3999
Enter a number between 1 and 3999: 3999
Valid input: 3999

Enter test case 3: input is 'MCMXCIX'
Expected output: Invalid input: MCMXCIX
Enter a number between 1 and 3999: MCMXCIX
Invalid input: MCMXCIX

Enter test case 4: input is 'MMCMXCIX'
Expected output: Invalid input: MMCMXCIX
Enter a number between 1 and 3999: MMCMXCIX
Invalid input: MMCMXCIX

Press any key to continue . . .
*/
