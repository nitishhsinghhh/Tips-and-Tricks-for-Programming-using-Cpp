#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
	std::vector<T> elements;
public:
	void enqueue(const T& value) {
		elements.push_back(value);
	}

	bool isEmpty() const {
		return elements.empty();
	}

	void dequeue() {
		if (!isEmpty())
			elements.erase(elements.begin());
	}

	const T& front() const {
		if (!isEmpty())
			return elements.front();
		throw std::out_of_range("Queue is empty");
	}

	void printQueue() const {
		for (const T& element : elements) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
};

int main() {
	Queue<int> myQueue;
	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.enqueue(30);
	myQueue.printQueue(); // Output: 10 20 30

	myQueue.dequeue();
	myQueue.printQueue(); // Output: 20 30

	std::cout << "Front element: " << myQueue.front() << std::endl; // Output: Front element: 20

	return 0;
}

/*
Output:
10 20 30
20 30
Front element: 20
*/
