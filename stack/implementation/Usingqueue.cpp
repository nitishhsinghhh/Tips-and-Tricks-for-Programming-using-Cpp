#include<iostream>
#include<queue>
using namespace std;

class Stack {
private:
	queue<int> q1, q2;
public:
	void push(int x) {
		q1.push(x);
	}

	int pop() {
		if (q1.empty()) {
			return -1;	// stack overflow
		}
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		int element = q1.front();
		q1.pop();
		swap(q1, q2);
		return element;
	}

	int top() {
		if (q1.empty()) {
			return -1; // Stack underflow
		}
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		int element = q1.front();
		q2.push(element);
		q1.pop();
		swap(q1, q2);
		return element;
	}

	bool empty() {
		return q1.empty();
	}

	int size() {
		return q1.size();
	}
};

int main() {
	Stack myStack;
	myStack.push(30);
	myStack.push(40);
	myStack.push(50);
	cout << "Top element: " << myStack.top() << endl;
	myStack.pop();
	cout << "Top element after pop: " << myStack.top() << endl;
	cout << "Stack size: " << myStack.size() << endl;
	return 0;
}

/*
Output:
Top element: 50
Top element after pop: 40
Stack size: 2
*/
