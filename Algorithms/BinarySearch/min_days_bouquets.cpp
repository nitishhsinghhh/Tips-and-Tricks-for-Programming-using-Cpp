#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

/**
 * @class Solution
 * @brief Provides a method to find the minimum number of days required
 * to make m bouquets from flowers.
 */
class Solution {
private:
    /**
     * @brief Checks whether it is possible to make 'm' bouquets by day 'mid'.
     *
     * @param bloomDay Vector representing bloom days of flowers.
     * @param m Number of bouquets to make.
     * @param k Number of flowers required in each bouquet.
     * @param mid The day being tested.
     * @return true If it is possible to make m bouquets by day 'mid'.
     * @return false Otherwise.
     */
    bool isValid(
        const std::vector<int>& bloomDay,
        int m,
        int k,
        int mid) {

        int count = 0;
        int size = 0;

        for (int day : bloomDay) {
            size = (day <= mid) ? size + 1 : 0;

            if (size == k) {
                count++;
                size = 0;
            }

            if (count == m)
                return true;
        }

        return false;
    }

public:
    /**
     * @brief Finds the minimum number of days required to make m bouquets.
     *
     * @param bloomDay A vector containing the days each flower blooms.
     * @param m Number of bouquets required.
     * @param k Number of flowers per bouquet.
     * @return int Minimum number of days needed, or -1 if impossible.
     */
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if (bloomDay.empty() || m == 0 || k == 0)
            return 0;

        if (static_cast<long long>(m) * k > bloomDay.size())
            return -1;

        int l = INT_MAX;
        int r = INT_MIN;

        for (int day : bloomDay) {
            l = std::min(l, day);
            r = std::max(r, day);
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isValid(bloomDay, m, k, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};