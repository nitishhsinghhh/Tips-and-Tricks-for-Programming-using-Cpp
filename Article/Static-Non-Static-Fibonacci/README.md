# Understanding Static vs Non-Static and Parameter Passing in C++ with Fibonacci
In C++, understanding how functions behave depending on their static/non-static nature and how parameters are [passed—by value, reference, or pointer](https://nitishhsinghhh.medium.com/pass-by-value-and-pass-by-reference-in-c-15c4393eb675)—is crucial for writing efficient and maintainable code. Let's explore these concepts using a simple Fibonacci class.

# Understanding Static vs Non-Static and Parameter Passing in C++ with Fibonacci

## Table of Contents
1. [Class Structure Overview](#class-structure-overview)  
2. [Static vs Non-Static Functions](#static-vs-non-static-functions)  
   - [Non-Static Functions](#non-static-functions)  
   - [Static Functions](#static-functions)  
   - [Common Error](#common-error)  
3. [Parameter Passing Techniques](#parameter-passing-techniques)  
   - [Pass by Value](#pass-by-value)  
   - [Pass by Reference](#pass-by-reference)  
   - [Pass by Pointer](#pass-by-pointer)  
4. [Fibonacci Function Implementations](#fibonacci-function-implementations)  
   - [Incorrect Version: Recursive Call for Pointer Version](#incorrect-version-recursive-call-for-pointer-version)  
5. [Sample Usage in main()](#sample-usage-in-main)
6. [Modern Guidance (C++11 and beyond)](#modern-guidance-c11-and-beyond)  
7. [When a Normal Function Call is Enough](#when-a-normal-function-call-is-enough)  
8. [When Function Pointers Are Useful](#when-function-pointers-are-useful)  
9. [Rule of Thumb](#rule-of-thumb)  

# Class Structure Overview
```Cpp
class fibonacci {
public:
    int fibByValue(int num);                  		// Non-static, pass by value
    static int fibByValueStatic(int num);     		// Static, pass by value
    int fibByRef(const int& num);             		// Non-static, pass by reference
    int fibByPointer(int* num);               		// Non-static, pass by pointer
	typedef int (*FibFunc)(int);			  		// Function pointer to static function
    typedef int (fibonacci::* MemberFibFunc)(int);	// Function pointer to non-static member function
	static void runFib(int n, FibFunc fibFunc);		// Callback Function

};
```

## Static vs Non-Static Functions
### Non-Static Functions
- Belong to an instance of a class.
- Require an object to be created before calling.
Example:
```Cpp
fibonacci fib;
fib.fibByValue(5);
```
### Static Functions
- Belong to the class itself, not any object.
- Can be called directly using the class name.
Example:
```Cpp
fibonacci::fibByValueStatic(5);
```
### Common Error
Trying to call a non-static function like this:
```CPP
fibonacci::fibByValue(5); // Error: needs an object
```

## Parameter Passing Techniques

### Pass by Value
 
- A copy of the value is passed.
- Changes inside the function do not affect the original variable.
- Simple and safe, but can be inefficient for large objects.
```Cpp
int fibonacci::fibByValue(int num);
```

### Pass by Reference
 
- Passes a reference to the original variable.
- Efficient for large objects.
- const ensures the function doesn't modify the original value.
- Cannot bind non-const reference to temporary values (e.g., num - 1).

```Cpp
int fibonacci::fibByRef(const int& num);
```

### [Pass by Pointer](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/blob/main/Interview_Question/Pointers-in-Cpp/README.md)
 
- Passes the address of the variable.
- Allows modification of the original value (unless const is used).
- Requires careful memory handling.
```Cpp
int fibonacci::fibByPointer(int* num);
```

## Fibonacci Function Implementations
```Cpp
int fibonacci::fibByValue(int num) {
	if (num == 1 || num == 2)
		return 1;
	else
		return fibonacci::fibByValue(num - 1) + fibonacci::fibByValue(num - 2);
}
 
int fibonacci::fibByValueStatic(int num) {
	if (num == 1 || num == 2)
		return 1;
	else
		return fibonacci::fibByValueStatic(num - 1) + fibonacci::fibByValueStatic(num - 2);
}
 
int fibonacci::fibByRef(const int& num) {
	if (num == 1 || num == 2)
		return 1;
	else
		return fibonacci::fibByRef(num - 1) + fibonacci::fibByRef(num - 2);
}
 
int fibonacci::fibByPointer(int* num) {
	if (*num == 1 || *num == 2)
		return 1;
	else {
 
		int n1 = *num - 1;
		int n2 = *num - 2;
		return fibonacci::fibByPointer(&n1) + fibonacci::fibByPointer(&n2);
	}
}
// We create new local integers for recursion because directly decrementing the pointer would lead to invalid memory access.

void fibonacci::runFib(int n, FibFunc fibFunc) {
    std::cout << "Callback Result: " << fibFunc(n) << std::endl;
}

```

### Incorrect Version: Recursive Call for Pointer Version
```Cpp
return fibonacci::fibByPointer(&(*(num - 1))) + fibonacci::fibByPointer(&(*(num - 2)));
```

## Sample Usage in main()
```Cpp
int main() {
    fibonacci fib;
 
    // Non-static pass by value
    std::cout << fib.fibByValue(5) << std::endl;
 
    // Static pass by value
    std::cout << fibonacci::fibByValueStatic(5) << std::endl;
 
    // Non-static pass by reference
    int numRef = 6;
    std::cout << fib.fibByRef(numRef) << std::endl;
 
    // Non-static pass by pointer
    int numPtr = 7;
    std::cout << fib.fibByPointer(&numPtr) << std::endl;

	// Assign function address to pointer
	fibonacci::FibFunc fPtr = &fibonacci::fibByValueStatic;
	std::cout << fPtr(10) << std::endl;
	 
	fibonacci::MemberFibFunc memberPtr = &fibonacci::fibByValue;
	std::cout << (fib.*memberPtr)(11) << std::endl;

	fibonacci::runFib(6, fibonacci::fibByValueStatic);
}
```
## Modern Guidance (C++11 and beyond)
Prefer std::function or lambdas instead of raw function pointers when you need flexibility.
Safer, more expressive, can bind member functions and captures.

```Cpp
#include <iostream>
#include <functional>

class Fibonacci {
public:
    static int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// Functor that calls Fibonacci
struct FibFunctor {
    int operator()(int n) const {
        return Fibonacci::fib(n);
    }
};

void runFib(int n, std::function<int(int)> cb) {
    std::cout << "Result: " << cb(n) << std::endl;
}

int main() {
    runFib(6, FibFunctor());      // using functor
}
```
**### What is a Functor in C++?**
- A functor (function object) is any object that can be used like a function.
- This is possible because it overloads the function call operator operator().
- So, instead of writing a free function, you make a class/struct that behaves like a function.

## When a Normal Function Call is Enough
- Use a plain function call when:
- The logic is fixed (you know at compile time which function will be called).
- There is no need for runtime switching between different behaviors.
- Readability and performance are top priority (direct calls are the fastest).

## When Function Pointers Are Useful
- Callback Mechanism
	- Pass a function as a parameter to another function.
   	- Example: sorting with a custom comparison.
 	```Cpp
	void runFib(int n, int (*fibFunc)(int)) {
	 	std::cout << fibFunc(n) << std::endl;
	}
	runFib(6, fibonacci::fibByValueStatic);
  ```
- Runtime Decision / Strategy Pattern
- Polymorphism Alternative (lighter than inheritance/virtual)
Instead of making a base class with virtual functions, you can just pass a function pointer if all you need is one behavior swap.
- Interfacing with C APIs / Callbacks
Libraries like POSIX threads, qsort(), or graphics toolkits expect function pointers.

## Rule of Thumb
Normal function → Best when you know exactly which function to call (clarity + speed).
Function pointer / std::function → Best when you want to decide later (runtime) which function to call, or need to pass behavior around (callbacks, strategies, event systems).


