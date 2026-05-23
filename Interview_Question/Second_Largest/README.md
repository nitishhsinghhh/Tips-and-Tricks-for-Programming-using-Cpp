# Given an integer array, find the second largest distinct element in the array

Example:

```txt
Input:  [10, 5, 20, 8, 15]
Output: 15
```

Constraints:

- Solve efficiently without sorting the entire array.
- Handle duplicate values correctly.

---

## Approach 1 — Sorting

- Idea
Sort the array in descending order and return the second distinct element.

- Complexity
Time: O(N log N)

Space: O(1) or O(N) depending on sort implementation

- Observation
This works, but sorting is unnecessary since we only need the top two values.

---

## Approach 2 — Priority Queue (Heap)

- Idea
Insert elements into a max heap and extract the largest values.

- Complexity
Time: O(N log N)

- Space: O(N)

Discussion
A heap-based solution demonstrates familiarity with STL data structures like:

```Cpp
std::priority_queue<int>
```

However, it introduces unnecessary overhead for this problem because we only need two values.

This approach becomes more useful in:

- streaming systems,
- Top-K problems,
- continuously changing datasets,
- large-scale distributed processing.

---

## Optimal Approach — Single Pass Linear Scan

Idea
Maintain:

- largest
- secondLargest

Update both values during a single traversal.

**Why This Is Optimal**
We only need relative comparisons, not full ordering.

This avoids:

- sorting cost,
- heap allocations,
- extra memory overhead.

Complexity

- Time: O(N)
- Space: O(1)

### C++ Soluton

```Cpp
#include <iostream>
#include <vector>
#include <limits>

int findSecondLargest(const std::vector<int>& nums)
{
    int largest = std::numeric_limits<int>::min();
    int secondLargest = std::numeric_limits<int>::min();

    for (int num : nums)
    {
        if (num > largest)
        {
            secondLargest = largest;
            largest = num;
        }
        else if (num > secondLargest && num != largest)
        {
            secondLargest = num;
        }
    }

    return secondLargest;
}

int main()
{
    std::vector<int> nums = {10, 5, 20, 8, 15};

    std::cout << findSecondLargest(nums);

    return 0;
}
```

---

## Edge Cases Considered

Duplicate Elements

```txt
{5, 5, 5}
```

Need clarification whether:

- second largest distinct value exists,
- or duplicate values are allowed.

Negative Numbers

```txt
{-10, -20, -5}
```

Handled correctly using:

```cpp
std::numeric_limits<int>::min()
```

Small Arrays

```txt
{7}
```

Should validate input size before processing.

---

## Interview Discussion

During the interview, I explored multiple approaches:

1. Sorting-based solution
2. Heap / Priority Queue solution
3. Optimized linear scan solution

I explained tradeoffs between:

- computational complexity,
- memory usage,
- STL abstraction overhead,
- scalability considerations.

The final implementation used a deterministic O(N) single-pass scan with constant auxiliary space.
