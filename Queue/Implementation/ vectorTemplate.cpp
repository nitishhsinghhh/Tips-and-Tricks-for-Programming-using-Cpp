#include<iostream>
#include<vector>

template<typename T>
class Queue {
private:
	std::vector<T> data;
public:
	bool isEmpty() {
		return data.empty();
	}

	void push(T element) {
		data.push_back(element);
	}

	void pop() {
		if (!isEmpty())
			data.erase(data.begin());
	}

	T front() {
		return data.front();
	}
};

int main() {
	Queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);

	std::cout << "Front: " << queue.front() << std::endl;

	queue.pop();
	return 0;
}

// Front: 1
