// Program to display airthmetic operators using switch case

#include <iostream>

void main() {
	char op;
	float num1, num2;
	std::cout << "Enter the first operand: ";
	std::cin >> num1;
	std::cout << "Enter operator either + or - or * or / : ";
	std::cin >> op;
	std::cout << "Enter second operand: ";
	std::cin >> num2;
	std::cout << std::endl;

	switch (op) {
	case '+':
		std::cout << "Result is " << num1 + num2 << std::endl;
		break;
	case '-':
		std::cout << "Result is " << num1 - num2 << std::endl;
		break;
	case '*':
		std::cout << "Result is " << num1 * num2 << std::endl;
		break;
	case '/':
		std::cout << "Result is " << num1 / num2 << std::endl;
		break;
	default:
		std::cout << "Error! Operator is not correct";
		break;
	}
	system("pause");
}
