/*Problem Statement: Create a program that accepts user input of a single character representing a number between 1 and 10. 
		     The program should validate the input and output whether it is valid or invalid, along with the input number. 
 Solution: The InputValidator class is responsible for validating the user input by checking if the input character is between '1' and '10'.
	   The InputHandler class is responsible for handling the user input and output by prompting the user to enter a character and creating 
           an instance of InputValidator to validate the input. If the input is valid, the program outputs "Valid input: " followed by the 
	   input number. If the input is invalid, the program outputs "Invalid input: " followed by the input character.              
*/

#include <iostream>
#include <string>
using namespace std;

// Single Responsibility Principle: This class is responsible for validating user input
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
		string input_str;
		cout << "Enter a number between 1 and 9, both included: ";
		cin >> input_str;
		if (input_str.length() == 1) {
			// If the input string size is 1, create an instance of InputValidator to validate the input
			char input_char = input_str[0];
			InputValidator validator(input_char - '0');
			if (validator.validate())
				cout << "Valid input: " << validator.getNum() << endl;
			else
				cout << "Invalid input: " << input_char << endl;
		}
		else {
			// If the input string size is greater than 1, output an error message
			cout << "Invalid input size: " << input_str.length() << endl;
		}
	}
};

int main() {
	cout << "Enter test case 1: input is '10'" << endl;
	cout << "Expected output: Invalid input size: 2" << endl;
	InputHandler handler1;
	handler1.handle();
	cout << endl;

	cout << "Enter test case 2: input is '9'" << endl;
	cout << "Expected output: Valid input: 9" << endl;
	InputHandler handler2;
	handler2.handle();
	cout << endl;

	cout << "Enter test case 3: input is '1'" << endl;
	cout << "Expected output: Valid input: 1" << endl;
	InputHandler handler3;
	handler3.handle();
	cout << endl;

	cout << "Enter test case 4: input is '0'" << endl;
	cout << "Expected output: Invalid input: 0" << endl;
	InputHandler handler4;
	handler4.handle();
	cout << endl;

	cout << "Enter test case 5: input is 'J'" << endl;
	cout << "Expected output: Invalid input: J" << endl;
	InputHandler handler5;
	handler5.handle();
	cout << endl;

	system("pause");
}
/*
Output:
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
Enter a number between 1 and 9, both included: j
Invalid input: j
*/
