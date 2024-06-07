/*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Problem Number in Leetcode: 24
  Problem Link: https://leetcode.com/problems/swap-nodes-in-pairs/
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
      
        ListNode *newHead = head->next;
        ListNode *current = head;
        ListNode *previous = nullptr;
      
        while(current && current->next){
            // store next node 
            ListNode *next_node = current->next;

            // store the next node of the next node 
            ListNode *second_next_node = current->next->next;

            // swap pointers
            next_node->next = current;
            // link to prev node 
            if(previous){
                previous->next = next_node;
            }
            current->next = second_next_node;

            // store tmp as previous node for next iteration
            previous = current;

            // move tmp for next pair
            current = current->next;
        }
        
        return newHead;
    }
};

int main() {
    // Create a static input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));

    // Create an instance of Solution class
    Solution solution;

    // Call the swapPairs function
    ListNode *newHead = solution.swapPairs(head);

    // Output the modified list
    while(newHead) {
        std::cout << newHead->val << " ";
        newHead = newHead->next;
    }
  
    return 0;
}

/*
==================================OUTPUT=======================================
TESTCASE 1:
-----------
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 2 -> 1 -> 4 -> 3 -> 5
----------------------------------------------

TESTCASE 2:
-----------
Input: 9 -> 0 -> 8 -> 0 -> 5 -> 0
Output: 0 -> 9 -> 0 -> 8 -> 0 -> 5
-----------------------------------------------

TESTCASE 3:
-----------
Input: 1
Output: 1
-----------------------------------------------

TESTCASE 4:
-----------
Input: NULL
Output: NULL
===============================================================================
*/
