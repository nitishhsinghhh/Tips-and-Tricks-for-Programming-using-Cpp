#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;

template<typename T>
class Stack {
private:
	std::vector<T> elements;
public:
	void push(T element) {
		elements.push_back(element);
	}

	bool isEmpty() const {
		return elements.empty();
	}

	void pop() {
		if (!isEmpty())
			elements.pop_back();
	}

	T top() const {
		if (!isEmpty())
			return elements.back();
		else
			throw std::out_of_range("Stack<>::top: empty stack");
	}

	int size() const {
		return elements.size();
	}
};

int main() {
	// Integer Stack
	Stack<int> MyStack;
	MyStack.push(10);
	MyStack.push(20);
	MyStack.push(30);

	cout << "Top element: " << MyStack.top() << endl;
	MyStack.pop();
	cout << "Top element after pop: " << MyStack.top() << endl;
	cout << "Stack size: " << MyStack.size() << endl;

	// String Stack
	Stack<std::string> MyStringStack;
	MyStringStack.push("10.00");
	MyStringStack.push("20.00");
	MyStringStack.push("30.00");

	cout << "Top element string: " << MyStringStack.top() << endl;
	MyStringStack.pop();
	cout << "Top element string after pop: " << MyStringStack.top() << endl;
	cout << "Stack size: " << MyStringStack.size() << endl;

	// Double Stack
	Stack<double> MyDoubleStack;
	MyDoubleStack.push(10.05);
	MyDoubleStack.push(20.08);
	MyDoubleStack.push(30.09);

	cout << "Top element double: " << MyDoubleStack.top() << endl;
	MyDoubleStack.pop();
	cout << "Top element double after pop: " << MyDoubleStack.top() << endl;
	cout << "Stack size: " << MyDoubleStack.size() << endl;

	return 0;
}

/*
Top element: 30
Top element after pop: 20
Stack size: 2
Top element string: 30.00
Top element string after pop: 20.00
Stack size: 2
Top element double: 30.09
Top element double after pop: 20.08
Stack size: 2
*/
