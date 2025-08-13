# Segmentation Fault in C++
Segmentation faults in C++ occur when a program attempts to access a memory location it does not have permission to access. Generally, this error occurs when memory access is violated and is a type of general protection fault. Segfaults are the abbreviation for segmentation faults.

## Table of Contents
- [Causes of Segmentation Fault in C++](#causes-of-segmentation-fault-in-c)
- [Common Segmentation Fault Scenarios](#common-segmentation-fault-scenarios)
  1. [Modifying a String Literal](#1-modifying-a-string-literal)
  2. [Accessing an Address That is Freed](#2-accessing-an-address-that-is-freed)
  3. [Accessing out-of-bounds Array Index](#3-accessing-out-of-bounds-array-index)
  4. [Improper use of scanf()](#4-improper-use-of-scanf)
  5. [Stack Overflow](#5-stack-overflow)
  6. [Buffer Overflow](#6-buffer-overflow)
  7. [Dereferencing an Uninitialized or NULL Pointer](#7-dereferencing-an-uninitialized-or-null-pointer)
- [How to Identify the Cause of Segmentation Faults in C++](#how-to-identify-the-cause-of-segmentation-faults-in-c)
- [How to Fix Segmentation Faults](#how-to-fix-segmentation-faults)
- [Conclusion](#conclusion)

## Causes of Segmentation Fault in C++

A program has access to specific regions of memory while it is running. The stack is used to hold the local variables for each function, and memory can also be allocated at runtime and saved on the heap (referred to as the "free store" in C++). A segmentation fault occurs when a program tries to:

- Access memory that it does not own.
- Dereference a `nullptr` or NULL pointer.
- Modify read-only memory.

It is an error indicating memory corruption.

## Common Segmentation Fault Scenarios

In a segmentation fault, a program tries to access memory that it is not authorized to access, or that does not exist. Some common scenarios that can cause segmentation faults are:

### 1. Modifying a String Literal

String literals are stored in the read-only section of memory. The following program may crash (giving a segmentation fault error) because the line `*(str + 1) = 'n'` tries to write to read-only memory.

```cpp
// C++ program to demonstrate segmentation fault by modifying a string literal
#include <iostream>

int main() {
    char* str;

    // Stored in read-only part of data segment
    str = "GfG";

    // Problem: trying to modify read-only memory
    *(str + 1) = 'n';
    return 0;
}
```

### 2. Accessing an Address That is Freed
In the code below, the pointer p is dereferenced after freeing the memory block, which is not allowed. Such pointers are called dangling pointers and they produce segmentation faults or abnormal program termination at runtime.

```Cpp
#include <iostream>

int main(void) {
    // allocating memory to p
    int* p = (int*)malloc(sizeof(int));
    *p = 100;

    // deallocated the space allocated to p
    free(p);

    // segmentation fault as now this statement is illegal
    *p = 110;

    return 0;
}
```

### 3. Accessing out-of-bounds Array Index
Accessing an out-of-bounds array index in C++ may cause a segmentation fault or other undefined behavior. There is no boundary checking for arrays in C++. Using containers such as std::vector::at() or an if statement can prevent out-of-bound errors.

```Cpp
#include <iostream>

int main() {
    int arr[2];

    // Accessing out of bound
    arr[3] = 10;
    return 0;
}
```

### 4. Improper Use of scanf()
The scanf() function expects the address of a variable as an input. In this program, n takes a value of 2 and assumes its address as 1000. If we pass n to scanf(), input fetched from STDIN is placed in invalid memory 2 instead of 1000, causing memory corruption and a segmentation fault.

```Cpp
#include <iostream>

int main() {
    int n = 2;
    std::cin >> n;
    return 0;
}
```


### 5. Stack Overflow
Running out of memory on the stack causes a stack overflow, leading to a segmentation fault. This can happen due to large array sizes, a large number of recursive calls, or an excessive number of local variables.

```Cpp
// C++ program to illustrate the segmentation fault due to stack overflow
#include <iostream>

int main() {
    int array[2000000000];
    return 0;
}
```


### 6. Buffer Overflow
A buffer overflow occurs when the data stored in the buffer exceeds the allocated size, leading to a segmentation fault. Most methods in C++ do not perform bound checking, so buffer overflows happen frequently when the required size is not allotted to the buffer.

``` Cpp
#include <iostream>

int main() {
    char ref[20] = "This is a long string";
    char buf[10];
    sscanf(ref, "%s", buf);

    return 0;
}
```

### 7. Dereferencing an Uninitialized or NULL Pointer
Dereferencing an uninitialized pointer (wild pointer) or a NULL pointer results in undefined behavior, data corruption, program errors, or segmentation faults. The following example demonstrates this:

```Cpp
#include <iostream>

int main() {
    int* ptr;
    int* nptr = NULL;
    std::cout << *ptr << " " << *nptr;
    return 0;
}
```

## How to Identify the Cause of Segmentation Faults in C++
To identify the cause of segmentation faults, you can analyze the core dump created by the program using tools like gdb. Running the program in gdb can also help check for segmentation faults. Other tools like valgrind, Address Sanitizer, etc., can help detect segmentation faults and show why they occurred.

Note: The core dump refers to the recording of the state of the program, including its resources in memory and the processor. Trying to access non-existent memory or memory used by other processes can cause segmentation faults, leading to a core dump.

## How to Fix Segmentation Faults
You can fix segmentation faults by being careful about the causes mentioned:

- Avoid modifying string literals or use built-in string containers.
- Be cautious when using pointers, as they are one of the most common causes. You can also use smart pointers instead of raw pointers.
- Consider the buffer and stack size before storing data to avoid buffer or stack overflow.
- Check bounds before accessing array elements or use STL containers such as vectors, sets, maps, etc.
- Use scanf() and printf() carefully to avoid incorrect format specifiers or buffer overflow.

## Conclusion
The main cause of segmentation faults is accessing memory that does not belong to your program. By avoiding such access, you can prevent segmentation faults. If you cannot find the source of the error, it is recommended to use a debugger, as it directly points to the error in the program.
