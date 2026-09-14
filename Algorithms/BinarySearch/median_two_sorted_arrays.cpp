/**
 * @file median_two_sorted_arrays.cpp
 * @author Nitish Singh
 * @brief Finds the median of two sorted arrays using binary search.
 *
 * Binary search is performed on the smaller array to find a valid partition.
 *
 * Time Complexity: O(log(min(N, M)))
 * Space Complexity: O(1)
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

/**
 * @brief Finds the median of two sorted arrays.
 *
 * @param first First sorted array.
 * @param second Second sorted array.
 * @return double Median of the combined sorted sequence.
 */
double findMedian(const std::vector<int>& first,
                  const std::vector<int>& second) {
    if (first.size() > second.size()) {
        return findMedian(second, first);
    }

    const int n = static_cast<int>(first.size());
    const int m = static_cast<int>(second.size());

    int left = 0;
    int right = n;

    while (left <= right) {
        const int partitionFirst = left + (right - left) / 2;
        const int partitionSecond =
            (n + m + 1) / 2 - partitionFirst;

        const int leftFirst =
            partitionFirst == 0
                ? INT_MIN
                : first[partitionFirst - 1];

        const int rightFirst =
            partitionFirst == n
                ? INT_MAX
                : first[partitionFirst];

        const int leftSecond =
            partitionSecond == 0
                ? INT_MIN
                : second[partitionSecond - 1];

        const int rightSecond =
            partitionSecond == m
                ? INT_MAX
                : second[partitionSecond];

        if (leftFirst <= rightSecond &&
            leftSecond <= rightFirst) {

            const int leftMax = std::max(
                leftFirst,
                leftSecond
            );

            if ((n + m) % 2 == 1) {
                return leftMax;
            }

            const int rightMin = std::min(
                rightFirst,
                rightSecond
            );

            return (leftMax + rightMin) / 2.0;
        }

        if (leftFirst > rightSecond) {
            right = partitionFirst - 1;
        } else {
            left = partitionFirst + 1;
        }
    }

    return 0.0;
}

/**
 * @brief Demonstrates median search across two sorted arrays.
 *
 * @return int Exit status.
 */
int main() {
    const std::vector<int> first = {1, 3};
    const std::vector<int> second = {2};

    std::cout << "Median: "
              << findMedian(first, second)
              << '\n';

    return 0;
}