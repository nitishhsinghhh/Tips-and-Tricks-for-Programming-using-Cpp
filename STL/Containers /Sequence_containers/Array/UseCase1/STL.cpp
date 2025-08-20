#include <iostream>
#include <array>
#include <string>
#include <algorithm> // for sort
#include <cstring>   // for memcpy

/**
 * @brief Demonstrates various operations on std::array in C++.
 *
 * This program covers:
 * - Initialization of std::array
 * - Size vs sizeof
 * - Iteration and sorting
 * - fill(), swap(), empty(), at(), front(), back(), data()
 * - Range-based for loops
 */
int main() {
    /// Initializing arrays of different types
    std::array<int, 5> array1{ 3, 4, 5, 1, 2 };
    std::array<int, 5> array2 = { 1, 2, 3, 4, 5 };
    std::array<std::string, 2> array3 = { std::string("a"), "b" };

    /**
     * @note size() or max_size() return the number of elements in the array,
     * while sizeof() gives the total memory size in bytes.
     */
    std::cout << "Sizes of std::arrays are" << std::endl;
    std::cout << array1.size() << std::endl;
    std::cout << array2.size() << std::endl;
    std::cout << array3.size() << std::endl;

    /// Iterating array1 before sorting
    std::cout << "\nInitial array1 : ";
    for (auto i : array1)
        std::cout << i << ' ';

    /**
     * @brief Sorting std::array using std::sort
     * @details Works since std::array provides iterators (begin(), end()).
     */
    sort(array1.begin(), array1.end());

    std::cout << "\nsorted  array1 : ";
    for (auto i : array1)
        std::cout << i << ' ';

    /**
     * @brief fill() function
     * @details Sets all elements of the array to a given value.
     */
    array2.fill(10);
    std::cout << "\nFilled array2 : ";
    for (auto i : array2)
        std::cout << i << ' ';

    /// Range-based for loop supported
    std::cout << "\narray3 : ";
    for (auto &s : array3)
        std::cout << s << ' ';

    /**
     * @brief Accessing elements using operator[]
     */
    std::array<char, 4> array4 = { 'G','H','J','K' };
    std::cout << "\narray4 : ";
    std::cout << array4[0] << " " << array4[2];

    /**
     * @brief front() and back()
     * @note These return the first and last elements of the array.
     */
    std::array<int, 3> array5 = { 'S','D','F' };
    std::cout << "\narray5 : ";
    std::cout << array5.front() << " " << array5.back(); // ASCII values

    /**
     * @brief swap() function
     * @details Swaps elements of two arrays of same type & size.
     */
    std::array<int, 3> array6 = { 'S','D','F' };
    std::array<int, 3> array7 = { 'M','M','P' };
    array6.swap(array7);
    std::cout << "\narray6 : ";
    std::cout << array6.front() << " " << array6.back();

    swap(array6, array7);
    std::cout << "\narray6 : ";
    std::cout << array6.front() << " " << array6.back();

    /**
     * @brief empty()
     * @return true if the array is empty, false otherwise.
     */
    std::array<int, 3> array8 = { 'S','D','F' };
    std::array<int, 3> array9 = { 'M','M','P' };
    std::cout << "\narray8 : ";
    bool x = array8.empty(); // false (not empty)
    std::cout << "array8 : " << (x);

    /**
     * @brief at() function
     * @details Provides bounds-checked access. Throws exception if out of range.
     */
    std::array<int, 3> array10 = { 'S','D','F' };
    std::array<int, 3> array11 = { 'M','M','P' };
    std::cout << "\narray10 : ";
    std::cout << array10.at(2) << " " << array11.at(2);

    /**
     * @brief data() function
     * @details Returns pointer to underlying array. Useful for C APIs.
     */
    const char* str = "HelloWorld";
    std::array<char, 13> array12;
    memcpy(array12.data(), str, 13);
    std::cout << "\narray12 : ";
    std::cout << array12.data() << '\n';

    return 0;
}

/**
 * @example Expected Output:
 * Sizes of std::arrays are
 * 5
 * 5
 * 2
 *
 * Initial array1 : 3 4 5 1 2
 * sorted  array1 : 1 2 3 4 5
 * Filled array2 : 10 10 10 10 10
 * array3 : a b
 * array4 : G J
 * array5 : 83 70
 * array6 : 77 80
 * array6 : 83 70
 * array8 : false
 * array10 : 70 80
 * array12 : HelloWorld
 */
