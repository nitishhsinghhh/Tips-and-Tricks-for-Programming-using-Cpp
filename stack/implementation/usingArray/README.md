# Implementing a Stack Using Arrays in C++

## Introduction
Stacks are fundamental data structures in computer science, widely used due to their simplicity and efficiency. They follow the Last In, First Out (LIFO) principle, where the most recently added element is the first to be removed. This article explores the implementation of a stack using arrays in C++, providing a step-by-step explanation of the code.

## What is a Stack?
A stack is a collection of elements with two main principal operations:
- **Push**: Adds an element to the collection.
- **Pop**: Removes the most recently added element.

Additional operations often include:
- **Peek/Top**: Returns the top element without removing it.
- **isEmpty**: Checks if the stack is empty.

## Why Use Arrays?
Arrays offer a simple and efficient way to implement a stack. They provide constant-time access to elements and are easy to manage within the fixed size constraints.

## Implementation
Let's dive into the implementation of a stack using arrays in C++.

### Step 1: Define Constants and Class Structure
We start by defining a constant for the maximum size of the stack and the basic structure of the `Stack` class.

```cpp
#include <iostream>
#define MAX_SIZE 100 // Define the maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE]; // Array to store stack elements
    int top; // Variable to keep track of the top element's index

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;
    }
```

### Step 2: Implement Push Operation
The push function adds an element to the stack. It checks for overflow to ensure that elements are only added if there is space.

```cpp
    // Function to push an element onto the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack Overflow" << std::endl;
        } else {
            arr[++top] = value;
            std::cout << "Pushed " << value << " onto the stack." << std::endl;
        }
    }

```

### Step 3: Implement Pop Operation
The pop function removes the top element from the stack. It checks for underflow to ensure elements are only removed if the stack is not empty.

```cpp
    // Function to pop an element from the stack
    void pop() {
        if (top < 0) {
            std::cout << "Stack Underflow" << std::endl;
        } else {
            int poppedValue = arr[top--];
            std::cout << "Popped " << poppedValue << " from the stack." << std::endl;
        }
    }

```

### Step 4: Implement Peek Operation
The peek function returns the top element without removing it. It checks if the stack is empty and returns an invalid value if it is.

```cpp
    // Function to get the top element of the stack
    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty" << std::endl;
            return -1; // Return an invalid value to indicate the stack is empty
        } else {
            return arr[top];
        }
    }

```

### Step 5: Implement isEmpty Function
The isEmpty function checks if the stack is empty.

```cpp
    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }
};
```

### Step 6: Main Function to Demonstrate Usage
The main function demonstrates how to use the stack by pushing, popping, and peeking elements.
```cpp
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    return 0;
}
```

## Conclusion
This article provided a straightforward implementation of a stack using arrays in C++. By understanding and utilizing this fundamental data structure, you can efficiently manage collections of data in a LIFO manner. The implementation can be expanded and customized as needed, making it a versatile tool in your programming arsenal.
