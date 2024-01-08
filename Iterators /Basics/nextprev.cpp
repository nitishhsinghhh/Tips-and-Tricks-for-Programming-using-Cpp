#include "pch.h"

/**
*  @File: nextprev.cpp
*  @Author: Nitish
*  @Date: January 8, 2024
*  @Email: me.singhnitish@yandex.com
*  @Description:
*  This program demonstrates the use of the std::next and std::prev functions to create new iterators at specific positions relative to existing iterators in a vector.
**/
#include <iostream>
#include <vector>
#include <iterator>

int main() {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::vector<int>::iterator itr = vec.begin(), ftr = vec.end();
	auto newItr = std::next(itr, 3), newFtr = std::prev(ftr, 3);
	std::cout << "The position of the new iterator using next() is: " << *newItr << std::endl;
	std::cout << "The position of the new iterator using prev() is: " << *newFtr << std::endl;
	system("pause");
	return 0;
}

/**
*	The position of the new iterator using next() is: 4
*	The position of the new iterator using prev() is: 3
*	Press any key to continue . . .
**/
