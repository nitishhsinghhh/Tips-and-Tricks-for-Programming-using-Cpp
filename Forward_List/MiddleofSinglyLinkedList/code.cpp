// Program to find Middle of the Linked List

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
	ListNode *middleNode(ListNode *head) {
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next, fast = fast->next->next;
		}
		return slow;
	}
};

int main() {
	Solution oSolution;
	ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode *middle = oSolution.middleNode(head);
	std::cout << "Output result: " << middle->val << std::endl;

	system("pause");
}
/*
Output:
Output result: 3
*/
