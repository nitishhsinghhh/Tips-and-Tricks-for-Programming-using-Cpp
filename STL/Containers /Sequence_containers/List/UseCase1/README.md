# Doubly Linked List Implementations in C++

This repository demonstrates two different usage of a doubly linked list using a custom node structure called `ListNode`.

## Overview

A doubly linked list is a type of linked list in which each node contains a value and two pointers: one to the next node and one to the previous node.

## Case 1: [Manual Node Creation and Linking](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/blob/main/STL/Containers%20/Sequence_containers/List/UseCase1/LinkedList_V1.0.cpp)

### Node Structure

The `ListNode` structure represents each node in the list and includes:
- An integer value (`val`).
- A pointer to the next node (`next`).
- A pointer to the previous node (`prev`).

### Constructors and Destructor

- **Default Constructor**: Initializes `val` to `0`, and both `next` and `prev` pointers to `nullptr`.
- **Parameterized Constructor**: Initializes `val` to a given integer, and both `next` and `prev` pointers to `nullptr`.
- **Parameterized Constructor with Pointers**: Initializes `val` to a given integer, `next` to a provided `next` pointer, and `prev` to a provided `prev` pointer.
- **Destructor**: Deletes the next node in the list recursively to clean up memory.

### Steps Involved

1. **Creating and Linking Nodes**:
   - Nodes are created manually for values 1 to 5.
   - Each new node is linked to the previous and next nodes accordingly.

2. **Forward Traversal**:
   - Starting from the first node, the list is traversed by following the `next` pointers.
   - The value of each node is printed until the end of the list is reached (`next` pointer is `nullptr`).

3. **Backward Traversal**:
   - Starting from the last node, the list is traversed by following the `prev` pointers.
   - The value of each node is printed until the start of the list is reached (`prev` pointer is `nullptr`).

4. **Memory Cleanup**:
   - The list is cleaned up by deleting the first node, which triggers the destructor to recursively delete all nodes.


# Case 2: [Node Creation and Linking in a Loop](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/blob/main/STL/Containers%20/Sequence_containers/List/UseCase1/LinkedList_V1.1.cpp)

## Node Structure
The `ListNode` structure is the same as in Case 1.

## Steps Involved

### Creating and Linking Nodes in a Loop:
- Nodes are created in a loop for values 1 to 5.
- Each new node is linked to the previous node using the `prev` pointer, and the `next` pointer of the previous node is updated accordingly.
- The `head` pointer is set to the first node.

### Forward Traversal:
- Starting from the `head`, the list is traversed by following the `next` pointers.
- The value of each node is printed until the end of the list is reached (`next` pointer is `nullptr`).

### Backward Traversal:
- Starting from the last node, the list is traversed by following the `prev` pointers.
- The value of each node is printed until the start of the list is reached (`prev` pointer is `nullptr`).

### Memory Cleanup:
- The list is traversed from the `head`, and each node is deleted to free up the allocated memory.
