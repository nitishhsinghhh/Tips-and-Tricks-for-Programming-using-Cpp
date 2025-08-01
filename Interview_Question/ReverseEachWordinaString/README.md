# Reverse Each Word in a Sentence (C++ Implementation)

## Problem Statement

Given a string consisting of words separated by spaces, reverse each word **individually**, keeping the original word order intact.

### Example

**Input:** "My name is Nitish"

Each word has been reversed, but the order of the words remains unchanged.

---

## Solution Approach

We approach the problem in two main steps:

1. **Break the input string into words** by identifying spaces.
2. **Reverse each word individually** using a helper function.

We then rebuild the sentence using the reversed words, preserving the original word order.

### Step-by-Step Algorithm:

1. Iterate through each character in the input string.
2. Use a temporary string (`tmp`) to accumulate characters of the current word.
3. When a space `' '` is encountered:
   - Reverse the accumulated word using a helper function.
   - Append the reversed word and a space to the result string.
   - Clear the temporary word holder.
4. After the loop, process the last word (which won’t be followed by a space).
5. Return the final result string.

---

## C++ Concepts Used

### 1. std::string
- Used for efficient string handling.
- Supports indexing, concatenation, and dynamic sizing.

### 2. Range-based for loop
```cpp
for (char c : s)
```

Simplifies iteration over containers like std::string.
### 3. Pass-by-reference
```cpp
string& s
```
Avoids unnecessary copying of strings, improving performance.
### 4. In-place reversal using std::swap
```cpp
std::swap(s[i], s[size - i - 1]);
```
Efficiently reverses the string without extra space.
### 5. String concatenation
```cpp
res += swapWords(tmp);
res += ' ';
```
Builds the final output one word at a time.

## Functions Explained

### string swapWords(string& s)
-  Reverses a string in-place using two-pointer technique.
-  Swaps characters from both ends moving toward the center.
### string swapWordByWord(string& s)
- Processes the sentence word by word.
- Reverses each word individually using swapWords.
- Builds and returns the transformed sentence.

```cpp
#include <iostream>
#include <string>

using std::string;

string swapWords(string& s) {
    int size = s.size();
    for (int i = 0; i < size / 2; i++) {
        std::swap(s[i], s[size - i - 1]);
    }
    return s;
}

string swapWordByWord(string& s) {
    string res = "";
    string tmp = "";
    for (char c : s) {
        if (c != ' ') {
            tmp += c;
        } else {
            res += swapWords(tmp);
            res += ' ';
            tmp = "";
        }
    }
    res += swapWords(tmp);
    return res;
}

int main() {
    string var = "My name is Nitish";
    string res = swapWordByWord(var);
    std::cout << res << std::endl;
    return 0;
}
```

### Output
```cpp
yM eman si hsitiN
```

## Complexity Analysis

- Time Complexity: O(N), where N is the length of the input string.
  Each character is visited once, and each word is reversed in linear time relative to its length.
- Space Complexity: O(N), due to temporary strings used to construct the result.

## Constraints:

- No <string> (we'll use C-style strings).
- No std::swap.
- No STL at all.
- Only #include <iostream> and raw character arrays.

```cpp
#include <iostream>

using namespace std;

/**
 * @brief Reverses a word in-place between indices [start, end] of a char array.
 */
void reverseWord(char* arr, int start, int end) {
    while (start < end) {
        // Manual swap without std::swap
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief Reverses each word in a sentence stored in a char array.
 *
 * Example: Input  -> "My name is Nitish"
 *          Output -> "yM eman si hsitiN"
 */
void reverseEachWord(char* str) {
    int i = 0, start = 0;

    while (str[i] != '\0') {
        // When space or end of string is found, reverse the word
        if (str[i] == ' ' || str[i + 1] == '\0') {
            int end = (str[i] == ' ') ? i - 1 : i;
            reverseWord(str, start, end);
            start = i + 1;
        }
        i++;
    }
}

/**
 * @brief Main function to demonstrate in-place word-wise reversal.
 */
int main() {
    // Mutable char array (unlike string literals which are const)
    char sentence[] = "My name is Nitish";

    reverseEachWord(sentence);

    cout << sentence << endl;  // Output: yM eman si hsitiN

    return 0;
}
```

## Modern C++ with std::string
```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::string;

string reverseEachWord(const string& input) {
    std::stringstream ss(input);
    string word, result;

    while (ss >> word) {
        reverse(word.begin(), word.end());
        result += word + ' ';
    }

    // Remove trailing space
    if (!result.empty()) result.pop_back();

    return result;
}

int main() {
    string sentence = "My name is Nitish";
    string reversed = reverseEachWord(sentence);
    std::cout << reversed << std::endl; // Output: yM eman si hsitiN
    return 0;
}
```
}
```

