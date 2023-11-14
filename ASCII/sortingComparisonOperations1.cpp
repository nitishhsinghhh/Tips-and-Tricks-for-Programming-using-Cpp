#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Single Responsibility Principle: This class is responsible for sorting and converting a string to an integer
class StringConverter {
public:
	StringConverter(string str) : input_str(str) {}
	int convert() {
		sort(input_str.begin(), input_str.end());
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
	string input_str;
};

// Single Responsibility Principle: This class is responsible for handling user input and output
class InputHandler {
public:
	InputHandler() {}
	void handle() {
		string str1 = "65321", str2 = "9876543210"; // Example input strings
		if (str1.length() > to_string(INT_MAX).length() || str2.length() > to_string(INT_MAX).length())
			throw invalid_argument("Input string exceeds maximum size that can be converted to an int");

		// Create instances of StringConverter to convert the strings to integers
		StringConverter converter1(str1);
		StringConverter converter2(str2);
		int num1 = converter1.convert(), num2 = converter2.convert();
		// Determine the smallest and largest numbers and output them to the console
		if (num1 < num2)
			swap(num1, num2);
		cout << "The smallest number is " << num2 << endl;
		cout << "The largest number is " << num1 << endl;
	}
};

int main() {
	string str1 = "65321", str2 = "98765";
	// Create instances of StringConverter to convert the strings to integers
	StringConverter converter1(str1);
	StringConverter converter2(str2);
	int num1 = converter1.convert(), num2 = converter2.convert();
	cout << "*** Note: The maximum size of the input string that can be converted to an int is limited by the maximum value that can be represented by an int. ***" << endl << endl;
	cout << "\tFor a signed 32-bit int, this is 2,147,483,647." << endl;
	cout << "\tFor a signed 64-bit int, this is 9,223,372,036,854,775,807." << endl << endl;
	cout << endl;
	// Determine the smallest and largest numbers and output them to the console
	if (num1 < num2)
		swap(num1, num2);
	cout << "The smallest number is " << num2 << endl;
	cout << "The largest number is " << num1 << endl;
	system("pause");
}
