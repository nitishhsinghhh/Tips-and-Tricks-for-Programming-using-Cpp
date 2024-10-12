/**
 * 234. Palindrome Linked list 
 * (https://leetcode.com/problems/palindrome-linked-list/description/)
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
    void insert_at_head(ListNode *&head, int val){
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *tmp = head;
        while(tmp != NULL){
            insert_at_head(newHead, tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp != NULL){
            if(newHead->val != tmp->val){
                return false;
            }
            tmp = tmp->next;
            newHead = newHead->next;
        }
        return true;
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
    

    bool res;

    res = sol.isPalindrome(head);

    if(res){
        std::cout<<"Given linked list is a palindrome"<<std::endl;
    }
    else{
        std::cout<<"Given linked list is not a palindrome"<<std::endl;
    }

    return 0;
}

/**
 * Output of test cases 
 * 
 * Test case 1:
 * Input: 1->1->2->2->3->3->4->5
 * Ouput: false
 * 
 * Test case 2:
 * Input: 1->1
 * Output: true
 * 
 * Test case 3:
 * Input: 1->2->3->2->1
 * Output: true
*/
