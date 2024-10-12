#include <iostream>
#include <queue>

class Stack {
private:
	std::queue<int> q1, q2;
	int topElement;
public:
	Stack() {}

	void push(int x) {
		q2.push(x);
		topElement = x;
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		swap(q1, q2);
	}

	int pop() {
		int val = q1.front();
		q1.pop();
		if (!q1.empty()) {
			topElement = q1.front();
		}
		return val;
	}

	int top() {
		return topElement;
	}

	bool empty() {
		return q1.empty();
	}

	int size() {
		return q1.size();
	}
};

void main() {
	Stack myStack;
	myStack.push(30);
	myStack.push(40);
	myStack.push(50);
	std::cout << "Top element: " << myStack.top() << std::endl;
	myStack.pop();
	std::cout << "Top element after pop: " << myStack.top() << std::endl;
	std::cout << "Stack size: " << myStack.size() << std::endl;
	system("pause");
}

/*
Top element: 50
Top element after pop: 40
Stack size: 2
Press any key to continue . . .
*/
