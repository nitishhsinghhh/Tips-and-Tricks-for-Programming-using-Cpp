//Here is an example of a merge sort algorithm in C++ that uses the divide and conquer approach to sort an array:

#include <iostream>
#include <vector>
using namespace std;

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

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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

/* 
This program uses a merge sort algorithm to sort an array of integers. The merge function takes three indices that 
divide the array into two subarrays and merges the subarrays into a sorted array. It creates a temporary array to \
store the sorted elements, compares the elements in the two subarrays, and copies them into the temporary array in sorted 
order. The mergeSort function uses the divide and conquer approach to sort the array. It repeatedly divides the array in 
half until it reaches subarrays of size 1, and then merges the subarrays back together in sorted order using the merge function. 
The main function initializes an array of integers and calls the mergeSort function on the entire array, printing the sorted 
array to the console.
*/

