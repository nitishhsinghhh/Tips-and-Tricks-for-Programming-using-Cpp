#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * @brief Entry point of the program.
 * 
 * This program demonstrates:
 *  - Lexicographical comparison of strings
 *  - Sorting of a vector of strings
 *  - Generating all permutations of a vector of integers using std::next_permutation
 *  - Outputting sorted and permuted results
 * 
 * @return int Exit status code.
 */
int main() {
    // Compare two strings lexicographically
    std::string str1 = "apple";
    std::string str2 = "banana";
    if (str1 < str2) 
        std::cout << str1 << " comes before " << str2 << std::endl;

    // Create a vector of fruits and sort them alphabetically
    std::vector<std::string> fruits = { "banana", "apple", "cherry" };
    std::sort(fruits.begin(), fruits.end());

    // Create a vector of integers and generate all permutations
    std::vector<int> nums = { 1, 2, 3 };
    do {
        // Process current permutation
        for (int i = 0; i < nums.size(); i++) 
            std::cout << nums[i] << " ";
        std::cout << std::endl;
    } while (std::next_permutation(nums.begin(), nums.end()));

    // Display sorted fruits
    std::cout << "Sorted fruits: ";
    for (int i = 0; i < fruits.size(); i++) 
        std::cout << fruits[i] << " ";
    std::cout << std::endl;

    // Pause execution before exit (Windows specific)
    system("pause");
    return 0;
}

/*
Expected Output:
apple comes before banana
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
Sorted fruits: apple banana cherry 
*/
