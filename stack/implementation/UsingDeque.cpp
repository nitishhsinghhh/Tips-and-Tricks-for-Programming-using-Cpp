#include <iostream>
#include <deque>

class DequeStack {
private:
	std::deque<int> stack;
public:
	void push(int data) {
		stack.push_back(data);
	}
	void pop() {
		if (!stack.empty()) {
			stack.pop_back();
		}
	}
	int peek() {
		if (!stack.empty()) {
			return stack.back();
		}
		return -1; // Or throw an exception
	}
	bool isEmpty() {
		return stack.empty();
	}
};

void main() {
	DequeStack stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	std::cout << "Peek: " << stack.peek() << std::endl;
	stack.pop();
	std::cout << "Peek after pop: " << stack.peek() << std::endl;
	std::cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
	system("pause");
}
/*
Top element: 50
Top element after pop: 40
Stack size: 2
Press any key to continue . . .
*/
