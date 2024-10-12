#include<iostream>
#include<stack>

void main() {
	int sum = 0;
	std::stack<int> myStack;
	myStack.push(1);
	myStack.push(8);
	myStack.push(3);
	myStack.push(6);
	myStack.push(2);

	// Stack becomes 1, 8, 3, 6, 2

	while (myStack.size() > 0) {
		sum += myStack.top();
		myStack.pop();
	}
	std::cout << sum;
}
