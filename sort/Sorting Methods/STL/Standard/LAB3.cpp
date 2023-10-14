// C++ program to demonstrate default behaviour of
// sort() in STL.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> vect { 0, 1, 5, 8, 9, 6, 7, 3, 4, 2 };
	sort(vect.begin() + 2, vect.end());
	cout << "\nVector after sorting using "
		"default sort is: ";
	for (int i = 0; i < vect.size(); ++i)
		cout << vect[i] << " ";

	return 0;
}

/*
Output:
Vector after sorting using default sort is:  0 1 2 3 4 5 6 7 8 9
*/
