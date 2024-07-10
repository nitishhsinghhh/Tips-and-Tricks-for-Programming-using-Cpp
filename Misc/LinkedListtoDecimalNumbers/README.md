# Converting Linked List Digits to Decimal Numbers: A Comprehensive Guide

In the world of computer science and mathematics, converting a sequence of digits stored in a linked list into a single number is a fundamental operation. This process can be easily understood by drawing analogies to how we construct multi-digit numbers in everyday math. This article will delve into the conversion process for both decimal (base-10) and binary (base-2) numbers, utilizing both iterative and recursive approaches, and showcasing the efficiency of binary operations.

## Decimal Number Conversion

Our standard number system is the decimal or base-10 system, which uses the digits 0 through 9. For example, consider the number 6578 represented by the digits in a linked list:

```
To convert this sequence into the number 6578, we perform the following operations:
Loop    Character    Operation               Result
1       ‘6’          6                       6
2       ‘5’          (6 x 10) + 5            65
3       ‘7’          (65 x 10) + 7           657
4       ‘8’          (657 x 10) + 8          6578
```

## Binary Number Conversion
Let's apply the same analogy to convert a binary number, where each digit is represented by a node in a linked list, into a decimal number. Instead of multiplying by 10, we will multiply by 2 (base-2) to shift left by one bit when incorporating each binary digit into the decimal result. For example, the binary number 1011 is equivalent to:

```
Loop    Character    Operation            Result
1       ‘1’          1                    1
2       ‘0’          (1 x 2) + 0          2
3       ‘1’          (2 x 2) + 1          5
4       ‘1’          (5 x 2) + 1          11
```

## Iterative Solution in C++
The following C++ code demonstrates the iterative approach to convert a binary number stored in a linked list to its decimal equivalent:

```cpp
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head, int baseNumber = 2) {
        int res = 0;
        while (head != nullptr) {
            res = res * baseNumber + head->val;
            head = head->next;
        }
        return res;
    }
};

void testGetDecimalValue() {
    Solution sol;

    // Example 1
    ListNode* head1 = new ListNode(1, new ListNode(0, new ListNode(1)));
    int result1 = sol.getDecimalValue(head1);
    std::cout << "Example 1 - Output: " << result1 << std::endl;

    // Example 2
    ListNode* head2 = new ListNode(0);
    int result2 = sol.getDecimalValue(head2);
    std::cout << "Example 2 - Output: " << result2 << std::endl;
}

int main() {
    testGetDecimalValue();
    return 0;
}
```

## Recursive Solution in C++
In languages where methods are stateless and idempotent, iteration is not supported, leading programmers to use recursion instead. The following C++ code demonstrates the recursive approach:
```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head, int res = 0, int baseNumber = 2) {
        return head ? getDecimalValue(head->next, res * baseNumber + head->val) : res;
    }
};
```

## Binary Operation
Binary operations can optimize the conversion process. Left shifting in bitwise operations involves shifting the binary representation of a number to the left by a specified number of positions. Each left shift operation effectively multiplies the number by 2 raised to the power of the shift count.

For example, the operation res = res * 2 + head->val can be optimized using the left shift operator:

```cpp
res * 2
// Translates to this below
(res << 1)
```

The | operator performs a bitwise OR operation with the binary value, effectively adding the current node's binary value to the left-shifted result:

```Cpp

res = (res << 1) | head->val;
Iterative Solution with Binary Operations
```

```Cpp

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head != NULL) {
            res = (res << 1) | head->val;
            head = head->next;
        }
        return res;
    }
};
```

Recursive Solution with Binary Operations
```Cpp

class Solution {
public:
    int getDecimalValue(ListNode *head, int res = 0) {
        return head ? getDecimalValue(head->next, (res << 1) | head->val) : res;
    }
};
```
## Conclusion
Converting a sequence of digits in a linked list to a single number is a process that can be optimized using binary operations. Whether using iterative or recursive methods, understanding the fundamentals of positional notation and binary operations enables efficient and effective solutions. By leveraging these techniques, developers can handle various numerical conversions with ease.
