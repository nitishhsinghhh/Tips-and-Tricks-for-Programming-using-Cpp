#include <iostream>
#include <queue>
#include <optional>

class Stack {
private:
	std::queue<int> q1, q2;
	std::optional<int> topElement;

public:
	Stack() = default;

	void push(int x) {
		q2.push(x);
		topElement = x;

		// Move all elements from q1 to q2
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// Swap queues to restore order
		q1 = std::move(q2);
	}

	std::optional<int> pop() {
		if (q1.empty()) return std::nullopt;

		int val = q1.front();
		q1.pop();

		// Update the top element if q1 is not empty
		topElement = q1.empty() ? std::nullopt : std::optional<int>{q1.front()};
		return val;
	}

	std::optional<int> top() const {
		return topElement;
	}

	bool empty() const {
		return q1.empty();
	}

	int size() const {
		return q1.size();
	}
};

int main() {
	Stack myStack;
	myStack.push(30);
	myStack.push(40);
	myStack.push(50);

	// Checking top element
	if (auto top = myStack.top(); top) {
		std::cout << "Top element: " << *top << std::endl;
	}

	// Popping top element and rechecking
	if (auto popped = myStack.pop(); popped) {
		if (auto newTop = myStack.top(); newTop) {
			std::cout << "Top element after pop: " << *newTop << std::endl;
		} else {
			std::cout << "Stack is empty after pop." << std::endl;
		}
	}

	std::cout << "Stack size: " << myStack.size() << std::endl;

	// Range-based demonstration to print remaining elements
	std::cout << "Remaining elements in stack: ";
	while (!myStack.empty()) {
		if (auto popped = myStack.pop(); popped) {
			std::cout << *popped << " ";
		}
	}
	std::cout << std::endl;

	return 0;
}

/*
Top element: 50
Top element after pop: 40
Stack size: 2
Remaining elements in stack: 40 30
*/
