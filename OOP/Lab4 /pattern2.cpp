// Control Structure: Nested Loop

#include <iostream>
using namespace std;

class Solution {
public:
	void CreatePattern(int num) {
		for (int i = 1; i <= num; i +=2) {
			for (int j = num - 2; j >= i; j -=2)
				cout << " ";
			for (int j = 1; j <= 1; j++)
				cout << "*";
			cout << endl;
		}
	}
};

void main() {
	Solution oSolution;
	oSolution.CreatePattern(6);
	cout << endl;
	oSolution.CreatePattern(8);
	cout << endl;
	oSolution.CreatePattern(10);
	cout << endl;
	oSolution.CreatePattern(12);
	cout << endl;
	oSolution.CreatePattern(14);
	system("pause");
}

/*
Output:

  *
 *
*

   *
  *
 *
*

    *
   *
  *
 *
*

     *
    *
   *
  *
 *
*

      *
     *
    *
   *
  *
 *
*

*/
