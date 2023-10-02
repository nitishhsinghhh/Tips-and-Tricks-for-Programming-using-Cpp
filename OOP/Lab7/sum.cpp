#include<iostream>
#include<math.h>
using namespace std;

long long int sum(long long int n) {
	if (n == 0)
		return 1;
	else
		return n + sum( n - 1);
}

int main() {
	cout << "\t\t\t***Program to calculate the sum of natural numbers using recursion***" << endl;
	int num;
	cout << "Please enter the interval: ";
	cin >> num;
	cout << "The sum is : " << sum(num);
	cout << endl;
	system("pause");
	return 0;
}
