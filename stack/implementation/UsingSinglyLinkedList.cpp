#include <iostream>
using namespace std;

// Singly Linked List
struct ListNode {
	int val;
	ListNode *next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Stack {
private:
	ListNode *topNode;
	int stackSize;
public:
	Stack() : topNode(nullptr), stackSize(0) {}

	void push(int x) {
		ListNode *newNode = new ListNode(x);
		newNode->next = topNode;
		topNode = newNode;
		stackSize++;
	}

	int pop() {
		if (topNode == nullptr) 
			throw "Stack is empty";
		
		int val = topNode->val;
		ListNode *temp = topNode;
		topNode = topNode->next;
		delete temp;
		stackSize--;
		return val;
	}
	
	int top() {
		if (topNode == nullptr)
			throw "Stack is empty";
		return topNode->val;
	}

	bool empty() {
		return topNode == nullptr;
	}

	int size() {
		return stackSize;
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
