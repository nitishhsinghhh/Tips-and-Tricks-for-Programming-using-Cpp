# Binary Search 
Binary search is an algorithm employed for searching in a sorted array by iteratively dividing the search range in half. The concept behind binary search is to leverage the sorted nature of the array to achieve a time complexity of O(log N).

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/51e0fc30-d69d-44f6-9e14-504b51840de0)

## Conditions for applying the Binary Search algorithm to a data structure:
1. The data structure must be sorted in ascending or descending order.
2. Accessing any element within the data structure must take constant time.

## Binary Search Algorithm:

1. Divide the search space into two halves by finding the middle index "mid".

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/9305617a-84d6-475b-a120-2bf6b4691821)

2. Compare the middle element of the search space with the key:
   A. If the key is found at the middle element, the process is terminated.
   B. If the key is not found at the middle element, choose which half will         be used as the next search space.
      a. If the key is smaller than the middle element, then the left side is          used for the next search.
      b. If the key is larger than the middle element, then the right side is          used for the next search.
3. This process is continued until the key is found or the total search space is exhausted.


