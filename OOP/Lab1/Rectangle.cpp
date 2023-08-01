// C++ program to Calculate Area of Rectangle

#include<iostream>
#include<math.h>

using namespace std;

void main() {
	cout << "\t\tC++program to Calculate Area of Rectangle. \n";
	float Length, Width, Area;
	cout << "Please enter the length of Rectangle: ";
	cin >> Length;
	cout << "Please enter the width of Rectangle: ";
	cin >> Width;

	if (Length > 0 && Width > 0) {
		Area = Length * Width;
		cout << "The Area of Rectangle is " << Area << ";" << endl;
	}
	else
		cout << "The sides of Rectangle cannot be negative numbers !" << endl;

	system("Pause");
}
