#include <iostream>
#include <string>
using namespace std;

// Single Responsibility Principle: This class is responsible for validating user input
class InputValidator {
public:
	InputValidator(string s) : input_str(s) {}
	bool validate() {
		if (input_str.empty()) return false;
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
	string input_str;
};

// Single Responsibility Principle: This class is responsible for handling user input and output
class InputHandler {
public:
	InputHandler() {}
	void handle() {
		string input_str;
		cout << "Enter a number between 1 and 3999: ";
		getline(cin, input_str);

		// Create an instance of InputValidator to validate the input
		InputValidator validator(input_str);
		if (validator.validate())
			cout << "Valid input: " << validator.getNum() << endl;
		else
			cout << "Invalid input: " << input_str << endl;
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
Enter a number between 1 and 3999: 4000
Invalid input: 4000
Enter a number between 1 and 3999: 1234
Valid input: 1234
*/
