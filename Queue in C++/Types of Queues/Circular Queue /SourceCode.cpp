#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class CircularQueue {
private:
	int front, rear, size;
	int arr[MAX_SIZE];

public:
	CircularQueue() {
		front = -1;
		rear = -1;
		size = 0;
	}

	bool is_empty() {
		return (size == 0);
	}

	bool is_full() {
		return (size == MAX_SIZE);
	}

	void enqueue(int val) {
		if (is_full()) {
			cout << "Error: Queue is full" << endl;
			return;
		}

		if (is_empty()) {
			front = 0;
			rear = 0;
		}
		else {
			rear = (rear + 1) % MAX_SIZE;
		}

		arr[rear] = val;
		size++;
	}

	void dequeue() {
		if (is_empty()) {
			cout << "Error: Queue is empty" << endl;
			return;
		}

		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			front = (front + 1) % MAX_SIZE;
		}

		size--;
	}

	int get_front() {
		if (is_empty()) {
			cout << "Error: Queue is empty" << endl;
			return -1;
		}

		return arr[front];
	}

	int get_rear() {
		if (is_empty()) {
			cout << "Error: Queue is empty" << endl;
			return -1;
		}

		return arr[rear];
	}

	void display() {
		if (is_empty()) {
			cout << "Queue is empty" << endl;
			return;
		}

		cout << "Circular Queue: ";
		for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
			cout << arr[i] << " ";
		}
		cout << arr[rear] << endl;
	}
};

void main() {
	CircularQueue cq;

	cq.enqueue(1);
	cq.enqueue(2);
	cq.enqueue(3);
	cq.enqueue(4);
	cq.enqueue(5);
	cq.display();

	cq.enqueue(6);
	cq.display();

	cq.dequeue();
	cq.dequeue();
	cq.display();

	cout << "Front of queue: " << cq.get_front() << endl;
	cout << "Rear of queue: " << cq.get_rear() << endl;
}

/*
Output: 
Circular Queue: 1 2 3 4 5
Error: Queue is full
Circular Queue: 1 2 3 4 5
Circular Queue: 3 4 5
Front of queue: 3
Rear of queue: 5
*/
