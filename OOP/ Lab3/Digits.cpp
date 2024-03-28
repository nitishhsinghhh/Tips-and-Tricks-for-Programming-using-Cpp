// Program to input a number and then calculate sum of its digits.

#include <iostream>
using namespace std;

void main() {
	int a, sum = 0;
	cout << "Please enter the number: ";
	cin >> a;
	while (a != 0) {
		sum += a % 10;
		a /= 10;
	}
	cout << "The sum of digits of given number is " << sum << ";" << endl;

	system("pause");
}
