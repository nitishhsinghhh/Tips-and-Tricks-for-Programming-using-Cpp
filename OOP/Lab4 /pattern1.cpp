// Control Structure: Nested Loop

#include <iostream>
using namespace std;

class Solution {
public:
	void CreatePattern(int num) {
		for (int i = 0; i <= num; i++) {
			for (int j = num; j >= i; j--)
				if (i >= j)
					cout << "*";
				else
					cout << " ";
			cout << endl;
		}
	}
};

void main() {
	Solution oSolution;
	oSolution.CreatePattern(6);
	cout << endl;
	oSolution.CreatePattern(7);
	cout << endl;
	oSolution.CreatePattern(8);
	cout << endl;
	oSolution.CreatePattern(9);
	cout << endl;
	oSolution.CreatePattern(10);
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
