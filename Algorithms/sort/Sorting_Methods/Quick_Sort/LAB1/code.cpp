#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Sorting methods for QuickSort.
 */
enum class SortMethod {
    Standard, ///< Uses the first element as the pivot.
    Random    ///< Uses a randomly chosen pivot.
};

/**
 * @class QuickSort
 * @brief Implements Quick Sort with standard and randomized pivot strategies.
 */
class QuickSort {
public:
    /**
     * @brief Sorts a vector of integers using Quick Sort.
     *
     * @param nums   The array to be sorted.
     * @param low    The starting index.
     * @param high   The ending index.
     * @param method The pivot selection strategy.
     */
    static void quickSort(vector<int>& nums, int low, int high,
                          SortMethod method) {
        if (low >= high)
            return;
        int pivot;
        if (method == SortMethod::Standard) {
            pivot = partitionArray(nums, low, high);
        } else {
            swap(nums[low + rand() % (high - low + 1)],
                 nums[low]); ///< Random pivot selection
            pivot = partitionArray(nums, low, high);
        }
        quickSort(nums, low, pivot, method); ///< Recursively sort left subarray
        quickSort(nums, pivot + 1, high,
                  method); ///< Recursively sort right subarray
    }

private:
    /**
     * @brief Partitions the array around a pivot.
     *
     * Elements less than the pivot go to the left,
     * and elements greater than or equal go to the right.
     *
     * @param nums The array to partition.
     * @param low  The starting index.
     * @param high The ending index.
     * @return int The final pivot position.
     */
    static int partitionArray(vector<int>& nums, int low, int high) {
        if (low >= high)
            return -1;
        int pivot = low, l = pivot + 1, r = high;
        while (l <= r) {
            if (nums[l] < nums[pivot])
                l++;
            else if (nums[r] >= nums[pivot])
                r--;
            else
                swap(nums[l], nums[r]);
        }
        swap(nums[pivot], nums[r]);
        return r;
    }
};

/**
 * @brief Demonstrates QuickSort using both Standard and Randomized methods.
 */
int main() {
    // Test standard quick sort
    vector<int> nums1 = {3, 2, 5, 1, 6, 4};
    QuickSort::quickSort(nums1, 0, nums1.size() - 1, SortMethod::Standard);
    cout << "Standard sorted array: { ";
    for (int num : nums1)
        cout << num << " ";
    cout << "}" << endl;

    // Test randomized quick sort
    vector<int> nums2 = {3, 2, 5, 1, 6, 4};
    QuickSort::quickSort(nums2, 0, nums2.size() - 1, SortMethod::Random);
    cout << "Randomised sorted array: {";
    for (int num : nums2)
        cout << num << " ";
    cout << "}" << endl;

    system("pause");
    return 0;
}
