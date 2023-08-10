#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode(): val(0), next(nullptr), prev(nullptr) {}
	ListNode(int x): val(x), next(nullptr), prev(nullptr) {}
	ListNode(int x, ListNode *next, ListNode *prev): val(x), next(next), prev(prev) {}
};

void main() {
	// Create nodes for the linked list
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);

	// Link the nodes together
	node1->next = node2;
	node2->prev = node1;

	node2->next = node3;
	node3->prev = node2;

	node3->next = node4;
	node4->prev = node3;

	node4->next = node5;
	node5->prev = node4;

	// Traverse the linked list forwards
	ListNode *current = node1;
	while (current != nullptr) {
		cout << current->val << " ";
		current = current->next;
	}

	cout << endl;

	// Traverse the linked list backwards
	current = node5;
	while (current != nullptr) {
		cout << current->val << " ";
		current = current->prev;
	}

	cout << endl;

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;

	system("pause");
}

/*
Output:
1 2 3 4 5
5 4 3 2 1
*/
