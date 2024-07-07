#include<iostream>

// Definition of ListNode structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;

    // Default constructor
    ListNode() : val(0), next(nullptr), prev(nullptr) {}

    // Constructor with a value
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}

    // Constructor with value, next pointer, and prev pointer
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

// Definition of DoublyLinkedList class
class DoublyLinkedList {
private:
	ListNode* head;
	ListNode* tail;
	int size;

public:
	// Default constructor
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	// Destructor
        ~DoublyLinkedList() {
		ListNode* current = head;
		while (current != nullptr) {
		    ListNode* nextNode = current->next;
		    delete current;
		    current = nextNode;
		}
        }

        // Get the value of the front node
	int front() {
		if (head == nullptr) {
			std::cout << "List is empty." << std::endl;
			return -1;
		}
		return head->val;
	}

	// Get the value of the back node
	int back() {
		if (tail == nullptr) {
			std::cout << "List is empty." << std::endl;
			return -1;
		}
		return tail->val;
	}

	// Add a node to the front of the list
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

	// Add a node to the end of the list
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

	 // Remove a node from the front of the list
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

	// Insert a node at a specific position
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

	// Get the size of the list
	int getSize() {
		return size;
	}

	// Get the head node
	ListNode* begin() {
		return head;
	}

	 // Get the end node (one past the last node)
	ListNode* end() {
		return tail->next;
	}

};

int main() {
	DoublyLinkedList list;

	// Add nodes to the list
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	// Print the front and back values
	std::cout << "Front: " << list.front() << std::endl;
	std::cout << "Back: " << list.back() << std::endl;

	// Remove nodes from the front and back
	list.pop_front();
	list.pop_back();

	 // Print the front and back values again
	std::cout << "Front: " << list.front() << std::endl;
	std::cout << "Back: " << list.back() << std::endl;

	// Insert a node at position 1
	list.insert(1, 10);

	// Print all the nodes in the list
	for (ListNode* n = list.begin(); n != list.end(); n = n->next) {
		std::cout << n->val << " ";
	}
	std::cout << std::endl;

	// Print the size of the list
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
