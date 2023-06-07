#include <iostream>

// Function to modify a variable passed by value
void modifyByValue(int num) {
    num = 42;
}

// Function to modify a variable passed by reference
void modifyByReference(int& num) {
    num = 42;
}

int main() {
    int number = 7;

    // Pass 'number' by value
    modifyByValue(number);
    std::cout << "Value after modifyByValue: " << number << std::endl; // Output: 7

    // Pass 'number' by reference
    modifyByReference(number);
    std::cout << "Value after modifyByReference: " << number << std::endl; // Output: 42

    return 0;
}
