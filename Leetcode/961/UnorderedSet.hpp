// Approach 2: First Duplicate via unordered_set

#ifndef UNORDERED_SET_HPP
#define UNORDERED_SET_HPP

#include <vector>
#include <unordered_set>

class UnorderedSetSolution {
public:
    int repeatedNTimes(const std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());

        for (int x : nums) {
            if (!seen.insert(x).second) {
                return x;
            }
        }

        // Defensive fallback; unreachable under stated constraints.
        return -1;
    }
};

#endif