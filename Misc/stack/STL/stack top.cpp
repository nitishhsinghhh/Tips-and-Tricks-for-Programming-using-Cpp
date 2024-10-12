#include <iostream>
#include<stack>

void main() {
	std::stack<int> myStack;
	myStack.push(5);
	myStack.push(1);
	myStack.push(2);

	// Stack Top
	std::cout << myStack.top();
}
