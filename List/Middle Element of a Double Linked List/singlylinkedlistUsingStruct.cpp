#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode * Next;
	ListNode(): val(0), Next(nullptr) {}
	ListNode(int x) : val(x), Next(nullptr) {}
	ListNode(int x, ListNode *Next) : val(x), Next(Next) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while (fast && fast->Next)
			slow = slow->Next, fast = fast->Next->Next;
		return slow;
	}
};

int main() {
	ListNode *head = new ListNode(1);
	head->Next = new ListNode(2);
	head->Next->Next = new ListNode(3);
	head->Next->Next->Next = new ListNode(4);
	head->Next->Next->Next->Next = new ListNode(5);
	head->Next->Next->Next->Next->Next = new ListNode(6);

	Solution oSolution;
	ListNode *middle = oSolution.middleNode(head);
	cout << "The middle node is: " << middle->val << endl;

	return 0;
}
