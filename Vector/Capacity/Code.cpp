#include <iostream>
#include <vector>

void main() {
	std::vector<int> g1{ 2,4,6,8,10 };

	std::cout << "Size : " << g1.size();
	std::cout << "\nCapacity : " << g1.capacity();
	std::cout << "\nMax_Size : " << g1.max_size();

	// prints the vector size after resize()
	std::cout << "\nSize : " << g1.size();

	// checks if the vector is empty or not
	if (g1.empty() == false)
		std::cout << "\nVector is not empty";
	else
		std::cout << "\nVector is empty";

	// Shrinks the vector
	g1.shrink_to_fit();
	std::cout << "\nVector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	system("pause");
}
/*
Size : 5
Capacity : 5
Max_Size : 1073741823
Size : 4
Vector is not empty
Vector elements are: 2 4 6 8
Press any key to continue . . .
*/
