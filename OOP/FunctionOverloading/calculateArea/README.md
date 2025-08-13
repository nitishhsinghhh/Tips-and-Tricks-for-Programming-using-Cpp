## Function Overloading Example

The below code demonstrates the use of function overloading in C++. In this code, two functions with the same name `calculateArea` are defined but with different parameter lists. This is an example of function overloading, where the function name is the same but the parameters are different.

### Function Definitions
1. `calculateArea(double sideLength)`: Calculates the area of a square using the formula `sideLength * sideLength`.
2. `calculateArea(double length, double width)`: Calculates the area of a rectangle using the formula `length * width`.

### Main Function
In the `main` function, the `calculateArea` function is called twice with different sets of arguments, and the appropriate overloaded version of the function is invoked based on the number of parameters provided.

The output will display the area of the square and the area of the rectangle.
```cpp
#include <iostream>

/**
 * @brief Calculates the area of a square.
 * This function computes the area of a square given its side length.
 * @param sideLength Length of one side of the square.
 * @return double Area of the square.
 */
double calculateArea(double sideLength) {
    return sideLength * sideLength;
}

/**
 * @brief Calculates the area of a rectangle.
 *
 * This function computes the area of a rectangle given its length and width.
 *
 * @param length Length of the rectangle.
 * @param width Width of the rectangle.
 * @return double Area of the rectangle.
 */
double calculateArea(double length, double width) {
    return length * width;
}

/**
 * @brief Main function to demonstrate function overloading.
 *
 * This program calculates the area of both a square and a rectangle
 * using overloaded versions of the calculateArea() function.
 *
 * @return int Exit status code.
 */
int main() {
    double squareArea = calculateArea(4.0);        
    double rectangleArea = calculateArea(5.0, 3.0);  

    std::cout << "Area of the square: " << squareArea << std::endl;
    std::cout << "Area of the rectangle: " << rectangleArea << std::endl;

    return 0;
}
```
