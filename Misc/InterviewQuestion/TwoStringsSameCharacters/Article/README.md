# Article: Checking if Two Strings Have the Same Characters Using OOP in C++

## Introduction
In software development, string manipulation is a frequent task, especially when dealing with problems like anagram detection. One common problem is to determine if two strings consist of the same characters, regardless of their order. In this article, we will solve this problem using an Object-Oriented Programming (OOP) approach in C++. We will break down the implementation into header files, source files, and the main file to demonstrate good coding practices and modular design.

## Problem Statement
Given two strings, the task is to check if they are composed of the same characters with the same frequency. For example, the strings "listen" and "silent" should be considered equivalent because they contain the same characters in the same quantities.

## Approach
To solve this problem efficiently using OOP, we will create a class called StringCharacterComparer. This class will encapsulate the functionality needed to compare the two strings. The class will be split into a header file (.h), a source file (.cpp), and we will demonstrate its usage in the main.cpp file.

### Header File (StringCharacterComparer.h)
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

class StringCharacterComparer {
public:
    StringCharacterComparer(std::string s1, std::string s2) : str1(s1), str2(s2) {}
    bool haveSameCharacters();
private:
    std::string str1;
    std::string str2;
};
```
### Source File (StringCharacterComparer.cpp)
```cpp
#include "StringCharacterComparer.h"

bool StringCharacterComparer::haveSameCharacters() {
    // Edge cases
    if (str1.length() != str2.length())
        return false;

    std::unordered_map<char, int> charCount;
    for (char ch : str1) 
        charCount[ch]++;
    for (char ch : str2)
        charCount[ch]--;

    for (const auto& pair : charCount) 
        if (pair.second != 0) 
            return false;

    return true;
}
```
### Main File (main.cpp)
```cpp
#include "StringCharacterComparer.h"
#include <iostream>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "eHllo";

    StringCharacterComparer comparer(str1, str2);

    if (comparer.haveSameCharacters()) 
        std::cout << "The strings have the exact same characters." << std::endl;
    else 
        std::cout << "The strings do not have the exact same characters." << std::endl;

    return 0;
}
```

### Explanation
#### Header File
In the header file, we define the StringCharacterComparer class. This class has a constructor that takes two strings as parameters and a public method haveSameCharacters that performs the comparison.

### Source File
In the source file, we implement the haveSameCharacters method. Here's how it works:
1. Length Check: The method starts by checking if the lengths of the two strings are the same. If not, it immediately returns false, as they cannot have the same characters.
2. Character Counting: We use a single std::unordered_map called charCount to count the frequency of each character in str1. For each character in str1, we increment its count in the map.
3. Character Decrementing: For each character in str2, we decrement its count in the map. If both strings have the same characters in the same quantities, all counts in the map should be zero after this step.
4. Validation: We iterate through the map to check if all counts are zero. If any count is not zero, the method returns false; otherwise, it returns true.











