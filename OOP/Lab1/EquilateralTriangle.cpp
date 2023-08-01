// C++ program to Calculate Area of Equilateral Triangle

#include<iostream>
#include<math.h>

using namespace std;

void main() {
	cout << "\t\tC++program to Calculate Area of Equilateral Triangle. \n";
	float Side, Area, Circumference;
	cout << "Please enter the value for the side of Triangle: ";
	cin >> Side;

	if (Side > 0) {
		Area = 0.25 * sqrt(3) * Side * Side;
		cout << "The Area of this triangle is " << Area << ";" << endl;
	}
	else
		cout << "The sides of Triangle cannot be negative numbers !" << endl;

	system("Pause");
}
