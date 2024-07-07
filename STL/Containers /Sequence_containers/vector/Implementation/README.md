# VectorClass Implementation and Usage

## Overview

This repository contains a custom implementation of a vector class in C++. The vector class, `VectorClass`, is a dynamic array that can store elements of any data type. The main features of this class include dynamic resizing, element access, insertion, and deletion.

## Files

- `VectorClass.h`: Header file containing the declaration and implementation of the `VectorClass` template class.
- `UseVector.cpp`: Source file demonstrating the usage of the `VectorClass` template class with `std::string` type.

## VectorClass Implementation

### Header File (`[VectorClass.h](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/blob/main/STL/Containers%20/Sequence_containers/vector/Implementation/UseVector.cpp)`)

The `VectorClass` template class is implemented in the header file. Here are the main components of the class:

- **Private Members:**
  - `int m_size`: Keeps track of the current size of the vector.
  - `int m_capacity`: Keeps track of the current capacity of the vector.
  - `T* m_data`: Pointer to the underlying array that stores the elements.

- **Public Members:**
  - **Constructors:**
    - Default constructor to initialize the vector with size 0 and capacity 2.
    - Constructor with one argument to initialize the vector with a given size.
    - Copy constructor to handle object initialization and copying.
  - **Destructor:**
    - Destructor to deallocate storage allocated by dynamic allocation to prevent memory leaks.
  - **Member Functions:**
    - `void reserve(int newCapacity)`: Increases the capacity of the vector to a specified amount.
    - `void push_back(const T& val)`: Adds an element to the end of the vector.
    - `void pop_back()`: Deletes the last element from the vector.
    - `T& operator[](int index)`: Overloaded operator[] to allow accessing elements using array notation.
    - `const T& operator[](int index) const`: Const version of operator[] to allow accessing elements using array notation.
    - `int size() const`: Returns the current size of the vector.
    - `bool empty() const`: Checks whether the vector is empty.
    - `void insertAt(const T& val, int index)`: Adds an element at any index in the vector.

### Source File (`[UseVector.cpp](.\UseVector.cpp)`)

The `UseVector.cpp` file demonstrates the usage of the `VectorClass` with `std::string` type. Here are the main steps:

1. **Creating a VectorClass object of type `std::string`:**
    ```cpp
    VectorClass<std::string> vec;
    ```

2. **Adding three elements to the vector using `push_back()`:**
    ```cpp
    vec.push_back("A");
    vec.push_back("B");
    vec.push_back("C");
    ```

3. **Printing the element at index 2 using `operator[]`:**
    ```cpp
    std::cout << "The vector at index 2 is: " << vec[2] << std::endl;
    ```

4. **Printing all the elements of the vector using a for loop and `operator[]`:**
    ```cpp
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    ```

5. **Inserting a new element at index 2 using `insertAt()` and printing the updated elements of the vector:**
    ```cpp
    vec.insertAt("AA", 2);
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    ```

6. **Removing the last element using `pop_back()` and printing the updated elements of the vector:**
    ```cpp
    vec.pop_back();
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    ```

7. **Pausing the console:**
    ```cpp
    system("pause");
    ```

## Usage

1. Include the `VectorClass.h` header file in your source file.
2. Create an object of `VectorClass` with the desired data type.
3. Use the provided member functions to manipulate the vector.

## Example

Here is a simple example of how to use the `VectorClass`:

```cpp
#include <iostream>
#include <string>
#include "VectorClass.h"

int main() {
    VectorClass<std::string> vec;
    vec.push_back("Hello");
    vec.push_back("World");
    vec.insertAt("C++", 1);

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    vec.pop_back();

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    return 0;
}
