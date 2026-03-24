// Approach 1: Frequency Map (Early Return)

#ifndef FREQUENCY_MAP_HPP
#define FREQUENCY_MAP_HPP

#include <vector>
#include <unordered_map>

class FrequencyMapSolution {
public:
    int repeatedNTimes(const std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        freq.reserve(nums.size());

        for (int x : nums) {
            if (++freq[x] == 2) {
                return x;
            }
        }

        // Defensive fallback; unreachable under stated constraints.
        return -1;
    }
};

#endif