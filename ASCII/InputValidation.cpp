#include <iostream>
#include <string>
using namespace std;

// Single Responsibility Principle: This class is responsible for validating user input
class InputValidator {
public:
	InputValidator(int num) : input_num(num) {}
	bool validate() {
		return input_num >= 1 && input_num <= 10;
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
		cout << "Enter a number between 0 and 10, both not included: ";
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
	// Create an instance of InputHandler to handle user input and output
	InputHandler handler;
	handler.handle();
	system("pause");
}
/*
Output:
Enter a number between 0 and 10, both not included: 0
Invalid input: 0
Enter a number between 0 and 10, both not included: 2
Valid input: 2
Enter a number between 0 and 10, both not included: 10
Invalid input size: 2
Enter a number between 0 and 10, both not included: J
Invalid input: J
*/
