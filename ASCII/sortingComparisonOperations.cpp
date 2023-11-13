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
	InputHandler handler;
	handler.handle();
	system("pause");
}

/*
Output:
The smallest number is 12356
The largest number is 56789
*/
