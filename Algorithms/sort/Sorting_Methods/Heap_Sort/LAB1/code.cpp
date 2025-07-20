#include <iostream>
#include <vector>

/**
 * @brief Class implementing Heap Sort algorithm.
 */
class HeapSort {
public:
    /**
     * @brief Adjusts the heap downwards from a given root index.
     * 
     * @param nums The array representing the heap.
     * @param size The number of elements in the heap.
     * @param rootInd The index from where to start heapifying down.
     * @param isMin Set true for min-heap, false for max-heap (default).
     */
    static void heapifyDown(std::vector<int> &nums, int size, int rootInd, bool isMin = false) {
        if (size <= 1 || rootInd < 0 || rootInd >= size - 1) 
            return;

        int keyInd = rootInd;
        int leftChildInd = 2 * rootInd + 1;
        int rightChildInd = 2 * rootInd + 2;

        if (leftChildInd < size && (isMin ? nums[leftChildInd] < nums[keyInd] : nums[leftChildInd] > nums[keyInd]))
            keyInd = leftChildInd;

        if (rightChildInd < size && (isMin ? nums[rightChildInd] < nums[keyInd] : nums[rightChildInd] > nums[keyInd]))
            keyInd = rightChildInd;

        if (nums[keyInd] != nums[rootInd]) {
            std::swap(nums[rootInd], nums[keyInd]);
            heapifyDown(nums, size, keyInd, isMin);
        }
    }

    /**
     * @brief Builds a heap from an unsorted array.
     * 
     * @param nums The array to be transformed into a heap.
     * @param isMin Set true to build a min-heap, false for max-heap (default).
     */
    static void heapifyArray(std::vector<int> &nums, bool isMin = false) {
        int size = nums.size();
        if (size <= 1) 
            return;

        int tailRootInd = (size >> 1) - 1;
        for (int rootInd = tailRootInd; rootInd >= 0; rootInd--)
            heapifyDown(nums, size, rootInd, isMin);
    }

    /**
     * @brief Sorts the given array using Heap Sort.
     * 
     * @param nums The array to be sorted in ascending order.
     */
    static void heapSort(std::vector<int> &nums) {
        if (nums.size() <= 1) 
            return;

        heapifyArray(nums);
        for (int size = nums.size() - 1; size; size--) {
            std::swap(nums[size], nums[0]);
            heapifyDown(nums, size, 0);
        }
    }
};

/**
 * @brief Main function to demonstrate heap sort.
 * 
 * @return int Exit status code.
 */
int main() {
    std::vector<int> nums = { 4, 2, 9, 6, 5, 1, 3, 7, 8 };
    HeapSort::heapSort(nums);

    std::cout << "Heap Sort: { ";
    for (int num : nums) 
        std::cout << num << " ";
    std::cout << "}" << std::endl;

    return 0;
}
