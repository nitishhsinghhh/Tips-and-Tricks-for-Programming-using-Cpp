// GCC 13.1: C++ 23
#include <iostream>
/**
 * @desc
 * This program prints all printable ASCII characters in the range [32..126].
 * It displays them in a formatted way, printing a newline after every 32 characters.
 *
 * @result
 * Outputs the printable ASCII characters from space (' ') to tilde ('~') to the console.
 */
int main() 
    std::cout << "Printable ASCII [32..126]:\n";

    // Loop through characters from ASCII 32 (' ') to 126 ('~')
    for (char c{ ' ' }; c <= '~'; ++c)
        // Print character followed by a space or newline every 32 characters
        std::cout << c << ((c + 1) % 32 ? ' ' : '\n');
    std::cout << '\n';
}
