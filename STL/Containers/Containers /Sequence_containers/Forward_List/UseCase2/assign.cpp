#include <forward_list>
#include <iostream>

// Driver Code
int main() {
	// Declaring forward list
	std::forward_list<int> flist1;
	std::forward_list<int> flist2;
	std::forward_list<int> flist3;

	// Assigning values using assign()
	flist1.assign({ 1, 2, 3 });
	flist2.assign(5, 10);
	flist3.assign(flist1.begin(), flist1.end());

	// Displaying forward lists
	std::cout << "The elements of first forward list are : ";
	for (int& a : flist1)
		std::cout << a << " ";
	std::cout << std::endl;

	std::cout << "The elements of second forward list are : ";
	for (int& b : flist2)
		std::cout << b << " ";
	std::cout << std::endl;

	std::cout << "The elements of third forward list are : ";
	for (int& c : flist3)
		std::cout << c << " ";
	std::cout << std::endl;

	return 0;
}

/*
Output
The elements of first forward list are : 1 2 3
The elements of second forward list are : 10 10 10 10 10
The elements of third forward list are : 1 2 3
*/
