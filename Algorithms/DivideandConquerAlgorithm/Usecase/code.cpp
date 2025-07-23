#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Merges two sorted subarrays of arr[].
 * 
 * The first subarray is arr[left..mid], and the second is arr[mid+1..right].
 * This function merges them into a single sorted array.
 * 
 * @param arr  Reference to the array to be sorted.
 * @param left Starting index of the first subarray.
 * @param mid  Ending index of the first subarray.
 * @param right Ending index of the second subarray.
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

/**
 * @brief Sorts an array using the merge sort algorithm.
 * 
 * Recursively divides the array into two halves, sorts them,
 * and then merges the sorted halves.
 * 
 * @param arr Reference to the array to be sorted.
 * @param left Starting index of the portion to sort.
 * @param right Ending index of the portion to sort.
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * @brief Main function to demonstrate merge sort.
 * 
 * Initializes an array of integers, sorts it using mergeSort,
 * and prints the sorted array.
 * 
 * @return int Exit status code.
 */
int main() {
    vector<int> arr = { 7, 5, 3, 9, 2, 8, 4, 1, 6 };
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
