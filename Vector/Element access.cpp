// C++ program to illustrate the
// element access in vector
#include<iostream>
#include<vector>

void main() {
	std::vector<int> g1{ 2,4,6,8,10 };

	std::cout << "\nReference operator [g] : g1[2] = " << g1[2];
	std::cout << "\nat : g1.at(4) = " << g1.at(4);
	std::cout << "\nfront() : g1.front() = " << g1.front();
	std::cout << "\nback() : g1.back() = " << g1.back();

	// pointer to the first element
	int* pos = g1.data();
	std::cout << "\nThe first element is " << *pos;
	std::cout << std::endl;

	system("pause");
}

/*
Reference operator [g] : g1[2] = 6
at : g1.at(4) = 10
front() : g1.front() = 2
back() : g1.back() = 10
The first element is 2
Press any key to continue . . .
*/

/*
at(g) – Returns a reference to the element at position ‘g’ in the vector
operator [g] – Returns a reference to the element at position ‘g’ in the vector
front() – Returns a reference to the first element in the vector
back() – Returns a reference to the last element in the vector
data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
*/
