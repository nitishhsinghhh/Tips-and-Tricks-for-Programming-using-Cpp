# Equalize the Array: Problem Explanation and Solution
In this article, we will explore the problem of equalizing an array. We will explain the problem, outline the steps to solve it, and provide a detailed solution using C++ code. The goal is to make all the elements of the array equal with the minimum number of deletions.

## Problem Statement
Given an array of integers, we need to determine the minimum number of deletions required to make all the elements of the array equal. For example, if the array is [3, 3, 2, 1, 3], we can delete the 2 and 1 to make all the elements equal to 3.

## Approach to the Solution
To solve this problem, we can follow these steps:

- Count the Frequency of Each Element:
- Use an unordered map (hash map) to count the frequency of each element in the array.
- Find the Most Frequent Element:
  Determine which element has the highest frequency. This will be the element that we want to keep since it will minimize the number of deletions.
- Calculate the Minimum Deletions:
  The minimum number of deletions required is the total number of elements in the array minus the frequency of the most frequent element.

## Detailed Solution
Let's implement the above approach in C++:
```
int equalizeArray(std::vector<int> arr) {
    std::unordered_map<int, int> mp;
    
    // Count the frequency of each element
    for (auto a : arr) 
        mp[a]++;
    
    // Find the most frequent element
    auto most_frequent = std::max_element(mp.begin(), mp.end(), 
    [] (const std::pair<int, int> & a, const std::pair<int, int> & b) {
        return a.second < b.second; });
    
    // Calculate the minimum deletions required
    return arr.size() - most_frequent->second;
}
```

## Explanation of the Code
- Counting Frequencies:
  We use an unordered map mp to count the frequency of each element in the array. The loop for (auto a : arr) mp[a]++; iterates through the array and increments the count for each element.

- Finding the Most Frequent Element:
  We use the max_element function to find the element with the highest frequency in the map. The lambda function [] (const pair<int, int> & a, const pair<int, int> &b) { return a.second < b.second; } compares the frequencies of elements.

- Calculating Minimum Deletions:
  The minimum deletions required to equalize the array are calculated as arr.size() - most_frequent->second, where most_frequent->second gives the frequency of the most frequent element.

- Main Function:
  The main function handles input and output operations. It reads the array size and elements, calls the equalizeArray function to get the result, and writes the result to the output.

## Conclusion
This solution efficiently calculates the minimum number of deletions required to equalize an array by leveraging frequency counts and finding the most frequent element. The approach ensures that we minimize deletions, making the array elements equal with the least effort.
