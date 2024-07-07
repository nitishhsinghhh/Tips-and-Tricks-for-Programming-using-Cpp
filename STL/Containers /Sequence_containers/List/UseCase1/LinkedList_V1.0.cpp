#include <iostream>

// Definition of ListNode structure
struct ListNode {
	int val;
	ListNode *next;
	ListNode *prev;

	// Default constructor
	ListNode() : val(0), next(nullptr), prev(nullptr) {}

	// Constructor with a value
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}

	// Constructor with value, next pointer, and prev pointer
	ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}

	// Destructor
    	~ListNode() {
		// Delete the next node in the list
		delete next; // This will recursively delete the entire list
	}
};

int main() {
	// Create nodes for the linked list
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);

	// Linking nodes
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	node3->next = node4;
	node4->prev = node3;
	node4->next = node5;
	node5->prev = node4;

	// Traversing the list forward
	ListNode *current = node1;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;

	// Traversing the list backward
	current = node5;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->prev;
	}
	std::cout << std::endl;

	// Cleaning up allocated memory
    	delete node1; // This will trigger the destructor and delete the entire list

	system("pause");

	return 0;
}

/*
Output:
1 2 3 4 5
5 4 3 2 1
*/
