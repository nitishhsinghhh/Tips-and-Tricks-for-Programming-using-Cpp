/**
 * @file main.cpp
 * @brief A function to perform quicksort on a range of elements.
 * This function sorts the elements in the range [first, last) using the
 * quicksort algorithm.
 * @author Nitish Singh
 * @date March 26, 2024
 *
 * @tparam ForwardIt The type of the iterator for the range.
 * @param first Iterator to the first element in the range.
 * @param last Iterator to the element past the last element in the range.
 */

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

template <class ForwardIt> void quicksort(ForwardIt first, ForwardIt last) {
    if (first == last)
        return;

    auto pivot = *std::next(first, std::distance(first, last) / 2);
    auto middle1 = std::partition(
        first, last, [pivot](const auto& em) { return em < pivot; });
    auto middle2 = std::partition(
        middle1, last, [pivot](const auto& em) { return !(pivot < em); });

    quicksort(first, middle1);
    quicksort(middle2, last);
}

int main() {
    // Create a vector of integers
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Original vector: ";
    for (int elem : v)
        std::cout << elem << ' ';

    // Partition the vector based on whether the number is even
    auto it =
        std::partition(v.begin(), v.end(), [](int i) { return i % 2 == 0; });

    // Display the partitioned vector
    std::cout << "\nPartitioned vector: ";
    std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "* ";
    std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, " "));

    // Create a forward_list of integers
    std::forward_list<int> fl{1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    std::cout << "\nUnsorted list: ";
    for (int n : fl)
        std::cout << n << ' ';

    // Sort the list using quicksort
    quicksort(std::begin(fl), std::end(fl));
    std::cout << "\nSorted using quicksort: ";
    for (int fi : fl)
        std::cout << fi << ' ';
    std::cout << '\n';
}

/**
 * Original vector: 0 1 2 3 4 5 6 7 8 9
 * Partitioned vector: 0 8 2 6 4 * 5 3 7 1 9
 * Unsorted list: 1 30 -4 3 5 -4 1 6 -8 2 -5 64 1 92
 * Sorted using quicksort: -8 -5 -4 -4 1 1 1 2 3 5 6 30 64 92
 **/
