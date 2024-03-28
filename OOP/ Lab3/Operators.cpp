// Program to display airthmetic operators using switch case

#include <iostream>

using namespace std;

void main() {
	char op;
	float num1, num2;
	cout << "Enter the first operand: ";
	cin >> num1;
	cout << "Enter operator either + or - or * or / : ";
	cin >> op;
	cout << "Enter second operand: ";
	cin >> num2;
	cout << endl;

	switch (op) {
	case '+':
		cout << "Result is " << num1 + num2 << endl;
		break;
	case '-':
		cout << "Result is " << num1 - num2 << endl;
		break;
	case '*':
		cout << "Result is " << num1 * num2 << endl;
		break;
	case '/':
		cout << "Result is " << num1 / num2 << endl;
		break;
	default:
		cout << "Error! Operator is not correct";
		break;
	}
	system("pause");
}
