// Program to find the entered year is leap or not

#include <iostream>
using namespace std;

void main() {
	int year;
	cout << "Enter a year: ";
	cin >> year;
	if (year % 4 ==0) 
		if (year % 100 == 0) 
			if (year % 400 == 0)
				cout << "Given " << year << " year is a leap." << endl;
			else
				cout << "Given " << year << " year isn't a leap." << endl;
		else
			cout << "Given " << year << " year is a leap year." << endl;
	else
		cout << "Given " << year << " year isn't a leap." << endl;

	system("pause");
}
