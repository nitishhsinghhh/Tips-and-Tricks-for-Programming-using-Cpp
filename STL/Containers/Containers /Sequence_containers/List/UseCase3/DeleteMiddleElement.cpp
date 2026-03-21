#include <iostream>

// Definition of ListNode structure
struct ListNode {
    int val;          // Value of the node
    ListNode *next;   // Pointer to the next node
    ListNode *prev;   // Pointer to the previous node

    // Default constructor
    ListNode() : val(0), next(nullptr), prev(nullptr) {}

    // Constructor with a value
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}

    // Constructor with value, next pointer, and prev pointer
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

// Definition of Solution class
class Solution {
private:
    ListNode* head;   // Pointer to the head of the list

public:
    // Default constructor
    Solution() {
        head = nullptr;
    }

    // Destructor to clean up memory
    ~Solution() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Insert a ListNode at the end of the list
    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Delete the middle element in the list
    void deleteMiddleElement() {
        if (head == nullptr) {
            std::cout << "List is empty " << std::endl;
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        // Use two pointers to find the middle element
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Remove the middle element
        if (slow->prev != nullptr) {
            slow->prev->next = slow->next;
        } else {
            head = slow->next;
        }

        if (slow->next != nullptr) {
            slow->next->prev = slow->prev;
        }

        delete slow;
    }

    // Print the list
    void printList() {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution solution;

    // Insert elements into the list
    solution.insert(1);
    solution.insert(2);
    solution.insert(3);
    solution.insert(4);
    solution.insert(5);

    // Print the list before deleting the middle element
    std::cout << "List before deleting middle element: ";
    solution.printList();

    // Delete the middle element
    solution.deleteMiddleElement();

    // Print the list after deleting the middle element
    std::cout << "List after deleting middle element: ";
    solution.printList();

    return 0;
}

/**
Output:
List before deleting middle element: 1 2 3 4 5
List after deleting middle element: 1 2 4 5
**/
