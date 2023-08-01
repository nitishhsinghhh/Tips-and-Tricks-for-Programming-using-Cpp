// C++ Program to Calculate Area and Circumference of Circle

#include<iostream>

using namespace std;

void main() {
	cout << "\t\tC++ program to Calculate Area and Circumference of Circle. \n";
	float Radius, Area, Circumference;
	cout << "Please enter the Radius of Circle: ";
	cin >> Radius;

	if (Radius > 0) {
		Area = 3.14 * Radius * Radius;
		Circumference = 2 * 3.14 * Radius;
		cout << "Area of circle is " << Area << ";" << endl;
		cout << "Circumference of Circle is " << Circumference << ";" << endl;
	}
	else
		cout << "Negative numbers cannot be applied !!!" << endl;

	system("Pause");
}
