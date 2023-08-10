// Program to find Middle of the Linked List

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
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
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	ListNode *middle = oSolution.middleNode(head);
	cout << "Output result: " << middle->val << endl;

	system("pause");
}
/*
Output: 
Output result: 3
*/
