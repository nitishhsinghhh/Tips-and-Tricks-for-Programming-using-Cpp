#include <iostream>

// Function to calculate the area of a square
double calculateArea(double sideLength) {
    return sideLength * sideLength;
}

// Function to calculate the area of a rectangle
double calculateArea(double length, double width) {
    return length * width;
}

int main() {
    double squareArea = calculateArea(4.0); // Invokes the first calculateArea() function
    double rectangleArea = calculateArea(5.0, 3.0); // Invokes the second calculateArea() function
    cout << "Area of the square: " << squareArea << endl;
    cout << "Area of the rectangle: " << rectangleArea << endl;
    return 0;
}
