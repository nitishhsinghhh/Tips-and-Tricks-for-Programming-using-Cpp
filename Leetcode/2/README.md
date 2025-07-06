# [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=5kiae7i1)

## Topics
- Linked List
- Math
- Recursion

This C++ function adds two numbers represented by two singly linked lists. Each node contains a single digit, and the digits are stored in reverse order (i.e., the 1's digit is at the head of the list).

```cpp
#include <iostream>
#include <vector>
#include <cassert>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy.next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& digits) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (int digit : digits) {
        current->next = new ListNode(digit);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to compare two linked lists
bool areEqual(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;

    // Test Case 1
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    ListNode* expected1 = createList({7, 0, 8});
    assert(areEqual(sol.addTwoNumbers(l1, l2), expected1));
    std::cout << "Test Case 1 Passed: ";
    printList(expected1);

    // Test Case 2
    l1 = createList({0});
    l2 = createList({0});
    ListNode* expected2 = createList({0});
    assert(areEqual(sol.addTwoNumbers(l1, l2), expected2));
    std::cout << "Test Case 2 Passed: ";
    printList(expected2);

    // Test Case 3
    l1 = createList({9, 9, 9, 9, 9, 9, 9});
    l2 = createList({9, 9, 9, 9});
    ListNode* expected3 = createList({8, 9, 9, 9, 0, 0, 0, 1});
    assert(areEqual(sol.addTwoNumbers(l1, l2), expected3));
    std::cout << "Test Case 3 Passed: ";
    printList(expected3);

    std::cout << "All test cases passed successfully!" << std::endl;
    return 0;
}

```
