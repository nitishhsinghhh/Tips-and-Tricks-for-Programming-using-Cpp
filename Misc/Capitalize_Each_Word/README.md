# Problem Statement
Given a string s consisting only of lowercase English letters (a–z) and single spaces between words, convert the string so that the first character of each word is uppercase. All other characters remain unchanged.

## Notes

  - The string does not have leading or trailing spaces.
  - Words are separated by exactly one space.
  - After every space, there is always a letter.
  - You may modify the string in-place and return it.

  ## Constraints (what to consider)

- 1 <= s.length <= 10^5
- s[i] ∈ {'a'..'z', ' '}
- No leading or trailing spaces.
- No consecutive spaces.
- After each ' ' there is a lowercase letter.

Under these constraints, the simple ASCII transformation is safe:
'a'..'z' → uppercase via ch = ch - 'a' + 'A'

## Examples
- Example 1
    - Input:  "my name is mohit"
    - Output: "My Name Is Mohit"

- Example 2
  - Input:  "hello world this is test"
  - Output: "Hello World This Is Test"

- Example 3
  - Input:  "a b c d e f"
  - Output: "A B C D E F"

  ## Approach

- If the first character is a lowercase letter, uppercase it.
- For each position i, if s[i] == ' ', then uppercase s[i+1] (guaranteed to be a lowercase letter by constraints).
- Time Complexity: O(n)
- Space Complexity: O(1) (in-place)

##  Edge Cases (within given constraints)

- Single word: "my" → "My"
- Single character: "a" → "A"
- Many short words: "aa aa aa aa" → "Aa Aa Aa Aa"

If constraints are ever relaxed (e.g., multiple spaces, digits/punctuation), guard conversions using std::islower before uppercasing the next character.

##  C++ Solution
```c++ []
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cctype>

std::string capitalizeEachWord(std::string& str) {
    if (str.empty())
        return str;

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 'a' + 'A';

    for (int i = 0; i < (int)str.size() - 1; i++) {
        if (str[i] == ' ')
            str[i + 1] = str[i + 1] - 'a' + 'A';
    }
    return str;
}

bool is_valid_input(const std::string& s) {
    if (s.empty()) return false;
    if (s.front() == ' ' || s.back() == ' ') return false;

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == ' ') {
            // space cannot be followed by space or end
            if (i + 1 >= s.size()) return false;
            if (s[i + 1] == ' ') return false;
            if (!(s[i + 1] >= 'a' && s[i + 1] <= 'z')) return false;
        } else {
            if (!(c >= 'a' && c <= 'z')) return false;
        }
    }
    return true;
}

void expect_eq(const std::string& input, const std::string& expected) {
    assert(is_valid_input(input) && "Input does not meet the specified constraints!");

    std::string s = input;
    std::string out = capitalizeEachWord(s);
    std::cout << "IN : [" << input    << "]\n"
              << "OUT: [" << out      << "]\n"
              << "EXP: [" << expected << "]\n"
              << "----\n";
    assert(out == expected && "Output did not match expected result!");
}

int main() {
    std::cout << "Testing implementation under constrained valid inputs...\n";

    // Valid cases per constraints
    expect_eq("a", "A");                            // single letter
    expect_eq("m", "M");                            // single letter different
    expect_eq("my", "My");                          // one word
    expect_eq("my name", "My Name");                // two words
    expect_eq("my name is mohit", "My Name Is Mohit");
    expect_eq("hello world this is test", "Hello World This Is Test");
    expect_eq("abcdefghijklmnopqrstuvwxyz", "Abcdefghijklmnopqrstuvwxyz");
    expect_eq("a b c d e f", "A B C D E F");
    expect_eq("aa aa aa aa aa", "Aa Aa Aa Aa Aa");

    std::cout << "All asserts passed for constrained valid inputs!\n";
    return 0;
}
```
