#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::set;
using std::vector;

/**
 * @brief Definition for singly-linked list node.
 * 
 * @note Follows SRP (Single Responsibility Principle): This struct only represents the data structure for a node.
 */
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode* nextNode) : val(value), next(nextNode) {}
};

/**
 * @interface ILinkedListModifier
 * @brief Interface for linked list modification logic.
 * 
 * @note Follows ISP and DIP. Enables Strategy Design Pattern.
 */
class ILinkedListModifier {
public:
    virtual ~ILinkedListModifier() = default;
    virtual ListNode* deleteNodes(const vector<int>& nums, ListNode* head) = 0;
};

/**
 * @class LinkedListModifier
 * @brief Concrete implementation of ILinkedListModifier.
 * 
 * @note Follows OCP and Strategy Pattern.
 */
class LinkedListModifier : public ILinkedListModifier {
public:
    ListNode* deleteNodes(const vector<int>& nums, ListNode* head) override {
        set<int> valuesToRemove(nums.begin(), nums.end());
        ListNode* current = head;

        while (current && valuesToRemove.count(current->val)) {
            current = current->next;
        }

        ListNode* newHead = current;

        while (current && current->next) {
            if (valuesToRemove.count(current->next->val)) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return newHead;
    }
};

/**
 * @interface ILinkedListUtils
 * @brief Interface for linked list utility operations.
 * 
 * @note Follows ISP and DIP. Enables interchangeable utility strategies.
 */
class ILinkedListUtils {
public:
    virtual ~ILinkedListUtils() = default;
    virtual bool areEqual(ListNode* list1, ListNode* list2) = 0;
    virtual void print(ListNode* head) = 0;
};

/**
 * @class LinkedListUtils
 * @brief Concrete implementation of ILinkedListUtils.
 * 
 * @note Follows SRP and implements utility strategy.
 */
class LinkedListUtils : public ILinkedListUtils {
public:
    bool areEqual(ListNode* list1, ListNode* list2) override {
        while (list1 && list2) {
            cout << "Comparing: " << list1->val << " and " << list2->val << endl;
            if (list1->val != list2->val) {
                cout << "Mismatch found!" << endl;
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }

        if (list1 || list2) {
            cout << "One of the lists has extra nodes." << endl;
            return false;
        }

        cout << "Lists are equal." << endl;
        return true;
    }

    void print(ListNode* head) override {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "\n" << endl;
    }
};

/**
 * @interface ILinkedListTest
 * @brief Interface for running linked list tests.
 * 
 * @note Follows ISP and DIP. Enables interchangeable test strategies.
 */
class ILinkedListTest {
public:
    virtual ~ILinkedListTest() = default;
    virtual void runAllTests(ILinkedListModifier& modifier, ILinkedListUtils& utils) = 0;
};

/**
 * @class LinkedListTest
 * @brief Concrete implementation of ILinkedListTest.
 * 
 * @note Follows SRP and uses Strategy Pattern for modifier and utility injection.
 */
class LinkedListTest : public ILinkedListTest {
public:
    void runAllTests(ILinkedListModifier& modifier, ILinkedListUtils& utils) override {
        testCase1(modifier, utils);
        testCase2(modifier, utils);
        testCase3(modifier, utils);
        cout << "All test cases passed successfully!" << "\n" << endl;
    }

private:
    void testCase1(ILinkedListModifier& modifier, ILinkedListUtils& utils) {
        cout << "Test Case 1: Input: nums = [1,2,3], head = [1,2,3,4,5]" << endl;
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        vector<int> nums{1, 2, 3};
        ListNode* result = modifier.deleteNodes(nums, head);
        ListNode* expected = new ListNode(4, new ListNode(5));
        assert(utils.areEqual(result, expected));
        cout << "Test Case 1 Output: ";
        utils.print(result);
    }

    void testCase2(ILinkedListModifier& modifier, ILinkedListUtils& utils) {
        cout << "Test Case 2: Input: nums = [1], head = [1,2,1,2,1,2]" << endl;
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(1, new ListNode(2, new ListNode(1, new ListNode(2))))));
        vector<int> nums{1};
        ListNode* result = modifier.deleteNodes(nums, head);
        ListNode* expected = new ListNode(2, new ListNode(2, new ListNode(2)));
        assert(utils.areEqual(result, expected));
        cout << "Test Case 2 Output: ";
        utils.print(result);
    }

    void testCase3(ILinkedListModifier& modifier, ILinkedListUtils& utils) {
        cout << "Test Case 3: Input: nums = [5], head = [1,2,3,4]" << endl;
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        vector<int> nums{5};
        ListNode* result = modifier.deleteNodes(nums, head);
        ListNode* expected = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        assert(utils.areEqual(result, expected));
        cout << "Test Case 3 Output: ";
        utils.print(result);
    }
};

/**
 * @brief Main function
 * 
 * @note Demonstrates Strategy Pattern and DIP by injecting concrete implementations of interfaces.
 */
int main() {
    LinkedListModifier modifier;           // Strategy implementation
    LinkedListUtils utils;                 // Utility implementation
    LinkedListTest tester;                 // Test implementation

    tester.runAllTests(modifier, utils);   // Inject dependencies via interfaces
    return 0;
}
