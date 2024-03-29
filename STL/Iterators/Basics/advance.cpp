/**
*	@File: advance.cpp
*	@Author: Nitish Singh
*	@Date: March 28, 2024
*	@Email: me.singhnitish@yandex.com
*	
*	@Description:
*	This program demonstrates the use of the advance function to move an iterator forward in a vector. It initializes a vector, 
*	advances the iterator by 3 positions, and then outputs the value at the new position.
**/
#include <iostream>
#include <vector>
int main() {
	std::vector<int> vec{ 1, 2, 3, 6, 5 };
	std::vector<int>::iterator itr = vec.begin();
	std::advance(itr, 3);
	std::cout << "The value of at position after advancing is: " << *itr << std::endl;
	system("pause");
	return 0;
}
/**
*	The value of at position after advancing is:: 6
*	Press any key to continue . . .
**/
