# Reverse Each Word in a Sentence (C++ Implementation)

## Problem Statement

Given a string consisting of words separated by spaces, reverse each word **individually**, keeping the original word order intact.

### Example

**Input:** "My name is Nitishi"
**Output:** "yM eman si hsitiN"

Each word has been reversed, but the order of the words remains unchanged.

---

## Solution Approach

We approach the problem using two distinct paradigms depending on the constraints:

- String Tokenization & Construction: Extracting word blocks, mutating them, and compiling a clean output stream.
- In-place Raw Pointer Manipulation: Iterating directly through a continuous memory buffer to swap characters between boundaries without allocating extra space.

### Step-by-Step Algorithm (In-Place Tracking)

1. Track the start boundary of a word using a pointer or index (start = 0).
2. Move through the character sequence index by index.
3. When hitting a space character (' ') or the null terminator ('\0'):
    - Calculate the end boundary of the current active word slice.
    - Invoke a two-pointer swapping strategy to reverse characters between start and end.
    - Fast-forward the start marker to the index immediately following the space.

---

## C++ Concepts Used

### 1. std::string

Used for managed string handling. It handles contiguous memory allocation internally, preventing raw pointer overruns while providing simple concatenation operators (+=).

### 2. Range-based for loop

Simplifies read-only sequence traversal over iterable STL containers without maintaining manual index math.

```cpp
for (char c : s)
```

### 3. Pass-by-reference

Prevents expensive heap copies of the string object by providing an alias to the original caller's data payload.

```cpp
string& s
```

### 4. In-place reversal using std::swap

Exchanges values of two memory slots directly, enabling linear mutation without tracking additional allocation tables.

```cpp
std::swap(s[i], s[size - i - 1]);
```

---

## Functions Explained

### string swapWords(string& s)

- Mutates a discrete string word in-place using a symmetric two-pointer strategy.
- Steps inward from both boundaries simultaneously to exchange characters up to the center pivot point.

### string swapWordByWord(string& s)

- Traverses the entire sentence character by character.
- Accumulates standard characters into a buffer, identifies word separations via space boundaries, handles processing of the terminal word token, and builds the returned sentence.

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

```Plaintext
yM eman si hsitiN
```

## Complexity Analysis

- Time Complexity: O(N), where N is the total number of characters in the string. Every position is verified sequentially, and character swaps run proportional to individual word lengths.
- Space Complexity: O(N) for the standard string implementations due to allocations for tokenized buffers and output states. Drops to O(1) auxiliary space for the raw C-string allocation variant.

## Constraints

- No <string> header or types allowed.
- No std::swap or std::reverse.
- Zero dependency on external runtime standard libraries except basic output streaming (<iostream>).

```cpp
#include <iostream>

/**
 * @brief Reverses a word in-place between indices [start, end] of a char array.
 */
void reverseWord(char* arr, int start, int end) {
    while (start < end) {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief Reverses each word in a sentence stored in a char array.
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

int main() {
    // Stack-allocated mutable character buffer
    char sentence[] = "My name is Nitish";

    reverseEachWord(sentence);

    std::cout << sentence << std::endl;  // Output: yM eman si hsitiN

    return 0;
}
```

---

## Modern C++ Abstraction (Using Standard Streams)

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
        std::reverse(word.begin(), word.end());
        result += word + ' ';
    }

    // Strip trailing delimiter space cleanly
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {
    string sentence = "My name is Nitish";
    string reversed = reverseEachWord(sentence);
    std::cout << reversed << std::endl; // Output: yM eman si hsitiN
    return 0;
}
```
