#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <climits>
using namespace std;

class StringConverter {
public:
	StringConverter(string str) : input_str(str) {}
	long convert() {
		int sign = 1, i = 0;
		if (input_str[0] == '-') {
			sign = -1;
			i = 1;
		}
		int count[10] = { 0 };
		for (; i < input_str.length(); i++) {
			if (input_str[i] < '0' || input_str[i] > '9')
				throw invalid_argument("Input string contains non-numeric characters");
			count[input_str[i] - '0']++;
		}
		long result = 0;
		for (int j = 9; j >= 0; j--) {
			for (int k = 0; k < count[j]; k++) {
				if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && j > LONG_MAX % 10))
					throw invalid_argument("Input string exceeds maximum value that can be represented by a long");
				result = result * 10 + j;
			}
		}
		return result * sign;
	}
private:
	string input_str;
};

// Single Responsibility Principle: This class is responsible for handling user input and output
class InputHandler {
public:
	InputHandler() {}
	void handle() {
		string str1, str2;
		cout << "The maximum valid input that can be converted is: " << LONG_MAX << endl;
		cout << "Enter the first number: ";
		cin >> str1;
		cout << "Enter the second number: ";
		cin >> str2;
		
		if (str1.length() > to_string(LONG_MAX).length() || str2.length() > to_string(LONG_MAX).length())
			throw invalid_argument("Input string exceeds maximum size that can be converted to a long");
		// Create instances of StringConverter to convert the strings to longs
		StringConverter converter1(str1);
		StringConverter converter2(str2);
		long num1 = converter1.convert(), num2 = converter2.convert();
		// Determine the smallest and largest numbers and output them to the console
		if (num1 < num2)
			swap(num1, num2);
		cout << "The smallest number is " << num2 << endl;
		cout << "The largest number is " << num1 << endl;
	}
};

int main() {
	InputHandler input_handler;
	try {
		input_handler.handle();
	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	return 0;
}
