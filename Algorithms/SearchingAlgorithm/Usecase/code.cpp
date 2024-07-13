// Here is an example of a binary search algorithm in C++ that searches for a number in a sorted array:

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        // If element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }
        // If element is smaller than mid, search left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }
        // If element is larger than mid, search right subarray
        return binarySearch(arr, mid + 1, right, x);
    }
    // If element is not present in array
    return -1;
}

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
/* This program uses a binary search algorithm to search for a given number in a sorted array. The binarySearch function 
takes an array, the left and right indices of the subarray to search, and the number to search for. It repeatedly divides 
the search space in half by calculating the middle index, and checks if the middle element is the desired element. If it 
is, the function returns the index. If it is smaller than the desired element, the function calls itself on the right half
of the subarray. If it is larger, the function calls itself on the left half of the subarray. The function continues to 
divide the subarray in half until the element is found or the subarray is empty. The main function initializes a sorted 
array and takes input for the number to search for. It calls the binarySearch function on the entire array and prints 
the index of the element if it is found, or a message indicating it is not found.
*/
