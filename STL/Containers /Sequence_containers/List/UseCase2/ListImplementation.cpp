#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode() : val(0), next(nullptr), prev(nullptr) {}
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
	ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class DoublyLinkedList {
private:
	ListNode* head;
	ListNode* tail;
	int size;

public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	int front() {
		if (head == nullptr) {
			std::cout << "List is empty." << std::endl;
			return -1;
		}
		return head->val;
	}

	int back() {
		if (tail == nullptr) {
			std::cout << "List is empty." << std::endl;
			return -1;
		}
		return tail->val;
	}

	void push_front(int value) {
		ListNode* newNode = new ListNode(value);

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}

	void push_back(int value) {
		ListNode* newNode = new ListNode(value);

		if (tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		size++;
	}

	void pop_front() {
		if (head == nullptr) {
			std::cout << "List is empty." << std::endl;
			return;
		}

		ListNode* temp = head;
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
			head->prev = nullptr;
		}

		delete temp;
		size--;
	}

	void pop_back() {
		if (tail == nullptr) {
			std::cout << "List is empty." << std::endl;
			return;
		}

		ListNode* temp = tail;

		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete temp;
		size--;
	}

	void insert(int position, int value) {
		if (position < 0 || position > size) {
			std::cout << "Invalid position." << std::endl;
			return;
		}

		if (position == 0) {
			push_front(value);
			return;
		}

		if (position == size) {
			push_back(value);
			return;
		}

		ListNode* newNode = new ListNode(value);
		ListNode* current = head;

		for (size_t i = 0; i < position; i++)
			current = current->next;

		newNode->prev = current->prev;
		newNode->next = current;
		current->prev->next = newNode;
		current->prev = newNode;

		size++;
	}

	int getSize() {
		return size;
	}

	ListNode* begin() {
		return head;
	}

	ListNode* end() {
		return tail->next;
	}

};

void main() {
	DoublyLinkedList list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	std::cout << "Front: " << list.front() << std::endl;
	std::cout << "Back: " << list.back() << std::endl;

	list.pop_front();
	list.pop_back();

	std::cout << "Front: " << list.front() << std::endl;
	std::cout << "Back: " << list.back() << std::endl;

	list.insert(1, 10);

	for (ListNode* n = list.begin(); n != list.end(); n = n->next) {
		std::cout << n->val << " ";
	}
	std::cout << std::endl;

	std::cout << "Size: " << list.getSize() << std::endl;
}

/*
Output:
Front: 1
Back: 3
Front: 2
Back: 2
2 10
Size: 2
*/
