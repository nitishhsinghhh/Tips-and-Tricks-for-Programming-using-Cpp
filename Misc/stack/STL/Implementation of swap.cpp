#include<iostream>
#include<stack>

void main() {

	// Stack container declaration
	std::stack<int> myStack1;
	std::stack<int> myStack2;

	// Pushing elements into first stack
	myStack1.push(1);
	myStack1.push(2);
	myStack1.push(3);
	myStack1.push(4);

	// Pushing elements into 2nd stack
	myStack2.push(3);
	myStack2.push(5);
	myStack2.push(7);
	myStack2.push(9);

	// Using swap() functions to swap elements of stack
	std::swap(myStack1, myStack2);

	// Printing the first stack 
	std::cout << "Mystack1 = ";
	while (!myStack1.empty()) {
		std::cout << myStack1.top() << " ";
		myStack1.pop();
	}

	std::cout << std::endl;

	// Printing the second stack 
	std::cout << "Mystack2 = ";
	while (!myStack2.empty()) {
		std::cout << myStack2.top() << " ";
		myStack2.pop();
	}
}
