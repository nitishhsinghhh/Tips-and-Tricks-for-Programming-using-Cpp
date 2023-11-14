#include<iostream>

// This class is responsible for adding two characters together for input between 0 to 9
class CharAdder {
public:
	char char1, char2;
	CharAdder(char c1, char c2) : char1(c1), char2(c2) {}
	int add() {
		int num1 = char1 - '0', num2 = char2 - '0';
		return num1 + num2;
	}
};

int main() {
	char c1, c2;
	std::cout << "Enter first character between 0 to 9: ";
	std::cin >> c1;
	std::cout << "Enter second character between 0 to 9: ";
	std::cin >> c2;
	CharAdder adder(c1, c2);
	int sum = adder.add();
	std::cout << "The sum of " << adder.char1 << " and " << adder.char2 << " is " << sum << std::endl;
	system("pause");
}
