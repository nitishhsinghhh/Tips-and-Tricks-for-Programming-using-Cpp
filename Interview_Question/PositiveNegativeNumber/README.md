### A C++ Program to Check Whether a Number is a Positive or Negative Number

```cpp
#include <iostream>

/**
 * @brief Main function to check if a number is positive or negative.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    int number = -100;

    if (number < 0)
        std::cout << "The given number is negative." << std::endl;
    else
        std::cout << "The given number is positive." << std::endl;

    return 0;
}
```

### Let's improve on this by taking the input from the user
```cpp
#include <iostream>

/**
 * @brief Main function to check if a number is positive or negative.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    int number;
    std::cout << "Please give the number to be tested." << std::endl;
    std::cin >> number;

    if (number < 0)
        std::cout << "The given number is negative." << std::endl;
    else
        std::cout << "The given number is positive." << std::endl;

    return 0;
}
```

### Lets say we also want to test for cases when we have to check if it is odd or even also
```cpp
#include <iostream>
#include <string>

/**
 * @brief Main function to check if a number is even or odd and positive or negative.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    int number;
    std::cout << "Please give the number to be tested." << std::endl;
    std::cin >> number;

    std::string boolVal = (number % 2 == 0) ? "even" : "odd";

    if (number < 0)
        std::cout << "The given number is negative and is " << boolVal << " number." << std::endl;
    else
        std::cout << "The given number is positive and is " << boolVal << " number." << std::endl;

    return 0;
}
```
### Let's further imrpove upon this
```cpp
#include <iostream>
#include <string>

/**
 * @brief Main function to check if a number is positive/negative and even/odd.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    int number;
    std::cout << "Please give the number to be tested." << std::endl;
    std::cin >> number;

    std::string res;

    if (number < 0)
        res.append("The given number is negative and is ");
    else
        res.append("The given number is positive and is ");

    res.append((number % 2 == 0) ? "even." : "odd.");

    std::cout << res << std::endl;

    return 0;
}
```

