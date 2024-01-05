/*
Author: Nitish Singh
Date: January 3, 2024
Email ID: me.singhnitish@yandex.com

Problem Statement: 
Create a C++ program to evaluate a postfix expression using a stack-based calculator. The program should accept a postfix expression as input and calculate the result using a stack data structure. 
The input expression can contain numbers and the operators '+', '-', '*', and '/'. The program should handle invalid expressions and provide appropriate error messages.

Solution: 
The StackCalculator class contains a method named "calculate" that takes a postfix expression as input and evaluates it using a stack. The class uses a stack to push operands and perform operations 
based on the encountered operators. It also includes methods to check whether a token is a number or an operator, as well as to perform arithmetic operations. The main function prompts the user to 
enter a postfix expression, calls the calculate method of the StackCalculator, and displays the result or any error messages.

Additional Information:
- The program uses a stack-based approach to evaluate postfix expressions, which is a common technique in computer science and mathematics.
- Error handling is implemented to handle cases such as invalid expressions, division by zero, and unknown operators.
- The program demonstrates the use of stringstream for tokenizing the input expression and handling the input/output operations.
- The main function provides a sample output for a valid postfix expression to demonstrate the functionality of the program.
*/

#include <iostream>
#include <stack>
#include <sstream>

class StackCalculator {
public:
	double calculate(const std::string& expression) {
		std::istringstream iss(expression);
		std::string token;
		while (iss >> token) {
			if (isNumber(token)) {
				double number = std::stod(token);
				operandStack.push(number);
			}
			else if (isOperator(token)) {
				if (operandStack.size() < 2) {
					throw std::runtime_error("Invalid expression.");
				}
				else {
					double operand2 = operandStack.top();
					operandStack.pop();
					double operand1 = operandStack.top();
					operandStack.pop();
					double result = performOperation(operand1, operand2, token);
					operandStack.push(result);
				}
			}
			else {
				throw std::runtime_error("Invalid token in expression.");
			}
		}

		if (operandStack.size() != 1) {
			throw std::runtime_error("Invalid expression.");
		}

		return operandStack.top();
	}

private:
	std::stack<double> operandStack;

	bool isNumber(const std::string& str) {
		return((!str.empty()) && str.find_first_not_of("0123456789.") == std::string::npos);
	}

	bool isOperator(const std::string& str) {
		return str == "+" || str == "-" || str == "*" || str == "/";
	}

	double performOperation(double operand1, double operand2, const std::string& op) {
		if (op == "+") {
			return operand1 + operand2;
		}
		else if (op == "-") {
			return operand1 - operand2;
		}
		else if (op == "*") {
			return operand1 * operand2;
		}
		else if (op == "/") {
			if (operand2 == 0) {
				throw std::runtime_error("Division by zero.");
			}
			return operand1 / operand2;
		}
		throw std::runtime_error("Invalid operator.");
	}
};

int main() {
	StackCalculator calculator;
	std::string expression;
	std::cout << "Enter a postfix expression: ";
	std::getline(std::cin, expression);

	try {
		double result = calculator.calculate(expression);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}

/*
Output:
Enter a postfix expression: 2 3 +
Result: 5
*/
