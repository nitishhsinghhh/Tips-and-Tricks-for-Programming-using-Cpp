# Accessing Elements in a `std::array` using a Wrapper Class in C++

This repository contains an implementation of a wrapper class around `std::array` to demonstrate accessing elements with bounds checking. The `NumbersArray` class provides a method to access elements at a specified index with error handling for out-of-range access.

## Overview

The `std::array` container in C++ provides a fixed-size array with the advantages of standard container operations. This example demonstrates how to create a wrapper class around `std::array` to access elements with bounds checking.

## NumbersArray Class

The `NumbersArray` class encapsulates a `std::array` and provides a method to access elements at a specified index.

### Constructor

- **NumbersArray()**: Initializes the array with the values `{1, 2, 3, 4, 5}`.

### Member Functions

- **getNumberAtIndex(int index) const**: Returns the element at the specified index. Throws an `std::out_of_range` exception if the index is out of bounds.
