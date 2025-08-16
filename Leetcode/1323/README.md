Why? Because digits on the left (higher place values) contribute more to the overall number than digits on the right. So changing a 6 in the thousands place is far more impactful than changing one in the units place.
# Greedy Approaches to Maximum 69 Number

## Table of Contents

1. [First Thought Process](#1-first-thought-process)  
2. [Natural First Steps](#2-natural-first-steps)  
3. [Why This Is Greedy](#3-why-this-is-greedy)  
4. [Solution](#4-solution)  
  4.1 [Classic String-Based Solution](#41-classic-string-based-solution)  
  4.2 [Compact Trick-Based Solution](#42-compact-trick-based-solution)  
  4.3 [CPP seventeen Compact Version Using find](#43-cpp-seventeen-compact-version-using-find)
  4.4 [Lambda-Based Modular Solution](#44-lambda-based-modular-solution)  
  4.5 [Pure Math-Based Solution](#45-pure-math-based-solution)  
  4.6 [Bit Manipulation](#46-bit-manipulation)  
6. [Interview Perspective](#5-interview-perspective)  
7. [Generalized C++ Solution](#6-generalized-c-solution)  
8. [Support for Bidirectional Transformation](#7-support-for-bidirectional-transformation)  
9. [Suggested Generalizations](#8-suggested-generalizations)
    
# 1. First Thought Process
The moment you read the prompt—“You are given a positive integer consisting only of digits 6 and 9. You can change at most one digit (6 to 9 or 9 to 6) to get the maximum number possible”—your brain immediately goes:
`
"Okay, I need to find the first '6' and flip it to '9'. That should give me the biggest possible number."`

# 2. Natural First Steps
- Convert the number to a string: Makes it easy to inspect and modify each digit.
- Loop through the string: Check each digit one by one.
- Find the first '6': As soon as you see it, change it to '9'.
- Break the loop: Only one change allowed.
- Convert back to integer: Return the modified number.

# 3. Why This Is Greedy:
A greedy algorithm makes the best possible decision at each step without worrying about future consequences. In this case, the greedy insight is:
`To maximize the number, flip the most significant '6' to a '9'.`

# 4. Solution

## 4.1 Classic String-Based Solution
```C++ []
class Solution {
public:
    int maximum69Number(int num) {
        string numberStr = to_string(num);
        for (int digitIndex = 0; digitIndex < numberStr.size(); ++digitIndex) {
            if (numberStr[digitIndex] == '6') {
                numberStr[digitIndex] = '9';
                break;
            }
        }
        return stoi(numberStr);
    }
};
```
Simple, readable, and effective.

Now that we’ve seen the classic approach, let’s explore a more compact trick using inline assignment.

## 4.2 Compact Trick-Based Solution
```C++ []
class Solution {
public:
    int maximum69Number(int& originalNumber) { 
        string numberStr = to_string(originalNumber);
        for (char& digit : numberStr)
            if (digit == '6' && (digit = '9')) break;

        return stoi(numberStr);
    }
};
```
Uses a clever inline assignment inside the if condition.
## 4.3 CPP seventeen Compact Version Using find
```C++ []
class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        if (auto pos = s.find('6'); pos != string::npos)
            s[pos] = '9';
        return stoi(s);
    }
};
// s.find('6') returns the index of the first '6' or string::npos if none is found.
```
Elegant use of inline initializer and find.

## 4.4 Lambda-Based Modular Solution
```C++ []
class Solution {
public:
    int maximum69Number(int num) {
        auto change = [](string& s) {
            for (char& c : s)
                if (c == '6')
                    return c = '9', true;
            return false;
        };
        string s = to_string(num);
        change(s);
        return stoi(s);
    }
};
```
Great for modularity and reuse.

## 4.5 Pure Math-Based Solution 
```C++ []
class Solution {
public:
    int maximum69Number(int num) {
        int temp = num, pos = -1, power = 0;
        while (temp) {
            if (temp % 10 == 6)
                pos = power;
            temp /= 10;
            power++;
        }
        return pos == -1 ? num : num + 3 * pow(10, pos);
    }
};
```
This avoids string conversion entirely.

## 4.6 Bit Manipulation 
Bit manipulation isn’t ideal for digit-level operations, but you can still use it for arithmetic optimizations.
```C++ []
class Solution {
public:
    int maximum69Number(int num) {
        int temp = num;
        int pos = -1;
        int i = 0;

        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 6) 
                pos = i;
        
            temp /= 10;
            i++;
        }

        if (pos == -1)
            return num;
            
        int power = 1;
        for (int j = 0; j < pos; j++) 
            power = (power << 3) + (power << 1); 

        return num + 3 * power;
    }
};
```

## Reality Check:
Bit manipulation works best when:

- You're working with binary flags.
- You need to set, clear, or toggle bits.
- You're optimizing for speed or memory.

But digits like '6' and '9' are not directly represented in binary as separate entities. For example:

- 9669 in binary is: 
1001011100101 There's no obvious way to say “this bit pattern represents the digit 6.”

`Whether you go with strings for clarity or math for performance, the key insight is the same: Flip the most significant '6' to a '9'—and do it once.`


# 5. Interview Perspective:

- 5.1 Greedy Algorithm Thinking
    - You’re applying a greedy strategy: change the leftmost '6' to '9' for maximum impact.
    - This shows you understand digit significance — leftmost digits affect the number more than rightmost ones.
- 5.2 String Manipulation
    - You convert the number to a string to easily access and modify digits.
    - Demonstrates comfort with type conversion and string traversal.
- 5.3 Adding maxChanges as a parameter
    - Adding maxChanges as a parameter shows foresight and flexibility. 
    - You’re not hardcoding logic — you’re designing for scalability.

```C++ []
int maximum69Number(int num, int maxChanges = 1) {
    string numberStr = to_string(num);
    int changes = 0;
    for (int digitIndex = 0; digitIndex < numberStr.size(); ++digitIndex) {
        if (numberStr[digitIndex] == '6') {
            numberStr[digitIndex] = '9';
            if (++changes == maxChanges) break;
        }
    }
    return stoi(numberStr);
}
```
[Default Parameter](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/tree/main/OOP/FunctionOverloading#3-important-notes-about-default-parameters-in-overloading): If the caller doesn't provide a value for maxChanges, then use 1 by default.

**Can you think about how the implementation logic changes if the number is negative?**
The idea is to maximize the number if it's positive, minimize it if it's negative, and leave it unchanged if it's zero.


## 6. Generalized C++ Solution
```C++ []
#include <iostream>
#include <string>
#include <cassert>

using std::cout;
using std::endl;

class Solution {
public:
    int transform69Number(int num, int maxChanges = 1) {
        if (num == 0 || maxChanges == 0) return num;

        bool isNegative = num < 0;
        std::string numberStr = std::to_string(abs(num));
        int changes = 0;

        for (int i = 0; i < numberStr.size(); ++i) {
            if (!isNegative && numberStr[i] == '6') {
                numberStr[i] = '9';
                ++changes;
            } else if (isNegative && numberStr[i] == '9') {
                numberStr[i] = '6';
                ++changes;
            }
            if (changes == maxChanges) break; 
        }

        int result = stoi(numberStr);
        return isNegative ? -result : result;
    }
};

int main() {
    Solution sol;

    assert(sol.transform69Number(0) == 0);
    assert(sol.transform69Number(6) == 9);
    assert(sol.transform69Number(9) == 9);
    assert(sol.transform69Number(-6) == -6);
    assert(sol.transform69Number(-9) == -6);
    assert(sol.transform69Number(6699, 2) == 9999);
    assert(sol.transform69Number(-9966, 2) == -6666);
    assert(sol.transform69Number(9999, 5) == 9999);
    assert(sol.transform69Number(6666, 0) == 6666);
    assert(sol.transform69Number(-9999, 0) == -9999);
    assert(sol.transform69Number(696969, 3) == 999999);
    assert(sol.transform69Number(-969696, 3) == -666666);

    cout << "All tests passed successfully!" << endl;
    return 0;
}
```

## 7. Support for Bidirectional Transformation 
Instead of hardcoding '6' → '9' for positive and '9' → '6' for negative, allow the caller to specify: 
- Which digit to change 
- What to change it to
let's build a generalized C++ function that allows the caller these
```C++ []
#include <iostream>
#include <string>
#include <cassert>

using std::cout;
using std::endl;

class Solution {
public:
    int transformDigits(int num, char fromDigit, char toDigit, int maxChanges = 1) {
        if (num == 0 || maxChanges == 0 || fromDigit == toDigit) return num;

        bool isNegative = num < 0;
        std::string numberStr = std::to_string(std::abs(num));
        int changes = 0;

        for (char& digit : numberStr) {
            if (digit == fromDigit) {
                digit = toDigit;
                ++changes;
                if (changes == maxChanges) break;
            }
        }

        int result = std::stoi(numberStr);
        return isNegative ? -result : result;
    }
};

int main() {
    Solution sol;

    // Basic transformations: default
    assert(sol.transformDigits(9669, '6', '9') == 9969);
    assert(sol.transformDigits(9969, '9', '6') == 6969);
    assert(sol.transformDigits(-9669, '9', '6') == -6669);
    assert(sol.transformDigits(-9669, '6', '9') == -9969);

    // Zero and no-change cases
    assert(sol.transformDigits(0, '6', '9') == 0);
    assert(sol.transformDigits(6666, '6', '9', 0) == 6666);
    assert(sol.transformDigits(6666, '6', '6') == 6666); // no-op

    // Multiple changes
    assert(sol.transformDigits(696969, '6', '9', 3) == 999999);
    assert(sol.transformDigits(696969, '6', '9', 2) == 999969);
    assert(sol.transformDigits(696969, '6', '9', 1) == 996969); 
    
    // Negative number with multiple changes
    assert(sol.transformDigits(-969696, '9', '6', 3) == -666666);

    cout << "All generalized tests passed successfully!" << endl;
    return 0;
}
```

## 8. Suggested Generalizations
- Support for Any Base
- Transform All Occurrences
Allow the user to specify whether to transform all matching digits or just up to maxChanges
- Transform by Position
Enable transformations based on digit position
```C++ []
enum class PositionMode { ANY, EVEN_INDEX, ODD_INDEX, LAST_N };
```
- Return Metadata
```C++ []
struct TransformResult {
    int original;
    int transformed;
    int changesMade;
};
```
- Digit Mapping Table
Support bulk transformations using a map:
```C++ []
std::unordered_map<char, char> digitMap = {{'6', '9'}, {'9', '6'}};
```
## C++ Code
```C++ []
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

enum class PositionMode { ANY, EVEN_INDEX, ODD_INDEX, LAST_N };

struct TransformResult {
    std::string original;
    std::string transformed;
    int changesMade;
};

class DigitTransformer {
public:
    // Transform using single digit replacement
    TransformResult transformDigits(int num, char fromDigit, char toDigit,
                                    int maxChanges = -1, int base = 10,
                                    PositionMode mode = PositionMode::ANY,
                                    int lastN = 0) {
        std::string numberStr = std::to_string(std::abs(num));
        std::string originalStr = numberStr;
        int changes = 0;

        int len = numberStr.size();
        for (int i = 0; i < len; ++i) {
            if (!isValidDigit(numberStr[i], base))
                continue;

            if (mode == PositionMode::EVEN_INDEX && i % 2 != 0)
                continue;
            if (mode == PositionMode::ODD_INDEX && i % 2 == 0)
                continue;
            if (mode == PositionMode::LAST_N && i < len - lastN)
                continue;

            if (numberStr[i] == fromDigit) {
                numberStr[i] = toDigit;
                ++changes;
                if (maxChanges != -1 && changes == maxChanges)
                    break;
            }
        }

        if (num < 0)
            numberStr = "-" + numberStr;
        return {(num < 0 ? "-" + originalStr : originalStr), numberStr,
                changes};
    }

    // Transform using a digit map
    TransformResult
    transformWithMap(const std::string& input,
                     const std::unordered_map<char, char>& digitMap,
                     int maxChanges = -1, PositionMode mode = PositionMode::ANY,
                     int lastN = 0) {
        std::string result = input;
        int changes = 0;
        int len = result.size();

        for (int i = 0; i < len; ++i) {
            char& ch = result[i];
            if (!std::isdigit(ch))
                continue;

            if (mode == PositionMode::EVEN_INDEX && i % 2 != 0)
                continue;
            if (mode == PositionMode::ODD_INDEX && i % 2 == 0)
                continue;
            if (mode == PositionMode::LAST_N && i < len - lastN)
                continue;

            auto it = digitMap.find(ch);
            if (it != digitMap.end()) {
                ch = it->second;
                ++changes;
                if (maxChanges != -1 && changes == maxChanges)
                    break;
            }
        }

        return {input, result, changes};
    }

private:
    bool isValidDigit(char ch, int base) {
        if (base <= 10)
            return ch >= '0' && ch < '0' + base;
        return std::isdigit(ch) ||
               (std::tolower(ch) >= 'a' && std::tolower(ch) < 'a' + base - 10);
    }
};
int main() {
    DigitTransformer dt;

    // Basic transformation
    auto res1 = dt.transformDigits(696969, '6', '9', 2);
    assert(res1.transformed == "999969");

    // Transform all occurrences
    auto res2 = dt.transformDigits(696969, '6', '9', -1);
    assert(res2.transformed == "999999");

    // Negative number
    auto res3 = dt.transformDigits(-969696, '9', '6', 3);
    assert(res3.transformed == "-666666");

    // Position-based (only last 2 digits)
    auto res4 =
        dt.transformDigits(696969, '6', '9', -1, 10, PositionMode::LAST_N, 2);
    assert(res4.transformed == "696999");

    // Bulk map transformation
    std::unordered_map<char, char> digitMap = {{'6', '9'}, {'9', '6'}};
    auto res5 = dt.transformWithMap("696969", digitMap, -1);
    assert(res5.transformed == "969696");

    std::cout << "All enhanced tests passed successfully!" << std::endl;
    return 0;
}
```

