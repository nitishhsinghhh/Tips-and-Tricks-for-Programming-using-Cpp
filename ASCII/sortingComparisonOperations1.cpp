#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Single Responsibility Principle: This class is responsible for sorting and converting a string to an integer
class StringConverter {
public:
	StringConverter(string str) : input_str(str) {}
	int convert() {
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
		int result = 0;
		for (int j = 9; j >= 0; j--) {
			for (int k = 0; k < count[j]; k++) {
				if (result > INT_MAX / 10 || (result == INT_MAX / 10 && j > INT_MAX % 10))
					throw invalid_argument("Input string exceeds maximum value that can be represented by an int");
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
		string str1 = "65321", str2 = "98765";

		// Create instances of StringConverter to convert the strings to integers
		StringConverter converter1(str1);
		StringConverter converter2(str2);
		int num1 = converter1.convert(), num2 = converter2.convert();

		// Determine the smallest and largest numbers and output them to the console
		if (num1 < num2)
			swap(num1, num2);
		cout << "The smallest number is " << num2 << endl, cout << "The largest number is " << num1 << endl;
	}
};

int main() {
	cout << "*** Note: The maximum size of the input string that can be converted to an int is limited by the maximum value that can be represented by an int. ***" << endl << endl;
	cout << "\tFor a signed 32-bit int, this is 2,147,483,647." << endl;
	cout << "\tFor a signed 64-bit int, this is 9,223,372,036,854,775,807." << endl << endl;
	cout << endl;
	InputHandler handler;
	handler.handle();
	system("pause");
}
