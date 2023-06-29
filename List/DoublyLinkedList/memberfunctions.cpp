#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int value) {
		data = value;
		next = nullptr;
		prev = nullptr;
	}
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int size;

public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	
	int front() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return -1;
		}
		return head->data;
	}

	int back() {
		if (tail == nullptr) {
			cout << "List is empty." << endl;
			return -1;
		}
		return tail->data;
	}

	void push_front(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}

	void push_back(int value) {
		Node* newNode = new Node(value);

		if (tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		size++;
	}

	void pop_front() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}

		Node* temp = head;
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
			head->prev = nullptr;
		}

		delete temp;
		size--;
	}

	void pop_back() {
		if (tail == nullptr) {
			cout << "List is empty." << endl;
			return;
		}

		Node* temp = tail;

		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete temp;
		size--;
	}

	void insert(int position, int value) {
		if (position < 0 || position > size) {
			cout << "Invalid position." << endl;
			return;
		}

		if (position == 0) {
			push_front(value);
			return;
		}

		if (position ==size) {
			push_back(value);
			return;
		}

		Node* newNode = new Node(value);
		Node* current = head;

		for (size_t i = 0; i < position; i++) 
			current = current->next;
		
		newNode->prev = current->prev;
		newNode->next = current;
		current->prev->next = newNode;
		current->prev = newNode;

		size++;
	}

	int getSize() {
		return size;
	}

	Node* begin() {
		return head;
	}

	Node* end() {
		return tail->next;
	}

};

void main() {
	DoublyLinkedList list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	cout << "Front: " << list.front() << endl;
	cout << "Back: " << list.back() << endl;

	list.pop_front();
	list.pop_back();

	cout << "Front: " << list.front() << endl;
	cout << "Back: " << list.back() << endl;

	list.insert(1, 10);

	for (Node* n = list.begin(); n != list.end(); n = n->next) {
		cout << n->data << " ";
	}
	cout << endl;

	cout << "Size: " << list.getSize() << endl;
}

/*
Output:
Front: 1
Back: 3
Front: 2
Back: 2
2 10
Size: 2

*/
