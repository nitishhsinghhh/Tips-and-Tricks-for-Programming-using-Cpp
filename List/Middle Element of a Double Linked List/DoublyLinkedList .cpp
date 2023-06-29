#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int value) {
		data = value;
		prev = nullptr;
		next = nullptr;
	}
};

class DoublyLinkedList {
private:
	Node* head;

public:
	DoublyLinkedList() {
		head = nullptr;
	}

	// Insert a node at the end of the list
	void insert(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr)
			head = newNode;
		else
		{
			Node* current = head;
			while (current->next != nullptr)
				current = current->next;

			current->next = newNode;
			newNode->prev = current;
		}
	}

	// delete the middle in the list
	void deleteMiddleelement() {
		if (head == nullptr) {
			cout << "List is empty " << endl;
			return;
		}

		Node* fast = head;
		Node* slow = head;

		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}

		if (slow->prev != nullptr)
			slow->prev->next = slow->next;
		else
			head = slow->next;

		if (slow->next != nullptr)
			slow->next->prev = slow->prev;

		delete slow;
	}

	// print the list
	void printList() {
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

};

void main() {
	DoublyLinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);

	cout << "Original list: ";
	list.printList();

	list.deleteMiddleelement();

	cout << "List after deleting middle element: ";
	list.printList();
}

/*
Output:
Original list: 1 2 3 4 5
List after deleting middle element: 1 2 4 5
*/
