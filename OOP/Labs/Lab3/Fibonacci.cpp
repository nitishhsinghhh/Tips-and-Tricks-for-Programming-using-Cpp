// Program to print Fibonacci series upto 100;

#include <iostream>

using namespace std;

void main() {
	int a = 0, b = 1, sum = 0;
	cout << a << endl;
	cout << b << endl;
	while (b < 100) {
		sum = a + b;
		a = b;
		b = sum;
		if (b > 100)
			break;
		cout << sum << endl;
	}
	system("pause");
}
