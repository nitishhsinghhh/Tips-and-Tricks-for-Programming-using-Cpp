#include<iostream>
#include<stack>

void main() {
	int c = 0;
	// Empty stack
	std::stack<int> mystack;
	mystack.emplace(5);
	mystack.emplace(13);
	mystack.emplace(0);
	mystack.emplace(9);
	mystack.emplace(4);

	// Stack becomes  5, 13, 0, 9, 4

	// Printing the stack
	while (!mystack.empty()) {
		mystack.pop();
		c++;
	}
	std::cout << c;
}
