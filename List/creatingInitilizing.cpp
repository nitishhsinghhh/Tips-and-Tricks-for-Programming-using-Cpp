// Program to show elements of a list

#include<iostream>
#include<list>

void main() {
	std::list<int> myList { 1, 2, 3, 4, 5 };

	// Accessing the range based for loop
	std::cout << "Output: ";
	for (int element : myList)
		std::cout << element << " ";
	std::cout << std::endl;
	system("pause");
}
// output: 1 2 3 4 5.
