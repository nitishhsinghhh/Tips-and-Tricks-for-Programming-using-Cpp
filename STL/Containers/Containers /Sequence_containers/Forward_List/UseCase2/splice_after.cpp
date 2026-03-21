// C++ code to demonstrate working of
// splice_after()
#include <forward_list> // for splice_after()
#include <iostream>
// Driver Code
int main() {
	// Initializing forward list
	std::forward_list<int> flist1 = { 10, 20, 30 };

	// Initializing second list
	std::forward_list<int> flist2 = { 40, 50, 60 };

	// Shifting elements from first to second
	// forward list after 1st position
	flist2.splice_after(flist2.begin(), flist1);

	// Displaying the forward list
	std::cout << "The forward list after splice_after operation "
		": ";
	for (int& c : flist2)
		std::cout << c << " ";
	std::cout << std::endl;

	return 0;
}

/*
Output
The forward list after splice_after operation : 40 10 20 30 50 60
*/
