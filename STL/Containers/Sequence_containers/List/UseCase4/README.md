# Deleting an Element from a Doubly Linked List in C++

This repository contains an implementation of deleting an element at a specific position from a doubly linked list using the C++ Standard Library's `std::list` container. The implementation includes various test cases to demonstrate the functionality.

## Overview

The `Solution` class provides a method to delete an element at a specified position from a doubly linked list. The position is 0-based, and the function handles different scenarios such as deleting the middle element, the first element, the last element, and handling edge cases like an empty list or a single-element list.

## Solution Class

The `Solution` class contains the following method:
- **deleteposElement(const std::list<int>& initialList, const int position)**: Deletes the element at the specified position from the provided list and prints the resulting list.
