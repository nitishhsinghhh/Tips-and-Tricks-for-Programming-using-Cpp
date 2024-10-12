# Checking if Two Strings Have the Same Characters in C++

In this repository, you'll find a solution to the problem of determining whether two strings consist of the same characters, regardless of their order. This is a common problem in technical interviews, often related to anagram detection.

## Problem Statement

Given two strings, we need to check if they are composed of the same characters with the same frequency. For example, the strings `"listen"` and `"silent"` should be considered equivalent because they contain the same characters in the same quantities.

## Approach

To solve this problem efficiently, we can use a hashmap (or `std::unordered_map` in C++) to count the frequency of each character in both strings. The steps to achieve this are as follows:

1. **Length Check**: If the lengths of the two strings are not the same, they cannot have the same characters.
2. **Character Counting**: Use a hashmap to count the frequency of characters in the first string and then decrement the count for the characters in the second string.
3. **Validation**: Verify that all counts in the hashmap are zero. If they are, the strings have the same characters; otherwise, they do not.

## Implementation

Below is the C++ implementation of this approach.

### Code

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

bool haveSameCharacters(const std::string& str1, const std::string& str2) {
    // If the lengths are not the same, the strings can't be made of the same characters
    if (str1.length() != str2.length()) {
        return false;
    }

    // Create a map to count the frequency of each character in the strings
    std::unordered_map<char, int> charCount;

    // Count the characters in the first string
    for (char ch : str1) {
        charCount[ch]++;
    }

    // Decrement the count for the characters in the second string
    for (char ch : str2) {
        charCount[ch]--;
    }

    // Check if all counts are zero
    for (const auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string str1 = "listen";
    std::string str2 = "silent";

    if (haveSameCharacters(str1, str2)) {
        std::cout << "The strings have the exact same characters." << std::endl;
    }
    else {
        std::cout << "The strings do not have the exact same characters." << std::endl;
    }

    return 0;
}
```

### Explanation
1. Length Check: The function starts by checking if the lengths of the two strings are the same. If not, it immediately returns false, as they cannot have the same characters.
2. Character Counting: We use a single std::unordered_map called charCount to count the frequency of each character in str1. For each character in str1, we increment its count in the map.
3. Character Decrementing: For each character in str2, we decrement its count in the map. If both strings have the same characters in the same quantities, all counts in the map should be zero after this step.
4. Validation: We iterate through the map to check if all counts are zero. If any count is not zero, the function returns false; otherwise, it returns true.
