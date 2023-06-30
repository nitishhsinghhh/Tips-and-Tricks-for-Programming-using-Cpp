#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
	vector<int> elements;
public:
	void push(int element) {
		elements.push_back(element);
	}

	bool isEmpty() {
		return elements.empty();
	}

	void pop() {
		if(!isEmpty())
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

	cout << "Top element: " << oStack.top() << endl;
	oStack.pop();
	cout << "Top element after pop: " << oStack.top() << endl;
	cout << "Stack size: " << oStack.size() << endl;
}
