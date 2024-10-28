// GCC 13.1 C++23

#include <iostream>
#include <memory>
#include <optional>
#include <coroutine>
#include <thread>
#include <ranges>

struct ListNode {
	int val;
	std::unique_ptr<ListNode> next;
	explicit ListNode(int x, std::unique_ptr<ListNode> next = nullptr)
		: val(x), next(std::move(next)) {}
};

class Stack {
private:
	std::unique_ptr<ListNode> topNode;
	int stackSize;

public:
	Stack() : topNode(nullptr), stackSize(0) {}

	~Stack() {
		// Automatically handled by unique_ptr
	}

	// Push with async simulation (just for fun)
	void push(int x) {
		std::jthread([this, x] {
			std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate delay
			auto newNode = std::make_unique<ListNode>(x, std::move(topNode));
			topNode = std::move(newNode);
			stackSize++;
		}).detach();
	}

	// Pop with optional return to avoid throwing
	std::optional<int> pop() {
		if (empty()) return std::nullopt;

		int val = topNode->val;
		topNode = std::move(topNode->next); // auto handles old node's deletion
		stackSize--;
		return val;
	}

	// Top with optional return to avoid throwing
	std::optional<int> top() const {
		return empty() ? std::nullopt : std::optional<int>(topNode->val);
	}

	bool empty() const {
		return topNode == nullptr;
	}

	int size() const {
		return stackSize;
	}
};

int main() {
	Stack myStack;
	myStack.push(30);
	myStack.push(40);
	myStack.push(50);

	// Delay to wait for async push operations
	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	if (auto topElem = myStack.top(); topElem) {
		std::cout << "Top element: " << *topElem << std::endl;
	}

	if (auto poppedElem = myStack.pop(); poppedElem) {
		std::cout << "Top element after pop: " << *myStack.top() << std::endl;
	} else {
		std::cout << "Stack is empty" << std::endl;
	}

	std::cout << "Stack size: " << myStack.size() << std::endl;

	// Printing stack elements
	std::cout << "Stack contents: ";
	for (int i : std::views::iota(0, myStack.size())) {
		std::cout << "Element " << i + 1 << " = " << (myStack.pop().value_or(-1)) << " ";
	}
	std::cout << std::endl;

	return 0;
}

/*
Top element: 40
Top element after pop: 50
Stack size: 2
Stack contents: Element 1 = 50 Element 2 = 30
*/
