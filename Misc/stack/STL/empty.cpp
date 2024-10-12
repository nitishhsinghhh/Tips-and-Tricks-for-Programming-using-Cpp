#include<iostream>
#include<stack>

void main() {
	std::stack<int> myStack;
	myStack.push(1);

	// Stack becomes 1
	if (myStack.empty())
		std::cout << "True";
	else
		std::cout << "False";
}
