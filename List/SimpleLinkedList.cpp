#include <iostream>

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;

    // Adding elements to the linked list
    Node* node1 = new Node();
    node1->data = 1;
    node1->next = nullptr;
    head = node1;

    Node* node2 = new Node();
    node2->data = 2;
    node2->next = nullptr;
    node1->next = node2;

    Node* node3 = new Node();
    node3->data = 3;
    node3->next = nullptr;
    node2->next = node3;

    // Accessing linked list elements
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
// 1 2 3


// Program to construct and Access the elements of a Linked List

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
};

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	// Accessing linked list elements
	ListNode *current = head;
	cout << "Output: ";
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->next;
	}
	cout << endl;

	system("pause");
}
/*
Output: 1 2 3 4 5
*/
