#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @file main.cpp
 * @brief A program to partition a vector of numbers into odd and even numbers.
 * @author Nitish Singh
 * @date March 26, 2024
 *
 * The program takes a vector of integers, partitions it into odd and even
 * numbers using std::partition, and then displays the original numbers, odd
 * numbers, and even numbers.
 */

int main() {
    std::vector<int> numbers{1, 2, 3, 4};

    if (numbers.empty()) {
        std::cout << "Vector is empty. No numbers to process.\n";
        return 0;
    }

    // Partition the vector into odd and even numbers
    const auto oddNumbers =
        std::partition(std::begin(numbers), std::end(numbers),
                       [](const auto& value) { return value % 2 != 0; });   // Lambda function to check if a number is odd.

    // Display original numbers
    std::cout << "Original numbers: ";
    for (const auto& num : numbers) 
        std::cout << num << " ";

    // Display odd numbers
    std::cout << "\nOdd numbers: ";
    if (std::begin(numbers) != oddNumbers)
        for (auto it = std::begin(numbers); it != oddNumbers; ++it) 
            std::cout << *it << " ";
    else 
        std::cout << "None";

    // Display even numbers
    std::cout << "\nEven numbers: ";
    if (oddNumbers != std::end(numbers)) 
        for (auto it = oddNumbers; it != std::end(numbers); ++it) 
            std::cout << *it << " ";
    else 
        std::cout << "None";

    return 0;
}
