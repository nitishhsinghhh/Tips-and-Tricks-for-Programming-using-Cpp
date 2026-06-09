/**
 * @file complex.cpp
 * @brief Implementation of a Complex number class with operator overloading.
 */

#include <iostream>
#include <cmath>

/**
 * @class Complex
 * @brief A class to represent and perform arithmetic on complex numbers.
 */
class Complex {
private:
    double real; ///< Real part of the complex number
    double imag; ///< Imaginary part of the complex number

public:
    /**
     * @brief Construct a new Complex object.
     * @param r Real part (defaults to 0).
     * @param i Imaginary part (defaults to 0).
     */
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    /**
     * @brief Overloads the + operator to add two complex numbers.
     * @param other The complex number to add to the current object.
     * @return A new Complex object representing the sum.
     */
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    /**
     * @brief Overloads the << operator to print the complex number.
     * @param os The output stream.
     * @param c The complex number to output.
     * @return The output stream with the complex number formatted.
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
        return os;
    }
};

/**
 * @brief Entry point of the program. 
 * Demonstrates the addition of two complex numbers and prints the result.
 */
int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    Complex result = c1 + c2;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "Sum: " << result << std::endl;

    return 0;
}