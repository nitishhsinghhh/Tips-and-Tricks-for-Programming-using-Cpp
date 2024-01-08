/**
*	@File: main.cpp
*	@Author: Nitish
*	@Date: January 8, 2024
*	@Email: me.singhnitish@yandex.com
*	
*	@Description:
*	This program demonstrates the use of the advance function to move an iterator forward in a vector. It initializes a vector, 
*	advances the iterator by 3 positions, and then outputs the value at the new position.
**/
#include <iostream>
#include <vector>
int main() {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::vector<int>::iterator itr = vec.begin();
	advance(itr, 3);
	std::cout << "The position of the iterator after advancing is: " << *itr << std::endl;
	system("pause");
	return 0;
}
/**
*	The position of the iterator after advancing is: 4
*	Press any key to continue . . .
**/
