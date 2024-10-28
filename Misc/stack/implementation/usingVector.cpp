#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Stack {
private:
	vector<int> elements;
public:
	void push(int element) {
		elements.push_back(element);
	}
	
	bool isEmpty() const{
		return elements.empty();
	}
	
	void pop() {
		if (!isEmpty())
			elements.pop_back();
	}
	
	int top() const{
		if (!isEmpty())
			return elements.back();
		throw std::out_of_range("Stack is empty");
	}
	
	int size() const{
		return elements.size();
	}
};

int main() {
	Stack oStack;

	// Test case 1: Basic operations
	oStack.push(10);
	oStack.push(20);
	oStack.push(30);
	cout << "Top element: " << oStack.top() << endl;
	oStack.pop();
	cout << "Top element after pop: " << oStack.top() << endl;
	cout << "Stack size: " << oStack.size() << endl;

	// Test case 2: Pop all elements
	oStack.pop();
	oStack.pop();
	cout << "Stack size after popping all elements: " << oStack.size() << endl;

	// Test case 3: Handling empty stack
	try {
		oStack.pop();	// Should hanlde gracefully
		cout << "Top element after popping from empty stack: " << oStack.top() <<endl;
	} catch (const std::exception& e) {
		std::cerr <<e.what() << endl;
	}
	
	return 0;
}
/*
Stack is empty
Top element: 30
Top element after pop: 20
Stack size: 2
Stack size after popping all elements: 0
Top element after popping from empty stack:
*/
