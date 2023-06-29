#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = nullptr;
	}
};

class SinglyLinkedList {
private:
	Node* head;
public:
	SinglyLinkedList() {
		head = nullptr;
	}

	// Insert a node at the end of the list
	void insert(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr)
			head = newNode;
		else {
			Node* current = head;
			while (current->next != nullptr)
				current = current->next;

			current->next = newNode;
		}
	}

	// delete the middle element in the list
	void deleteMiddleElement() {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}

		Node* fast = head;
		Node* slow = head;
		Node* prev = nullptr;

		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}

		if (prev != nullptr) {
			prev->next = slow->next;
		}
		else {
			head = head->next;
		}

		delete slow;
	}

	// print the list
	void printList() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

void main() {
	SinglyLinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);

	cout << "Original list: ";
	list.printList();

	list.deleteMiddleElement();

	cout << "List after deleting middle element: ";
	list.printList();

}

/*
Output:
Original list: 1 2 3 4 5
List after deleting middle element: 1 2 4 5

*/
