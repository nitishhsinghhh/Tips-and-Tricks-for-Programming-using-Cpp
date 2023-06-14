#include <forward_list> // for using forward list
#include <iostream>
using namespace std;

int main() {
	// creating forward list
	forward_list<int> flist{ 1, 2, 3, 4, 5 };

	//Printing forward list
	cout<<"Forward list: ";
	for(auto i: flist){
	cout<<i<<" ";
	}
	cout<<endl;

	flist.clear();
	// Forward List becomes empty

	// Printing the Forward list
	cout<<"Forward list after using clear function: ";
	for (auto it = flist.begin(); it != flist.end(); ++it)
		cout << ' ' << *it;
	cout<<endl;

	return 0;
}

/*
Output
Forward list: 1 2 3 4 5 
Forward list after using clear function: 
*/
