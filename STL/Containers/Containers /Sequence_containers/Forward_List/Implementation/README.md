# Custom Implementation of `std::forward_list` in C++

This repository contains a custom implementation of the `std::forward_list` container in C++. The implementation includes basic functionalities such as adding elements to the front, removing elements from the front, checking if the list is empty, iterating through the list, and clearing the list.

## Overview

A singly linked list is a type of data structure where each node contains a value and a pointer to the next node. This custom implementation of `std::forward_list` provides similar functionalities to the standard library's forward list.

## Components

### Node Structure

The `detail::forward_list_node` structure represents each node in the list and includes:
- An integer value (`value`).
- A pointer to the next node (`next`).

### Allocator Base

The `detail::forward_list_alloc_base` structure manages memory allocation for the nodes using a specified allocator.

### Iterator

The `detail::forward_list_iterator` structure provides an iterator for the forward list, supporting basic iterator operations.

### Forward List Class

The `forward_list` class template provides the main functionalities of the singly linked list.
