#include <iostream>
#include <queue>
#include<string>

void main() {
	// Creating an empty queue of string
	std::queue<std::string> q;

	// Adding elements to the queue
	q.push("hello");
	q.push("world");
	q.push("!");

	// Displaying the queue
	std::cout << "Queue: ";
	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

// Output: Queue: hello world !
