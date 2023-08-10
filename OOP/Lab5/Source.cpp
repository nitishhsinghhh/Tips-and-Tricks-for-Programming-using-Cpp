// Program to calculate are of a circle using functions

#include<iostream>
using namespace std;

class Solution {
public:
	float area(float radius) {
		float area;
		area = (atan(1) * 4) * pow(radius, 2);
		return area;
	}
};

void main() {
	float radius;
	cout << "Please enter the radius of circle: ";
	cin >> radius;

	Solution oSolution;
	if (radius > 0)
		cout << oSolution.area(radius) << endl;
	else
		cout << "Invalid Radius!" << endl;

	system("pause");
}
