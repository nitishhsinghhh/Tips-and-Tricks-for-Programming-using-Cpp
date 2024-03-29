#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode() : val(0), next(nullptr), prev(nullptr) {}
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
	ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

int main() {
	ListNode *head = nullptr;
	ListNode *prev = nullptr;

	// Create and link the nodes in a loop
	for (int i = 1; i <= 5; i++) {
		ListNode *node = new ListNode(i, nullptr, prev);
		if (prev != nullptr) {
			prev->next = node;
		}
		else {
			head = node; // Set head to the first node
		}
		prev = node;
	}

	// Traverse the linked list forwards
	ListNode *current = head;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->next;
	}

	std::cout << std::endl;

	// Traverse the linked list backwards
	current = prev;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->prev;
	}

	std::cout << std::endl;

	// Clean up memory by deleting nodes
	current = head;
	while (current != nullptr) {
		ListNode *temp = current;
		current = current->next;
		delete temp;
	}

	return 0;
}

/*
Output:
1 2 3 4 5
5 4 3 2 1
*/
