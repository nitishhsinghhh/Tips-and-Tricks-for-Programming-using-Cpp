#include <forward_list> // for using forward list
#include <iostream>

int main() {
	// creating forward list
	std::forward_list<int> flist{ 1, 2, 3, 4, 5 };

	//Printing forward list
	std::cout << "Forward list: ";
	for (auto i : flist) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	flist.clear();
	// Forward List becomes empty

	// Printing the Forward list
	std::cout << "Forward list after using clear function: ";
	for (auto it = flist.begin(); it != flist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	return 0;
}

/*
Output
Forward list: 1 2 3 4 5
Forward list after using clear function:
*/
