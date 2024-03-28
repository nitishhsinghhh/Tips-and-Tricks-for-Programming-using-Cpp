// C++ code to demonstrate working of
// insert_after(), emplace_after()
// and erase_after()
#include <forward_list>
#include <iostream>

// Driver Code
int main()
{
	// Initializing forward list
	std::forward_list<int> flist = { 10, 20, 30 };

	// Declaring a forward list iterator
	std::forward_list<int>::iterator ptr;

	// Inserting value using insert_after()
	// starts insertion from second position
	ptr = flist.insert_after(flist.begin(), { 1, 2, 3 });

	// Displaying the forward list
	std::cout << "The forward list after insert_after operation "
		": ";
	for (int& c : flist)
		std::cout << c << " ";
	std::cout << std::endl;

	// Inserting value using emplace_after()
	// inserts 2 after ptr
	ptr = flist.emplace_after(ptr, 2);

	// Displaying the forward list
	std::cout << "The forward list after emplace_after "
		"operation : ";
	for (int& c : flist)
		std::cout << c << " ";
	std::cout << std::endl;

	// Deleting value using erase.after Deleted 2
	// after ptr
	ptr = flist.erase_after(ptr);
	std::cout << "The forward list after erase_after operation "
		": ";
	// Displaying the forward list
	for (int& c : flist)
		std::cout << c << " ";
	std::cout << std::endl;



	// Deleting value in a range
	// another variant of erase which uses start and end iterator
	// and deletes all the values in between them
	ptr = flist.erase_after(flist.begin(), flist.end());
	std::cout << "The forward list after erase_after (range) operation "
		": ";
	// Displaying the forward list
	for (int& c : flist)
		std::cout << c << " ";
	std::cout << std::endl;

	return 0;
}

/*
Output
The forward list after insert_after operation : 10 1 2 3 20 30
The forward list after emplace_after operation : 10 1 2 3 2 20 30
The forward list after erase_after operation : 10 1 2 3 2 30
The forward list after erase_after (range) operation : 10
*/
