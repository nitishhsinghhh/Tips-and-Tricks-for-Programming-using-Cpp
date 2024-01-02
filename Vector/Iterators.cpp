// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

void main() {
	std::vector<int> g1{ 2,4,6,8,10 };

	std::cout << "Output of begin and end: ";
	for (auto i = g1.begin(); i != g1.end(); ++i)
		std::cout << *i << " ";
	std::cout << "\nOutput of cbegin and cend: ";
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		std::cout << *i << " ";
	std::cout << "\nOutput of rbegin and rend: ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		std::cout << *ir << " ";
	std::cout << "\nOutput of crbegin and crend : ";
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
		std::cout << *ir << " ";
	std::cout << std::endl;
	system("pause");
}
/*
Output of begin and end: 2 4 6 8 10
Output of cbegin and cend: 2 4 6 8 10
Output of rbegin and rend: 10 8 6 4 2
Output of crbegin and crend : 10 8 6 4 2
Press any key to continue . . .
*/

/*
Iterators
begin() / cbegin() (C++11)– Returns an iterator pointing to the first element in the vector
end() / cend() (C++11)– Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() / crbegin() (C++11)– Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() / crend() (C++11)– Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/
