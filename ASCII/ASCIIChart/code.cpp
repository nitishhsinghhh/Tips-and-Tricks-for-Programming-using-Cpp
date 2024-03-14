// Author: Nitish Singh
// Date: March 14, 2024
// Description: This C++ program prints the printable ASCII characters in the range of 32 to 126.
// Each character is followed by a space, except when it's the last character in a group of 32, in which case a newline is printed.

#include <iostream>

int main() {
    // Print message indicating the range of printable ASCII characters
    std::cout << "Printable ASCII [32..126]:\n";

    // Loop through the ASCII characters in the specified range and print them
    for (char c{' '}; c <= '~'; ++c)
        std::cout << c << ((c + 1) % 32 ? ' ' : '\n');

    // Print a newline character to complete the output
    std::cout << '\n';
}
