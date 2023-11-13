#include <iostream>
#include <string>
using namespace std;

// Single Responsibility Principle: This class is responsible for validating user input
class InputValidator {
public:
	InputValidator(char c) : input_char(c) {}
	bool validate() {
		int input_num = input_char - '0';
		return input_num >= 1 && input_num <= 10;
	}
	int getNum() {
		return input_char - '0';
	}
private:
	char input_char;
};

// Single Responsibility Principle: This class is responsible for handling user input and output
class InputHandler {
public:
	InputHandler() {}
	void handle() {
		char input_char;
		cout << "Enter a number between 1 and 10: ";
		cin >> input_char;

		// Create an instance of InputValidator to validate the input
		InputValidator validator(input_char);
		if (validator.validate()) 
			cout << "Valid input: " << validator.getNum() << endl;
		else 
			cout << "Invalid input: " << input_char << endl;
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
Enter a number between 1 and 10: J
Invalid input: J
Enter a number between 1 and 10: 1
valid input: 1
*/