#### Findings from the last program
1. The [append](https://en.cppreference.com/w/cpp/string/basic_string/append) function in C++ is a member function of the std::string class that is used to concatenate (append) a string or a part of a string to the end of another string. This function is commonly used to combine two strings together.
2. The ?: operator in C++ is known as the ternary conditional operator. It is a shorthand way of writing an if-else statement in a single line. The ternary operator takes three operands: a condition, a value to be returned if the condition is true, and a value to be returned if the condition is false.

### To return a value using the ternary conditional operator in C++, we  can simply use the operator within the return statement. Here is an example demonstrating how to return a value using the ternary operator:
```cpp
#include <iostream>
#include <string>

/**
 * @brief Determines if a number is even or odd.
 * 
 * @param num The integer number to check.
 * @return std::string "Even" if the number is even, otherwise "Odd".
 */
std::string checkEvenOdd(int num) {
    return (num % 2 == 0) ? "Even" : "Odd";
}

int main() {
    int number = 7;

    // Call the function and return the result using the ternary operator
    std::string result = checkEvenOdd(number);

    std::cout << "The number " << number << " is " << result << "." << std::endl;

    return 0;
}
```

### Let's imrpove upon it by taking input from the user
```cpp
#include <iostream>
#include <string>

/**
 * @brief Determines if a number is even or odd.
 * 
 * @param num The integer number to check.
 * @return std::string "Even" if the number is even, otherwise "Odd".
 */
std::string checkEvenOdd(int num) {
    return (num % 2 == 0) ? "Even" : "Odd";
}

/**
 * @brief Main function to take user input and display whether the number is even or odd.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    int number;

    std::cout << "Please enter the number: ";
    std::cin >> number;

    std::string result = checkEvenOdd(number);

    std::cout << "The number " << number << " is " << result << "." << std::endl;

    return 0;
}
```
- Let's include OOP
```cpp
#include <iostream>
#include <string>

/**
 * @class Solution
 * @brief A class to determine if a number is even or odd.
 */
class Solution {
public:
    /**
     * @brief Constructor to initialize the number.
     * @param num The integer number to be checked.
     */
    Solution(int num) : _num(num) {}

    /**
     * @brief Checks whether the number is even or odd.
     * @return A string "Even" if the number is even, otherwise "Odd".
     */
    std::string checkEvenOdd() {
        return (_num % 2 == 0) ? "Even" : "Odd";
    }

private:
    int _num;  ///< The number to be checked.
};

/**
 * @brief Main function to take user input and display whether the number is even or odd.
 * @return 0 on successful execution.
 */
int main() {
    int number;

    std::cout << "Please enter the number: ";
    std::cin >> number;

    Solution oSolution(number);
    std::string result = oSolution.checkEvenOdd();

    std::cout << "The number " << number << " is " << result << "." << std::endl;

    return 0;
}
```
### Using Copy Constructor
```cpp
#include <iostream>
#include <string>

/**
 * @class Solution
 * @brief A class to determine if a number is even or odd.
 */
class Solution {
public:
    /**
     * @brief Constructor to initialize the number.
     * @param num The integer to be evaluated.
     */
    Solution(const int& num) : _num(num) {}

    /**
     * @brief Copy constructor.
     * @param other Another Solution object to copy from.
     */
    Solution(const Solution& other) : _num(other._num) {}

    /**
     * @brief Checks whether the number is even or odd.
     * @return A string "Even" if the number is even, otherwise "Odd".
     */
    std::string checkEvenOdd() {
        return (_num % 2 == 0) ? "Even" : "Odd";
    }

private:
    int _num; ///< The number to be evaluated.
};

int main() {
    int number;

    std::cout << "Please enter the number: ";
    std::cin >> number;

    Solution oSolution(number);
    Solution oSolution1 = oSolution; // Using the copy constructor

    std::string result = oSolution1.checkEvenOdd();
    std::cout << "The number " << number << " is " << result << "." << std::endl;

    result = oSolution.checkEvenOdd();
    std::cout << "The number " << number << " is " << result << "." << std::endl;

    return 0;
}
```
### Positive, Negative and Even Odd fucntion
```cpp
#include <iostream>
#include <string>

/**
 * @class Solution
 * @brief A class to evaluate properties of an integer such as even/odd and sign.
 */
class Solution {
public:
    /**
     * @brief Constructor to initialize the number.
     * @param num The integer to be evaluated.
     */
    Solution(const int& num) : _num(num) {}

    /**
     * @brief Copy constructor.
     * @param other Another Solution object to copy from.
     */
    Solution(const Solution& other) : _num(other._num) {}

    /**
     * @brief Checks whether the number is even or odd.
     * @return A string "Even" if the number is even, otherwise "Odd".
     */
    std::string checkEvenOdd() {
        return (_num % 2 == 0) ? "Even" : "Odd";
    }

    /**
     * @brief Determines if the number is positive, negative, or zero.
     * @return A string "Positive", "Negative", or "Zero" based on the number's value.
     */
    std::string checkPositiveNegativeZero() {
        if (_num > 0)
            return "Positive";
        else if (_num < 0)
            return "Negative";
        else
            return "Zero";
    }

private:
    int _num; ///< The number to be evaluated.
};

int main() {
    int number;

    std::cout << "Please enter the number." << std::endl;
    std::cin >> number;

    Solution oSolution(number);
    Solution oSolution1 = oSolution; // Using the copy constructor

    std::string result = oSolution1.checkEvenOdd();
    std::cout << "The number " << number << " is " << result << "." << std::endl;

    result = oSolution.checkEvenOdd();
    std::cout << "The number " << number << " is " << result << "." << std::endl;

    std::string posNegZero = oSolution.checkPositiveNegativeZero();
    std::cout << "The number " << number << " is " << posNegZero << "." << std::endl;

    return 0;
}
```
