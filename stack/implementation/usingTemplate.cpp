#include <iostream>
#include <vector>
#include<string>

template<typename T>
class Stack {
private:
	std::vector<T> elements;
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

	std::cout << "Top element: " << MyStack.top() << std::endl;
	MyStack.pop();
	std::cout << "Top element after pop: " << MyStack.top() << std::endl;
	std::cout << "Stack size: " << MyStack.size() << std::endl;

	// String Stack
	Stack<std::string> MyStringStack;
	MyStringStack.push("10.00");
	MyStringStack.push("20.00");
	MyStringStack.push("30.00");

	std::cout << "Top element string: " << MyStringStack.top() << std::endl;
	MyStringStack.pop();
	std::cout << "Top element string after pop: " << MyStringStack.top() << std::endl;
	std::cout << "Stack size: " << MyStack.size() << std::endl;

	// double stack
	Stack<double> MyDoubleStack;
	MyDoubleStack.push(10.05);
	MyDoubleStack.push(20.08);
	MyDoubleStack.push(30.09);

	std::cout << "Top element: " << MyDoubleStack.top() << std::endl;
	MyDoubleStack.pop();
	std::cout << "Top element after pop: " << MyDoubleStack.top() << std::endl;
	std::cout << "Stack size: " << MyDoubleStack.size() << std::endl;

	system("pause");

}

/*
Top element: 30
Top element after pop: 20
Stack size: 2
Top element string: 30.00
Top element string after pop: 20.00
Stack size: 2
Top element: 30.09
Top element after pop: 20.08
Stack size: 2
Press any key to continue . . .
*/
