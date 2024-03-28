#include <iostream>

// Definition for singly-linked list.
struct Node {
 int data;
 Node* next;
 Node() : data(0), next(nullptr) {}
 Node(int x) : data(x), next(nullptr) {}
 Node(int x, Node *next) : data(x), next(next) {}
};

void main() {
 Node* head = new Node(1, new Node(2, new Node(3)));

 while (head != nullptr) {
  std::cout << head->data << " ";
  head = head->next;
 }
 std::cout << std::endl;

 system("pause");
}
// 1 2 3
