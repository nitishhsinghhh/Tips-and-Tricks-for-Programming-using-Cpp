// C++ program to demonstrate default behaviour of
// sort() in STL.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> vect { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	/*Here we take two parameters, the beginning of the
	array and the length n upto which we want the array to
	be sorted*/
	sort(vect.begin(), vect.end());

	cout << "\nArray after sorting using "
		"default sort is: ";
	for (int i = 0; i < vect.size(); ++i)
		cout << vect[i] << " ";

	return 0;
}

/*
Output:
Vector after sorting using default sort is: 0 1 2 3 4 5 6 7 8 9
*/
