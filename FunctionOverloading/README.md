## Function Overloading in C++

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

```
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
   
```
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
   
```
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
## How Function Overloading Works

Function overloading in C++ operates based on the following rules:

1. Exact Match: When a function call exactly matches a specific function name and parameter list, the corresponding function is called.

2. Promotion and Standard Conversion: If an exact match is not found, C++ performs the following conversions to find the best match:
   - Char, unsigned char, and short are promoted to an int.
   - Float is promoted to double.
   - C++ tries to find a match through standard conversions, such as converting between different numeric types, applying user-defined conversions, and so on.

3. No Match: If no exact match or promotion/standard conversion match is found, a compilation error occurs indicating that no matching function is found.

These rules ensure that the correct overloaded function is called based on the provided arguments, allowing for flexibility in handling different types and numbers of parameters. If no matching function is found, a compilation error is generated.
