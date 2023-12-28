#include <iostream>
#include <vector>

class Stack {
private:
	std::vector<int> elements;
public:
	void push(int element) {
		elements.push_back(element);
	}
	bool isEmpty() {
		return elements.empty();
	}
	void pop() {
		if (!isEmpty())
			elements.pop_back();
	}
	int top() {
		if (!isEmpty())
			return elements.back();
	}
	int size() {
		return elements.size();
	}
};

void main() {
	Stack oStack;
	oStack.push(10);
	oStack.push(20);
	oStack.push(30);
	std::cout << "Top element: " << oStack.top() << std::endl;
	oStack.pop();
	std::cout << "Top element after pop: " << oStack.top() << std::endl;
	std::cout << "Stack size: " << oStack.size() << std::endl;
	system("pause");
}
/*
Top element: 30
Top element after pop: 20
Stack size: 2
Press any key to continue . . .
*/
