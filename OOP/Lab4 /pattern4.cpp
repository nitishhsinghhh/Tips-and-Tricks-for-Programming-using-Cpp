// A program to add first seven terms of the following series using for loop:1 / !1 + 2 / !2 + 3 / !3 + ...

#include <iostream>
using namespace std;

class Solution {
public:
	void CreatePattern(int num) {
		float sum = 0, fact = 1;
		for (int i = 1; i <= num; i++) {
			fact = fact * i;
			sum += i / fact;
		}
		cout << "Sum is: " << sum << endl;
	}
};

void main() {
	Solution oSolution;
	oSolution.CreatePattern(5);
	cout << endl;
	oSolution.CreatePattern(6);
	cout << endl;
	oSolution.CreatePattern(7);
	cout << endl;
	oSolution.CreatePattern(8);
	cout << endl;
	oSolution.CreatePattern(9);
	system("pause");
}
