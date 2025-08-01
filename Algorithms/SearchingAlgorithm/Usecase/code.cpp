#include <iostream>
using namespace std;

/**
 * @brief Performs binary search on a sorted array to find the target element.
 *
 * This recursive function searches for the element 'x' within the subarray 
 * defined by the indices 'left' and 'right'. If found, it returns the index
 * of the element. If not found, it returns -1.
 *
 * @param arr[] The sorted array to search in.
 * @param left The starting index of the current subarray.
 * @param right The ending index of the current subarray.
 * @param x The target element to search for.
 * @return int The index of the element if found; otherwise, -1.
 */
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if the middle element is the target
        if (arr[mid] == x) {
            return mid;
        }

        // If target is smaller than mid, search the left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }

        // If target is larger than mid, search the right subarray
        return binarySearch(arr, mid + 1, right, x);
    }

    // Element not found
    return -1;
}

/**
 * @brief Main function to demonstrate binary search.
 *
 * Initializes a sorted array and prompts the user to enter a number to search.
 * The binary search is performed using the binarySearch() function.
 * The result is printed to the console.
 *
 * @return int Exit code.
 */
int main() {
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    cout << "Enter a number to search: ";
    cin >> x;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index " << result << "." << endl;
    }

    return 0;
}
