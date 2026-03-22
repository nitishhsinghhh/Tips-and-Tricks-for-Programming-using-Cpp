/**
 * 83. Remove Duplicates From Sorted List
 * (https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)
*/

#include<iostream>
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
		while (tmp != NULL && tmp->next != NULL) {
			if (tmp->val == tmp->next->val) {
				ListNode *delNode = tmp->next;
				tmp->next = tmp->next->next;
				delete delNode;
			}
			else {
				tmp = tmp->next;
			}
		}
		return head;
	}
	void print_linkedlist(ListNode *head) {
		ListNode *tmp = head;
		while (tmp != NULL) {
			std::cout << tmp->val << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
};
int main() {
	Solution sol;
	ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	// print the linked list before removing duplicate elements
	sol.print_linkedlist(head); //1->2->2->3->3->4->4->5
	//calling function for remove duplicate
	sol.deleteDuplicates(head);
	// print the linked list after removing duplicate elements
	sol.print_linkedlist(head); //1->2->3->4->5
	system("pause");
	return 0;
}
