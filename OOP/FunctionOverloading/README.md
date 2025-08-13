# Function Overloading and Default Parameters in C++

## Table of Contents

1. [Function Overloading in C++](#1-function-overloading-in-c)
2. [Conditions for Function Overloading Parameters](#2-conditions-for-function-overloading-parameters)  
   2.1 [Different Parameter Types](#21-different-parameter-types)  
   2.2 [Different Number of Parameters](#22-different-number-of-parameters)  
   2.3 [Different Sequence of Parameters](#23-different-sequence-of-parameters)  
   2.4 [Parameters with Default Values](#24-parameters-with-default-values)  
3. [Important Notes About Default Parameters in Overloading](#3-important-notes-about-default-parameters-in-overloading)  
   3.1 [USE CASE 1 — Function Overloading Ambiguity Caused by Default Parameters](#31-use-case-1--function-overloading-ambiguity-caused-by-default-parameters)  
   3.2 [USE CASE 2 — Conflicting Default Arguments in Overloads](#32-use-case-2--conflicting-default-arguments-in-overloads)  
   3.3 [USE CASE 3 — Multiple Overloads Becoming Ambiguous with Defaults](#33-use-case-3--multiple-overloads-becoming-ambiguous-with-defaults)  
   3.4 [USE CASE 4 — Conflicts Between Inline Definition and Separate Declaration](#34-use-case-4--conflicts-between-inline-definition-and-separate-declaration)  
4. [How Function Overloading Works](#4-how-function-overloading-works)


Function overloading is a feature of object-oriented programming that allows multiple functions to have the same name but different parameters. This concept enables a function to perform different tasks based on the input parameters. Function overloading is considered an example of polymorphism in C++.

Key points about function overloading:
- Functions with the same name but different parameters constitute function overloading.
- The purpose of function overloading is to improve the readability of the program by using the same function name for related operations.
- For example, if a program needs to perform addition on a varying number of arguments, using function overloading with the same function name but different parameter lists (e.g., a(int, int) for two parameters and b(int, int, int) for three parameters) enhances the clarity and understanding of the function's behavior.

### Conditions for Function Overloading Parameters

Parameters for function overloading should adhere to one or more of the following conditions:
- Parameters should have different types
  - Example: 
    - `add(int a, int b)`
    - `add(double a, double b)`

```cpp
#include <iostream>

void add(int a, int b) {
	std::cout << "sum = " << (a + b);
}

void add(double a, double b) {
	std::cout << std::endl << "sum = " << (a + b);
}

int main() {
	add(10, 2);
	add(5.3, 6.2);

	return 0;
}
```
- Parameters should have a different number
  - Example:
    - `add(int a, int b)`
    - `add(int a, int b, int c)`
   
```cpp
#include <iostream>

void add(int a, int b) {
	std::cout << "sum = " << (a + b);
}

void add(int a, int b, int c) {
	std::cout << std::endl << "sum = " << (a + b + c);
}

int main() {
	add(10, 2);
	add(5, 6, 4);

	return 0;
}
```
- Parameters should have a different sequence of parameters
  - Example:
    - `add(int a, double b)`
    - `add(double a, int b)`
   
```cpp
#include<iostream>

void add(int a, double b) {
	std::cout << "sum = " << (a + b);
}

void  add(double a, int b){
	std::cout << std::endl << "sum = " << (a + b);
}

int main() {
	add(10, 2.5);
	add(5.5, 6);

	return 0;
}
```

- Parameters with Default Values
Default parameters can affect overload resolution and sometimes cause ambiguity.
```Cpp
#include <iostream>

void add(int a, int b = 5) {
    std::cout << "int version, sum = " << (a + b);
}

void add(double a) {
    std::cout << "\ndouble version, sum = " << (a + 5.0);
}

int main() {
    add(10);   // Matches `add(int, int=5)` — NOT the double version
    add(3.5);  // Matches `add(double)`
}
```
## Important notes about default parameters in overloading

### USE CASE 1: Function Overloading Ambiguity Caused by Default Parameters

```cpp
#include <iostream>

void compute(int a, int b = 10) {
    std::cout << "First version: " << a + b << "\n";
}

void compute(int b = 20) { 
    std::cout << "Second version: " << a + b << "\n";
}

int main() {
    compute(5); 
}
```

When the compiler checks for overloading, it ignores default parameter values.
So your two functions look like this to the compiler:
```cpp
void compute(int, int);  // from: void compute(int a, int b = 10);
void compute(int);       // from: void compute(int b = 20);
```

**C++ rules:Two functions can be overloaded only if their signatures differ (parameter count or types).** <br>
Here:
compute(int, int) is different from compute(int)
So they can both exist at first glance.


- When you write:
```cpp
compute(5);
```
- Both are viable:
compute(int) → exact match
compute(int, int) → matches because b can be filled with default 10
Now the compiler must choose one best match — but both are equally good.
This leads to error.

- **Why the Compiler Rejects It** <br>
The compiler cannot decide which one you meant.
Default arguments are only considered after the overload is chosen, so they cannot be used to resolve the tie — instead, they cause the tie.

### USE CASE 2: Conflicting Default Arguments in Overloads
```cpp
#include <iostream>

void compute(int a, int b = 10);  
void compute(int a, int b = 20); 

void compute(int a, int b) {
    std::cout << a + b << "\n";
}

int main() {
    compute(5); // Which default b? Compiler refuses.
}
```
What the compiler actually sees
In C++, the function signature ignores default argument values.
The signature is just:
```cpp
void compute(int, int);
```
So to the compiler, both declarations are the same function — you’re just giving it two conflicting default values.

- Why it’s an error
It’s an error because both declarations have the same signature (int, int) but specify different defaults for b.
Default arguments are tied to the declaration, so giving a new default in a redeclaration creates a conflict, and the compiler rejects it.

### USE CASE 3: Multiple overloads becoming ambiguous with defaults
```cpp
void h(int a, int b = 5);
void h(int a, double b = 5.0); // Ambiguous if `h(10)` is called
```
h(10) matches both, so compiler cannot decide → ambiguity error.

### USE CASE 4: Conflicts between inline definition and separate declaration
```cpp
void k(int x = 5);
void k(int x) { } // Missing default here is fine, but changing it causes error
```
We can not do this 
```cpp
// Declaration with one default
void k(int x = 5);

// Definition with a different default
void k(int x = 10) { }  
```

- Why this happens:
  	- Default arguments are not part of the function signature — they are tied to the declaration in a given scope.
  	- When you declare it once with x = 5, the compiler stores that as the only allowed default for this parameter.
  	- Giving a different default (x = 10) in the definition is seen as a conflicting redeclaration of the same function.













## How Function Overloading Works

Function overloading in C++ operates based on the following rules:

1. Exact Match: When a function call exactly matches a specific function name and parameter list, the corresponding function is called.

2. Promotion and Standard Conversion: If an exact match is not found, C++ performs the following conversions to find the best match:
   - Char, unsigned char, and short are promoted to an int.
   - Float is promoted to double.
   - C++ tries to find a match through standard conversions, such as converting between different numeric types, applying user-defined conversions, and so on.

3. No Match: If no exact match or promotion/standard conversion match is found, a compilation error occurs indicating that no matching function is found.

These rules ensure that the correct overloaded function is called based on the provided arguments, allowing for flexibility in handling different types and numbers of parameters. If no matching function is found, a compilation error is generated.
