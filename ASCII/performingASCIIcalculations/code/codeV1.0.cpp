/**
Author: Nitish Singh
Date: February 12, 2024
Email ID: me.singhnitish@yandex.com

Problem Statement: 
The CharAdder class is responsible for adding two characters together. 
It takes two characters as input and adds their numeric values. 
The main function creates an instance of CharAdder, adds the characters, and outputs the sum.

Solution: 
The CharAdder class takes two characters as input and calculates their sum by converting them to integers. 
The main function demonstrates the use of the CharAdder class by adding two characters and displaying the result.

Additional Information:
- The CharAdder class uses integer conversion to add the characters, assuming that the input characters represent numeric values.
- The main function showcases the functionality of the CharAdder class by adding the characters '3' and '7' and displaying the result.

Note:
The line CharAdder(char c1, char c2) : char1(c1), char2(c2) {} is a constructor for the CharAdder class. Let's break down this line:
CharAdder(char c1, char c2): This part defines the constructor for the CharAdder class. It takes two parameters of type char, denoted as c1 and c2. 
This means that when an object of the CharAdder class is created, it can be initialized with two characters.

: char1(c1), char2(c2) {}: This part is the initializer list. It is used to initialize the member variables of the CharAdder class. Here, it initializes 
char1 with the value of c1 and char2 with the value of c2. This allows the member variables char1 and char2 to be set to the values passed to the constructor 
when an object of CharAdder is created.

In summary, this line defines a constructor for the CharAdder class that takes two char parameters and initializes the member variables char1 and char2 with 
the values of the parameters passed to the constructor. This allows the CharAdder objects to be initialized with specific character values when they are created.
**/

#include <iostream>

// This class is responsible for adding two characters together
class CharAdder {
public:
	CharAdder(char c1, char c2) : char1(c1), char2(c2) {}		// parameterized constructor
	int add() {
		int num1 = char1 - '0';
		int num2 = char2 - '0';
		return num1 + num2;
	}
private:
	char char1, char2;
};

void main() {
	char c1 = '3', c2 = '7';
	CharAdder adder(c1, c2);
	int sum = adder.add();
	std::cout << "The sum of " << c1 << " and " << c2 << " is " << sum << std::endl;
	system("pause");
}

/*
The sum of 3 and 7 is 10
Press any key to continue . . .
*/ 
