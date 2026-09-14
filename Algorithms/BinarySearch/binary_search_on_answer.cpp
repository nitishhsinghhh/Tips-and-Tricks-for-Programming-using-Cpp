/**
 * @file binary_search_on_answer.cpp
 * @author Nitish Singh
 * @brief Demonstrates Binary Search on Answer using the Bouquet problem.
 *
 * The search space is the number of days rather than an array index.
 *
 * Time Complexity: O(N log M)
 * where N is the number of flowers and M is the range of possible days.
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

/**
 * @brief Determines whether enough bouquets can be created by a given day.
 *
 * @param bloomDay Blooming day of each flower.
 * @param bouquets Required number of bouquets.
 * @param flowersPerBouquet Flowers required per bouquet.
 * @param day Candidate day.
 * @return true if enough bouquets can be created.
 */
bool canMakeBouquets(const std::vector<int>& bloomDay,
                     int bouquets,
                     int flowersPerBouquet,
                     int day) {
    int consecutiveFlowers = 0;
    int completedBouquets = 0;

    for (const int bloom : bloomDay) {
        if (bloom <= day) {
            ++consecutiveFlowers;

            if (consecutiveFlowers == flowersPerBouquet) {
                ++completedBouquets;
                consecutiveFlowers = 0;
            }
        } else {
            consecutiveFlowers = 0;
        }

        if (completedBouquets >= bouquets) {
            return true;
        }
    }

    return false;
}

/**
 * @brief Finds the minimum number of days needed to make bouquets.
 *
 * @param bloomDay Blooming day of each flower.
 * @param bouquets Required number of bouquets.
 * @param flowersPerBouquet Flowers required per bouquet.
 * @return int Minimum required day, or -1 if impossible.
 */
int minimumDays(const std::vector<int>& bloomDay,
                int bouquets,
                int flowersPerBouquet) {
    if (static_cast<long long>(bouquets) * flowersPerBouquet
        > static_cast<long long>(bloomDay.size())) {
        return -1;
    }

    int left = std::numeric_limits<int>::max();
    int right = std::numeric_limits<int>::min();

    for (const int day : bloomDay) {
        left = std::min(left, day);
        right = std::max(right, day);
    }

    while (left <= right) {
        const int mid = left + (right - left) / 2;

        if (canMakeBouquets(
                bloomDay,
                bouquets,
                flowersPerBouquet,
                mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

/**
 * @brief Demonstrates binary search on answer.
 *
 * @return int Exit status.
 */
int main() {
    const std::vector<int> bloomDay = {
        1, 10, 3, 10, 2
    };

    const int bouquets = 3;
    const int flowersPerBouquet = 1;

    std::cout << "Minimum days required: "
              << minimumDays(
                     bloomDay,
                     bouquets,
                     flowersPerBouquet)
              << '\n';

    return 0;
}