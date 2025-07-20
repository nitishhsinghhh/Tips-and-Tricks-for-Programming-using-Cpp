#include <iostream>
#include <vector>

/**
 * @brief Implements bubble sort and array printing functionality.
 */
class Sorter {
public:
    /**
     * @brief Sorts a vector of integers using the bubble sort algorithm.
     *
     * @param numbers Reference to the vector of integers to sort.
     */
    void bubbleSort(std::vector<int>& numbers) {
        int endIndex, currentIndex, size = numbers.size();
        if (size <= 1)
            return;
        for (endIndex = size - 1; endIndex; endIndex--)
            for (currentIndex = 0; currentIndex < endIndex; currentIndex++)
                if (numbers[currentIndex] > numbers[currentIndex + 1])
                    std::swap(numbers[currentIndex], numbers[currentIndex + 1]);
    }

    /**
     * @brief Prints the elements of a vector of integers.
     *
     * @param numbers Vector of integers to print.
     */
    void print(std::vector<int> numbers) {
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
    }
};

/**
 * @brief Entry point of the program. Demonstrates bubble sort on a sample
 * array.
 *
 * @return int Exit status code.
 */
int main() {
    Sorter sorter;
    std::vector<int> numbers = {5, 2, 9, 3, 1, 6};

    std::cout << "Unsorted array: ";
    sorter.print(numbers);

    sorter.bubbleSort(numbers);

    std::cout << "Sorted array: ";
    sorter.print(numbers);

    return 0;
}
