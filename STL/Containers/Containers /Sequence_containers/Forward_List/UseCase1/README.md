# Finding the Middle of a Linked List in C++

This repository contains an implementation to find the middle node of a singly linked list using a two-pointer approach. The `Solution` class provides a method to find the middle node of the linked list.

## Overview

A singly linked list is a type of data structure where each node contains a value and a pointer to the next node. This example demonstrates how to find the middle node of the list using two pointers (`slow` and `fast`). The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time. When the `fast` pointer reaches the end of the list, the `slow` pointer will be at the middle node.

## ListNode Structure

The `ListNode` structure represents each node in the list and includes:
- An integer value (`val`).
- A pointer to the next node (`next`).

### Constructors

- **ListNode()**: Initializes `val` to `0` and `next` to `nullptr`.
- **ListNode(int x)**: Initializes `val` to a given integer and `next` to `nullptr`.
- **ListNode(int x, ListNode *next)**: Initializes `val` to a given integer and `next` to a provided `next` pointer.

## Solution Class

The `Solution` class contains the following method:
- **middleNode(ListNode *head)**: Returns the middle node of the singly linked list.
