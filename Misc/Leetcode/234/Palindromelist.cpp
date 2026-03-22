/**
 * @file main.cpp
 * @brief Solution for LeetCode 234 - Palindrome Linked List.
 *
 * This program builds linked lists, checks whether they are palindromes,
 * and prints the results for multiple test cases.
 */

#include <iostream>

/**
 * @struct ListNode
 * @brief Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

/**
 * @class Solution
 * @brief Provides helper methods for linked list creation and palindrome check.
 */
class Solution {
public:
    /**
     * @brief Inserts a new node at the head of the linked list.
     *
     * @param head Reference to the head pointer.
     * @param val Value to insert.
     */
    void insert_at_head(ListNode*& head, int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    /**
     * @brief Checks whether the linked list is a palindrome.
     *
     * This method creates a reversed copy of the list and compares
     * it with the original list.
     *
     * @param head Pointer to the head of the linked list.
     * @return true if the linked list is a palindrome, otherwise false.
     */
    bool isPalindrome(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* tmp = head;

        while (tmp != nullptr) {
            insert_at_head(newHead, tmp->val);
            tmp = tmp->next;
        }

        tmp = head;
        ListNode* reverseTmp = newHead;

        while (tmp != nullptr) {
            if (reverseTmp->val != tmp->val) {
                deleteList(newHead);
                return false;
            }
            tmp = tmp->next;
            reverseTmp = reverseTmp->next;
        }

        deleteList(newHead);
        return true;
    }

    /**
     * @brief Inserts a new node at the tail of the linked list.
     *
     * @param head Reference to the head pointer.
     * @param tail Reference to the tail pointer.
     * @param val Value to insert.
     */
    void insert_at_tail(ListNode*& head, ListNode*& tail, int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    /**
     * @brief Prints the linked list.
     *
     * @param head Pointer to the head of the linked list.
     */
    void print_linkedlist(ListNode* head) {
        ListNode* tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->val;
            if (tmp->next != nullptr) {
                std::cout << " -> ";
            }
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Deletes all nodes in the linked list.
     *
     * @param head Pointer to the head of the linked list.
     */
    void deleteList(ListNode* head) {
        while (head != nullptr) {
            ListNode* nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }
};

int main() {
    Solution sol;

    // Test case 1: 1->1->2->2->3->3->4->5
    ListNode* head1 = nullptr;
    ListNode* tail1 = nullptr;
    sol.insert_at_tail(head1, tail1, 1);
    sol.insert_at_tail(head1, tail1, 1);
    sol.insert_at_tail(head1, tail1, 2);
    sol.insert_at_tail(head1, tail1, 2);
    sol.insert_at_tail(head1, tail1, 3);
    sol.insert_at_tail(head1, tail1, 3);
    sol.insert_at_tail(head1, tail1, 4);
    sol.insert_at_tail(head1, tail1, 5);

    std::cout << "Test case 1: ";
    sol.print_linkedlist(head1);
    std::cout << (sol.isPalindrome(head1) ? "Given linked list is a palindrome" :
                                         "Given linked list is not a palindrome")
              << std::endl << std::endl;

    // Test case 2: 1->1
    ListNode* head2 = nullptr;
    ListNode* tail2 = nullptr;
    sol.insert_at_tail(head2, tail2, 1);
    sol.insert_at_tail(head2, tail2, 1);

    std::cout << "Test case 2: ";
    sol.print_linkedlist(head2);
    std::cout << (sol.isPalindrome(head2) ? "Given linked list is a palindrome" :
                                         "Given linked list is not a palindrome")
              << std::endl << std::endl;

    // Test case 3: 1->2->3->2->1
    ListNode* head3 = nullptr;
    ListNode* tail3 = nullptr;
    sol.insert_at_tail(head3, tail3, 1);
    sol.insert_at_tail(head3, tail3, 2);
    sol.insert_at_tail(head3, tail3, 3);
    sol.insert_at_tail(head3, tail3, 2);
    sol.insert_at_tail(head3, tail3, 1);

    std::cout << "Test case 3: ";
    sol.print_linkedlist(head3);
    std::cout << (sol.isPalindrome(head3) ? "Given linked list is a palindrome" :
                                         "Given linked list is not a palindrome")
              << std::endl;

    sol.deleteList(head1);
    sol.deleteList(head2);
    sol.deleteList(head3);

    return 0;
}