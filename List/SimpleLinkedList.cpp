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
