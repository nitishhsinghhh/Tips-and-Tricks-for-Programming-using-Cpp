#include <iostream>
#include <vector>
#include<string>
using namespace std;

template<typename T>
class Stack {
private:
	vector<T> elements;
public:
	void push(T element) {
		elements.push_back(element);
	}

	bool isEmpty() {
		return elements.empty();
	}

	void pop() {
		if (!isEmpty())
			elements.pop_back();
	}

	T top() {
		if (!isEmpty())
			return elements.back();
	}

	int size() {
		return elements.size();
	}
};

void main() {

	// integer Stack
	Stack<int> MyStack;
	MyStack.push(10);
	MyStack.push(20);
	MyStack.push(30);

	cout << "Top element: " << MyStack.top() << endl;
	MyStack.pop();
	cout << "Top element after pop: " << MyStack.top() << endl;
	cout << "Stack size: " << MyStack.size() << endl;

	// String Stack
	Stack<string> MyStringStack;
	MyStringStack.push("10.00");
	MyStringStack.push("20.00");
	MyStringStack.push("30.00");

	cout << "Top element string: " << MyStringStack.top() << endl;
	MyStringStack.pop();
	cout << "Top element string after pop: " << MyStringStack.top() << endl;
	cout << "Stack size: " << MyStack.size() << endl;

	// double stack
	Stack<double> MyDoubleStack;
	MyDoubleStack.push(10.05);
	MyDoubleStack.push(20.08);
	MyDoubleStack.push(30.09);

	cout << "Top element: " << MyDoubleStack.top() << endl;
	MyDoubleStack.pop();
	cout << "Top element after pop: " << MyDoubleStack.top() << endl;
	cout << "Stack size: " << MyDoubleStack.size() << endl;

}

/*
Output:
Top element: 30
Top element after pop: 20
Stack size: 2
Top element string: 30.00
Top element string after pop: 20.00
Stack size: 2
Top element: 30.09
Top element after pop: 20.08
Stack size: 2
*/
