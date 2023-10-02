#include<iostream>
using namespace std;

int fibonacci(int num) {
	if (num <= 1)
		return num;
	else
		return (fibonacci(num - 1) + fibonacci(num - 2));
}

int main() {
	cout << "\t\t\t***Program to calculate the sum of natural numbers using recursion***" << endl;
	cout << "Enter how many numbers would you like to output: ";
	int num;
	cin >> num;
	cout << "Fibonnaci Series: ";
	for (int i = 0; i < num; i++)
		cout << " " << fibonacci(i);
	cout << endl;
	system("pause");
	return 0;
}
