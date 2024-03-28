/**
*    @File: inserter.cpp
*    @Author: Nitish Singh
*    @Date: January 8, 2024
*    @Email: ms.singhnitish@yandex.com
*
*    @Description:
*    This program demonstrates the use of the std::advance and std::inserter functions to insert elements from one vector into another vector at a specific position.
**/
#include <iostream>
#include <vector>
#include <iterator>
int main() {
	std::vector<int> vec = { 1, 2, 3, 4, 5 }, newVec = { 10, 20, 30 };
	std::vector<int>::iterator itr = vec.begin();
	std::advance(itr, 3);
	copy(newVec.begin(), newVec.end(), inserter(vec, itr));
	std::cout << "The new vector after inserting elements is: ";
	for (int& x : vec) 
		std::cout << x << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}
/**
*	The new vector after inserting elements is: 1 2 3 10 20 30 4 5
*	Press any key to continue . . .
**/
