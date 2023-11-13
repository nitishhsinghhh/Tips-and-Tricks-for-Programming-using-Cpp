#include <iostream>
using namespace std;

// Single Responsibility Principle: This class is responsible for adding two characters together
class CharAdder {
public:
	char char1, char2;

	CharAdder(char c1, char c2) : char1(c1), char2(c2) {}
	int add() {
		int num1 = char1 - '0';
		int num2 = char2 - '0';
		return num1 + num2;
	}
};

int main() {
	CharAdder adder('3', '7');
	int sum = adder.add();
	// Single Responsibility Principle: This line is responsible for outputting the result to the console
	cout << "The sum of " << adder.char1 << " and " << adder.char2 << " is " << sum << endl;
	system("pause");
	return 0;
}

// Output: The sum of 3 and 7 is 10
