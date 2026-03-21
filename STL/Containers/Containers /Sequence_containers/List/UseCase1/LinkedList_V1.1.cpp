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
	ListNode *head = nullptr;
	ListNode *prev = nullptr;

	// Creating and linking the nodes in a loop
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

	// Traversing the linked list forwards
	ListNode *current = head;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->next;
	}

	std::cout << std::endl;

	// Traversing the linked list backwards
	current = prev;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->prev;
	}
	std::cout << std::endl;

	// Cleaning up allocated memory
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
