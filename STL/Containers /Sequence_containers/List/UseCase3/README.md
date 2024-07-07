# Doubly Linked List with Middle Element Deletion in C++

This repository contains an implementation of a doubly linked list using a custom node structure called `ListNode` and a class `Solution` to manage the list operations. The implementation includes methods to insert elements, delete the middle element, and print the list.

## Overview

A doubly linked list is a type of linked list in which each node contains a value and two pointers: one to the next node and one to the previous node. This implementation provides functionality to manage the list and ensures proper memory management through a destructor.

## Node Structure

The `ListNode` structure represents each node in the list and includes:
- An integer value (`val`).
- A pointer to the next node (`next`).
- A pointer to the previous node (`prev`).

### Constructors

- **Default Constructor**: Initializes `val` to `0`, and both `next` and `prev` pointers to `nullptr`.
- **Parameterized Constructor**: Initializes `val` to a given integer, and both `next` and `prev` pointers to `nullptr`.
- **Parameterized Constructor with Pointers**: Initializes `val` to a given integer, `next` to a provided `next` pointer, and `prev` to a provided `prev` pointer.

## Solution Class

The `Solution` class manages the doubly linked list operations, including adding, removing, and accessing nodes, as well as maintaining the list size.

### Constructors and Destructor

- **Default Constructor**: Initializes an empty list.
- **Destructor**: Recursively deletes all nodes to clean up memory.

### Member Functions

- **insert(int value)**: Adds a node with the given value to the end of the list.
- **deleteMiddleElement()**: Deletes the middle element of the list using two pointers (`fast` and `slow`).
- **printList()**: Prints all the values in the list.
