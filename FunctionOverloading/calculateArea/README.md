## Function Overloading Example

The given [code](./code.cpp) demonstrates the use of function overloading in C++. In this code, two functions with the same name `calculateArea` are defined but with different parameter lists. This is an example of function overloading, where the function name is the same but the parameters are different.

### Function Definitions
1. `calculateArea(double sideLength)`: Calculates the area of a square using the formula `sideLength * sideLength`.
2. `calculateArea(double length, double width)`: Calculates the area of a rectangle using the formula `length * width`.

### Main Function
In the `main` function, the `calculateArea` function is called twice with different sets of arguments, and the appropriate overloaded version of the function is invoked based on the number of parameters provided.

The output will display the area of the square and the area of the rectangle.
