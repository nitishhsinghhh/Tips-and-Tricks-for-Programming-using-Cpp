// C++ program to demonstrate default behaviour of
// sort() in STL.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> vect { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	sort(vect.begin(), vect.end(), greater<int>());

	cout << "\nVector after sorting using "
		"default sort is: ";
	for (int i = 0; i < vect.size(); ++i)
		cout << vect[i] << " ";

	return 0;
}

/*
Output:
Vector after sorting using default sort is: 9 8 7 6 5 4 3 2 1 0
*/
