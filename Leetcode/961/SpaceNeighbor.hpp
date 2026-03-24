// Approach 3: Strict O(1) Space Neighbor Check

#ifndef SPACE_NEIGHBOR_HPP
#define SPACE_NEIGHBOR_HPP

#include <vector>

class SpaceNeighborSolution {
public:
    int repeatedNTimes(const std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < n && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < n && nums[i] == nums[i + 3]) return nums[i];
        }

        // Technically unreachable under valid constraints.
        return nums[0];
    }
};

#endif