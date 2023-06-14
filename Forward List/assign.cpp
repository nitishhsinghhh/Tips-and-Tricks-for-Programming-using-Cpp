#include <forward_list>
#include <iostream>
using namespace std;

// Driver Code
int main() {
	// Declaring forward list
	forward_list<int> flist1;
	forward_list<int> flist2;
	forward_list<int> flist3;

	// Assigning values using assign()
	flist1.assign({ 1, 2, 3 });
	flist2.assign(5, 10);
	flist3.assign(flist1.begin(), flist1.end());

	// Displaying forward lists
	cout << "The elements of first forward list are : ";
	for (int& a : flist1)
		cout << a << " ";
	cout << endl;

	cout << "The elements of second forward list are : ";
	for (int& b : flist2)
		cout << b << " ";
	cout << endl;
	
	cout << "The elements of third forward list are : ";
	for (int& c : flist3)
		cout << c << " ";
	cout << endl;

	return 0;
}

/*
Output
The elements of first forward list are : 1 2 3 
The elements of second forward list are : 10 10 10 10 10 
The elements of third forward list are : 1 2 3 
*/
