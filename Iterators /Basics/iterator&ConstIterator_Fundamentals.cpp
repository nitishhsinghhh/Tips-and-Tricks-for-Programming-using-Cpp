#include <iostream>
#include <vector>

int main() {

	// Case 1
	std::vector<int> input{ 1,2,3,4,5 };
	std::vector<int>::iterator it;
	for (it = input.begin(); it != input.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Case 2
	input.push_back(6);
	std::vector<int>::const_iterator itc;
	for(itc = input.cbegin(); itc != input.cend(); ++itc)
		std::cout << *itc << " ";
	std::cout << std::endl;

	// Case 3
	input.push_back(7);
	std::vector<int>::reverse_iterator itc1;
	for (itc1 = input.rbegin(); itc1!= input.rend() ; ++itc1)
		std::cout << *itc1 << " ";
	std::cout << std::endl;

	// Case 4
	input.push_back(8);
	std::vector<int>::const_reverse_iterator cri;
	for(cri = input.crbegin(); cri != input.crend(); ++cri)
		std::cout << *cri << " ";
	std::cout << std::endl;

	system("pause");
}
/**
*  1 2 3 4 5
*  1 2 3 4 5 6
*  7 6 5 4 3 2 1
*  8 7 6 5 4 3 2 1
*  Press any key to continue . . .
**/
