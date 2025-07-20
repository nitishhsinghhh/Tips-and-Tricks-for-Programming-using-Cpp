#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Class for sorting algorithms.
 */
class Sorting {
public:
    /**
     * @brief Performs Counting Sort on the given vector.
     * 
     * @param nums Vector of integers to sort.
     * @param isAscending If true, sorts in ascending order; otherwise, in descending order.
     */
    static void countingSort(std::vector<int>& nums, bool isAscending = true) {
        // Find the minimum and maximum values in the input array
        int minVal = *std::min_element(nums.begin(), nums.end());
        int maxVal = *std::max_element(nums.begin(), nums.end());

        // Determine the size of the frequency array and allocate memory
        int freqSize = maxVal - minVal + 2; // +1 for range, +1 for indexing
        int size = nums.size();
        std::vector<int> freq(freqSize, 0), sorted(size, 0);

        // Count the frequency of each value in the input array
        for (int ind = 0; ind < size; ind++)
            freq[nums[ind] - minVal]++;

        // Compute prefix/suffix sums based on sorting order
        if (isAscending)
            for (int ind = 1; ind < freqSize; ind++)
                freq[ind] += freq[ind - 1];
        else
            for (int ind = freqSize - 2; ind >= 0; ind--)
                freq[ind] += freq[ind + 1];

        // Sort the input array using the frequency array
        for (int ind = size - 1; ind >= 0; ind--)
            sorted[freq[nums[ind] - minVal]-- - 1] = nums[ind];

        // Copy the sorted values back into the original array
        nums = sorted;
    }
};

/**
 * @brief Main function demonstrating counting sort.
 * 
 * @return int Exit status code.
 */
int main() {
    // Declare an input array and print its initial values
    std::vector<int> nums = { 2, 5, 3, 0, 2, 3, 0, 3 };
    std::cout << "Input array: {";
    for (int num : nums)
        std::cout << num << " ";
    std::cout << "}" << std::endl;

    // Sort the input array in ascending order and print the sorted values
    Sorting::countingSort(nums);
    std::cout << "Sorted array (ascending): {";
    for (int num : nums)
        std::cout << num << " ";
    std::cout << "}" << std::endl;

    // Sort the input array in descending order and print the sorted values
    Sorting::countingSort(nums, false);
    std::cout << "Sorted array (descending): {";
    for (int num : nums)
        std::cout << num << " ";
    std::cout << "}" << std::endl;

    return 0;
}
