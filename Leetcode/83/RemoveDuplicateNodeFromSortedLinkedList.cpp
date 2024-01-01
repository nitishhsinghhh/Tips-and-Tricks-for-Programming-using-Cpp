/**
 * 83. Remove Duplicates From Sorted List 
 * (https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)
*/

#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp = head;
        while(tmp != NULL && tmp->next != NULL){
            if(tmp->val == tmp->next->val){
                ListNode *delNode = tmp->next;
                tmp->next = tmp->next->next;
                delete delNode;
            }
            else{
                tmp = tmp->next;
            }
        }
        return head;
    }
    void insert_at_tail(ListNode *&head, ListNode *&tail, int val){
        // create a new node 
        ListNode *newNode = new ListNode(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void print_linkedlist(ListNode *head){
        ListNode *tmp = head;
        while(tmp != NULL){
            std::cout<<tmp->val<<" ";
            tmp = tmp->next;
        }
        std::cout<<std::endl;
    }
};
int main(){
    Solution sol;
    ListNode *head = NULL, *tail = NULL;
    sol.insert_at_tail(head, tail, 1);
    sol.insert_at_tail(head, tail, 2);
    sol.insert_at_tail(head, tail, 2);
    sol.insert_at_tail(head, tail, 3);
    sol.insert_at_tail(head, tail, 3);
    sol.insert_at_tail(head, tail, 4);
    sol.insert_at_tail(head, tail, 4);
    sol.insert_at_tail(head, tail, 5);

    // print the linked list before removing duplicate elements
    sol.print_linkedlist(head); //1->2->2->3->3->4->4->5

    //calling function for remove duplicate
    sol.deleteDuplicates(head);

    // print the linked list after removing duplicate elements
    sol.print_linkedlist(head); //1->2->3->4->5

    return 0;
}

/**
 * Output of test cases 
 * 
 * Test case 1:
 * Input: 1->1->2->2->3->3->4->5
 * Ouput: 1->2->3->4->5
 * 
 * Test case 2:
 * Input: 1->1
 * Output: 1
 * 
 * Test case 3:
 * Input: 5->5->5->6->12->13
 * Output: 5->6->12->13
*/