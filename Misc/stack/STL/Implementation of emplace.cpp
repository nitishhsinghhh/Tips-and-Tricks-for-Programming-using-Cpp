#include<iostream>
#include<stack>

void main() {
	std::stack<int> mystack;
	mystack.emplace(1);
	mystack.emplace(2);
	mystack.emplace(3);
	mystack.emplace(4);
	mystack.emplace(5);
	mystack.emplace(6);

	// Stack becomes 1, 2, 3, 4, 5, 6

	// Printing the stack
	std::cout << "myStack = ";
	while (!mystack.empty()) {
		std::cout << mystack.top() << " ";
		mystack.pop();
	}
}
