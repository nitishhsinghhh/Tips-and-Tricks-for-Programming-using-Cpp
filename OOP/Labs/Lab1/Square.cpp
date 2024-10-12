// C++ program to Calculate Area of Square

#include<iostream>
#include<math.h>

using namespace std;

void main() {
	cout << "\t\tC++ program to Calculate Area of Square. \n";
	float Length, Area;
	cout << "Please enter the length of Square: ";
	cin >> Length;

	if (Length > 0 ) {
		Area = Length * Length;
		cout << "The Area of Square is " << Area << ";" << endl;
	}
	else
		cout << "The sides of Square cannot be negative numbers !" << endl;

	system("Pause");
}
