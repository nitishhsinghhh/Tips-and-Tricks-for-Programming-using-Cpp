### A C++ Program to Check Whether a Number is a Positive or Negative Number

```cpp
#include <iostream>

void main() {
	int number = -100;
	if (number < 0)
		std::cout << "The given number is negative." << std::endl;
	else
		std::cout << "The given number is positive." << std::endl;

	system("pause");
}
```

- Let's improve on this by taking the input from the user
```cpp
#include <iostream>

void main() {
	int number;
	std::cout << "Please give the number to be tested." << std::endl;
	std::cin >> number;
	if (number < 0)
		std::cout << "The given number is negative." << std::endl;
	else
		std::cout << "The given number is positive." << std::endl;

	system("pause");
}
```

- Lets say we also want to test for cases when we have to check if it is odd or even also
```cpp
#include <iostream>
#include <string>

void main() {
	int number;
	std::cout << "Please give the number to be tested." << std::endl;
	std::cin >> number;
	std::string boolVal = "";
	(number % 2 == 0) ? boolVal = "even" : boolVal = "odd";

	if (number < 0)
		std::cout << "The given number is negative and is " << boolVal << " number." << std::endl;
	else
		std::cout << "The given number is positive and is " << boolVal << " number." << std::endl;

	system("pause");
}
```
- Let's further imrpove upon this
```cpp
#include <iostream>
#include <string>

void main() {
	int number;
	std::cout << "Please give the number to be tested." << std::endl;
	std::cin >> number;
	std::string res = "";
	std::string boolVal = "";	
	if (number < 0)
		res = res.append("The given number is negative and is ");
	else
		res = res.append("The given number is positive and is ");
	(number % 2 == 0) ? res.append("even.") : res.append("odd.");
	std::cout << res << std::endl;
	system("pause");
}
```

# Findings from the last program
1. The [append](https://en.cppreference.com/w/cpp/string/basic_string/append) function in C++ is a member function of the std::string class that is used to concatenate (append) a string or a part of a string to the end of another string. This function is commonly used to combine two strings together.
2. The ?: operator in C++ is known as the ternary conditional operator. It is a shorthand way of writing an if-else statement in a single line. The ternary operator takes three operands: a condition, a value to be returned if the condition is true, and a value to be returned if the condition is false.

- To return a value using the ternary conditional operator in C++, we  can simply use the operator within the return statement. Here is an example demonstrating how to return a value using the ternary operator:
```cpp
#include <iostream>
#include <string>

// Function to determine if a number is even or odd using the ternary operator
std::string checkEvenOdd(int num) {
	return (num % 2 == 0) ? "Even" : "Odd";
}

int main() {
	int number = 7;

	// Call the function and return the result using the ternary operator
	std::string result = checkEvenOdd(number);

	std::cout << "The number " << number << " is " << result << "." << std::endl;

	return 0;
}
```

- Let's imrpove upon it by taking input from the user
```cpp
#include <iostream>
#include <string>

// Function to determine if a number is even or odd using the ternary operator
std::string checkEvenOdd(int num) {
	return (num % 2 == 0) ? "Even" : "Odd";
}

int main() {
	int number;

	std::cout << "Please enter the number." << std::endl;
	std::cin >> number;

	// Call the function and return the result using the ternary operator
	std::string result = checkEvenOdd(number);

	std::cout << "The number " << number << " is " << result << "." << std::endl;

	return 0;
}
```
- Let's include OOP
```cpp
class Solution
{
public:
	Solution(int num) : _num(num) {}	// Constrctor

	// Function to determine if a number is even or odd using the ternary operator
	std::string checkEvenOdd() {
		return (_num % 2 == 0) ? "Even" : "Odd";
	}
private:
	int _num;
};

int main() {
	int number;

	std::cout << "Please enter the number." << std::endl;
	std::cin >> number;

	Solution oSolution(number);
	// Call the function and return the result using the ternary operator
	std::string result = oSolution.checkEvenOdd();
	std::cout << "The number " << number << " is " << result << "." << std::endl;

	return 0;
}
```
- Using Copy Constructor
```cpp
#include <iostream>
#include <string>

class Solution {
public:
	Solution(const int& num) : _num(num) {} // Constructor
	Solution(const Solution& other) : _num(other._num) {}

	// Function to determine if a number is even or odd using the ternary
	// operator
	std::string checkEvenOdd() { return (_num % 2 == 0) ? "Even" : "Odd"; }

private:
	int _num;
};

int main() {
	int number;

	std::cout << "Please enter the number." << std::endl;
	std::cin >> number;

	Solution oSolution(number);
	Solution oSolution1 = oSolution; // Using the copy constructor

	std::string result = oSolution1.checkEvenOdd();
	std::cout << "The number " << number << " is " << result << "."
		<< std::endl;

	result = oSolution.checkEvenOdd();
	std::cout << "The number " << number << " is " << result << "."
		<< std::endl;

	return 0;
}
```
- Positive, Negative and Even Odd fucntion
```cpp
#include <iostream>
#include <string>

class Solution {
public:
	Solution(const int& num) : _num(num) {} // Constructor
	Solution(const Solution& other) : _num(other._num) {}

	// Function to determine if a number is even or odd using the ternary operator
	std::string checkEvenOdd() { return (_num % 2 == 0) ? "Even" : "Odd"; }

	// Function to check if the number is positive, negative, or zero
	std::string checkPositiveNegativeZero() {
		if (_num > 0) 
			return "Positive";
		else if (_num < 0) 
			return "Negative";
		else 
			return "Zero";
	}

private:
	int _num;
};

int main() {
	int number;

	std::cout << "Please enter the number." << std::endl;
	std::cin >> number;

	Solution oSolution(number);
	Solution oSolution1 = oSolution; // Using the copy constructor

	std::string var;
	std::string result = oSolution1.checkEvenOdd();
	std::cout << "The number " << number << " is " << result << "." << std::endl;

	result = oSolution.checkEvenOdd();
	std::cout << "The number " << number << " is " << result << "." << std::endl;

	std::string posNegZero = oSolution.checkPositiveNegativeZero();
	std::cout << "The number " << number << " is " << posNegZero << "." << std::endl;

	return 0;
}
```
