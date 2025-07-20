#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Enum to select the type of merge method.
 */
enum MergeMethod {
    Outplace, ///< Uses additional memory for merging.
    Inplace   ///< Merges in-place without extra space.
};

/**
 * @brief Class implementing Merge Sort using both outplace and inplace merging
 * strategies.
 */
class MergeSort {
public:
    /**
     * @brief Recursively sorts the array using merge sort algorithm.
     *
     * @param nums The array of integers to sort.
     * @param low The starting index of the current segment.
     * @param high The ending index of the current segment.
     * @param method Merge method to use (Outplace or Inplace).
     */
    void mergeSort(vector<int>& nums, int low, int high, MergeMethod method) {
        if (low >= high)
            return;

        int mid = (high - low) / 2 + low;

        mergeSort(nums, low, mid, method);
        mergeSort(nums, mid + 1, high, method);

        if (method == Outplace)
            outPlaceMerge(nums, low, mid, high);
        else if (method == Inplace)
            inPlaceMerge(nums, low, mid, high);
    }

private:
    /**
     * @brief Performs outplace merging of two sorted subarrays.
     *
     * @param nums The original array.
     * @param low Start index of the first subarray.
     * @param mid End index of the first subarray.
     * @param high End index of the second subarray.
     */
    void outPlaceMerge(vector<int>& nums, int low, int mid, int high) {
        if (low >= high)
            return;

        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);

        while (l <= mid && r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];

        while (l <= mid)
            sorted[k++] = nums[l++];

        while (r <= high)
            sorted[k++] = nums[r++];

        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }

    /**
     * @brief Performs in-place merging of two sorted subarrays.
     *
     * @param nums The original array.
     * @param low Start index of the first subarray.
     * @param mid End index of the first subarray.
     * @param high End index of the second subarray.
     */
    void inPlaceMerge(vector<int>& nums, int low, int mid, int high) {
        if (low >= high)
            return;

        int l = low, r = mid + 1;

        while (l <= mid && r <= high) {
            if (nums[l] <= nums[r]) {
                l++;
            } else {
                int val = nums[r];
                for (int k = r++; k > l; k--)
                    nums[k] = nums[k - 1];
                nums[l++] = val;
                mid++;
            }
        }
    }
};

/**
 * @brief Main function demonstrating both types of merge sort.
 *
 * @return int Exit status.
 */
int main() {
    MergeSort mergeSort;

    vector<int> nums = {5, 2, 4, 7, 1, 3, 2, 6};
    cout << "Before sorting: {";
    for (int num : nums)
        cout << num << " ";
    cout << "}" << endl;

    mergeSort.mergeSort(nums, 0, nums.size() - 1, Outplace);
    cout << "After outplace merging sort: {";
    for (int num : nums)
        cout << num << " ";
    cout << "}" << endl;

    nums = {5, 2, 4, 7, 1, 3, 2, 6};
    mergeSort.mergeSort(nums, 0, nums.size() - 1, Inplace);
    cout << "After inplace merging sort: {";
    for (int num : nums)
        cout << num << " ";
    cout << "}" << endl;

    system("pause");
    return 0;
}
