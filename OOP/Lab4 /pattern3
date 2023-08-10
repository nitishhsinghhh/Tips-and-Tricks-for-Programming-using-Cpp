// Control Structure: Nested Loop

#include <iostream>
using namespace std;

class Solution {
public:
	void CreatePattern(int num) {
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= i; j++)
				cout << "*";
			cout << endl;
		}

		for (int i = 1; i <= num; i++) {
			for (int j = num; j >= i; j--)
				cout << "*";
			cout << endl;
		}
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

/*
Output:

*
**
***
****
*****
*****
****
***
**
*

*
**
***
****
*****
******
******
*****
****
***
**
*

*
**
***
****
*****
******
*******
*******
******
*****
****
***
**
*

*
**
***
****
*****
******
*******
********
********
*******
******
*****
****
***
**
*

*
**
***
****
*****
******
*******
********
*********
*********
********
*******
******
*****
****
***
**
*

*/
