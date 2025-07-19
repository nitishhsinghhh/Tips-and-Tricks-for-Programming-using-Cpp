# 🧪 Software Testing Methodologies Guide: A High-Level Overview

As a software engineer, writing code is just one part of the job. What's really important is making sure that the code works well, runs efficiently, and doesn't have any bugs. To do this, we need to test the code thoroughly. Testing helps us make sure the program behaves as expected, even when things get tricky.

Now, let's look at the problem we're working on. Imagine you have a list of numbers, and the goal is to make that list strictly increasing. This means each number in the list should be larger than the number before it. For example, in the list `[1, 2, 3]`, each number is larger than the one before it.

Here's the twist: we can only make changes to the numbers by subtracting prime numbers (numbers that are only divisible by 1 and themselves) from them. You can subtract these prime numbers as many times as needed, but the key is to make sure the final list is strictly increasing.

To ensure our solution works properly, we'll go over the different testing techniques. These include **unit testing, edge case testing, performance testing, consistency testing, and integration testing**. Each of these methods is important because they help us verify that the solution performs well, not just in typical scenarios, but also when it's pushed to its limits or faced with unusual inputs.

---

## The Problem: Prime Subtraction for Strictly Increasing Sequences

The problem we're solving involves an array of numbers, and the goal is to make the sequence strictly increasing by subtracting prime numbers from each element. The basic idea is to subtract the largest prime number from each element, but only if it doesn't make the sequence non-increasing.

To solve this efficiently, we will use a sieve algorithm to generate a list of prime numbers. Then, we apply prime subtraction to the array, making sure the sequence becomes strictly increasing, all while keeping the algorithm's time complexity manageable.

### Approach to the Solution

- **Generating Primes**: First, we create a list of all prime numbers up to the largest number in the array using the Sieve of Eratosthenes. This helps us quickly find all the primes we need.
- **Subtracting Primes**: For each number in the array, we calculate how much it needs to change to be smaller than the previous number (or from 0 for the first number). Then, we subtract the largest prime that keeps the sequence strictly increasing.

---

## C++ Implementation

```cpp
class Solution {
public:
    void sieveOfEratosthenes(vector<int>& primes, int maxVal) {
        vector<bool> sieve(maxVal + 1, false);
        for (int i = 2; i * i <= maxVal; ++i) 
            if (!sieve[i]) 
                for (int j = i * i; j <= maxVal; j += i)
                    sieve[j] = true;
        
        for (int i = 2; i <= maxVal; ++i)
            if (!sieve[i])
                primes.push_back(i);
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        int maxVal = *std::max_element(nums.begin(), nums.end());
        sieveOfEratosthenes(primes, maxVal);

        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = i == 0 ? nums[0] - 1 : nums[i] - nums[i - 1] - 1;
            size_t lb = std::lower_bound(primes.begin(), primes.end(), diff) - primes.begin();
  
            if (lb == primes.size() || primes[lb] > diff)
                lb--;

            if (i == 0 || nums[i] > nums[i - 1]) {
                if (lb < primes.size()) {
                    nums[i] -= primes[lb];
                }
            } else 
                return false;
        }
        return true;
    }
};
```

# Testing the Solution: A Comprehensive Approach

As we proceed with testing, we aim to cover a variety of scenarios—from basic functionality to edge cases and performance under load. Here's how we approach it:

---

## 1. Unit Testing: Validating Core Functionality

The first step in ensuring our solution works correctly is unit testing. We need to test individual components of the algorithm. For instance, we begin by testing the Sieve of Eratosthenes function that generates primes.

### 🧪 Test Case: Prime Generation

```cpp
void testSieveOfEratosthenes() {
    Solution sol;
    vector<int> primes;
    sol.sieveOfEratosthenes(primes, 30);
    vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    assert(primes == expected);
    cout << "sieveOfEratosthenes test passed!" << endl;
}
```

## 2. Edge Case Testing: Handling Special Scenarios
No solution is complete without accounting for edge cases. These are situations where the input is either minimal or follows an unusual pattern.

Consider an array with only one element. This is an edge case, but trivially, the solution should always return true since a single element is already in a strictly increasing sequence.

```cpp
void testAdditionalCases() {
    Solution sol;

    vector<int> nums4 = {2};
    assert(sol.primeSubOperation(nums4) == true);
    cout << "primeSubOperation test 4 passed!" << endl;
}
```

## 3. Performance Testing: Scalability Under Load

Performance is another critical area, especially when dealing with large datasets. We need to ensure that our algorithm can handle large input sizes efficiently.

We run a performance test where we have a large array of numbers (100,000 elements). The goal is to measure how long the function takes to process the input and ensure it finishes within an acceptable time frame.

```cpp
void testPerformance() {
    Solution sol;

    vector<int> nums(100000);
    for (int i = 0; i < 100000; ++i) 
        nums[i] = i + 1;

    auto start = high_resolution_clock::now();
    bool result = sol.primeSubOperation(nums);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Performance test result: " << result << endl;
    cout << "Performance test duration: " << duration << " ms" << endl;
}
```

## 4. Consistency Testing: Ensuring Reliability
To ensure our algorithm behaves consistently across multiple executions, we run the function multiple times with the same input and check for consistent outputs.

We test the function's consistency by calling it multiple times with the same input to confirm that it produces the same result each time.

```cpp
void testConsistency() {
    Solution sol;

    vector<int> nums = {4, 9, 6, 10};
    bool firstResult = sol.primeSubOperation(nums);

    for (int i = 0; i < 10; ++i) {
        vector<int> numsCopy = {4, 9, 6, 10};
        bool result = sol.primeSubOperation(numsCopy);
        assert(result == firstResult);
    }

    cout << "Consistency test passed!" << endl;
}
```

## 5. Integration Testing: Ensuring End-to-End Functionality
Lastly, we need to test the entire solution end-to-end to ensure that all components work together seamlessly.

Here, we test different scenarios, such as strictly increasing sequences, arrays with large gaps, and sequences where subtraction doesn't work. These tests simulate real-world cases and help validate the entire process.

```cpp
void testIntegrationCases() {
    Solution sol;

    vector<int> nums6 = {1, 2, 3, 4, 5};
    assert(sol.primeSubOperation(nums6) == true);

    vector<int> nums7 = {10, 20, 30, 40, 50};
    assert(sol.primeSubOperation(nums7) == true);

    vector<int> nums8 = {10, 5, 1};
    assert(sol.primeSubOperation(nums8) == false);

    vector<int> nums9 = {15, 14, 13, 12, 11};
    assert(sol.primeSubOperation(nums9) == true);
}
