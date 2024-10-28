#include <iostream>
#include <deque>
#include <optional>

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

	[[nodiscard]] std::optional<int> peek() const {
		// Use optional to handle the empty case safely
		if (!stack.empty()) {
			return stack.back();
		}
		return std::nullopt;
	}

	[[nodiscard]] bool isEmpty() const {
		return stack.empty();
	}
};

int main() {
	DequeStack stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);

	// Peek at the top element
	if (auto top = stack.peek(); top.has_value()) {
		std::cout << "Peek: " << *top << std::endl;
	} else {
		std::cout << "Stack is empty" << std::endl;
	}

	stack.pop();

	// Peek after pop
	if (auto top = stack.peek(); top.has_value()) {
		std::cout << "Peek after pop: " << *top << std::endl;
	} else {
		std::cout << "Stack is empty" << std::endl;
	}

	// Check if stack is empty
	std::cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

	return 0;
}

/*
Peek: 30
Peek after pop: 20
Is empty? No
*/
