#include <iostream>
#include <deque>

int main() {
	// Creating a deque of integers
	std::deque<int> dq;

	dq.push_front(1);
	dq.push_back(2);
	dq.push_front(3);
	dq.push_back(4);

	std::cout << "Deque: ";
	for (auto it = dq.begin(); it != dq.end(); ++it) 
		std::cout << *it << " ";
	std::cout << std::endl;

	dq.pop_front();
	dq.pop_back();

	std::cout << "Updated Deque: ";
	for (auto it = dq.begin(); it != dq.end(); ++it) 
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}

/*
Output:
Deque: 3 1 2 4
Updated Deque: 1 2
*/
