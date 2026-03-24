// Approach 1

#ifndef INCREMENTAL_SUMMATION_HPP
#define INCREMENTAL_SUMMATION_HPP

#include <string>

class IncrementalSummationSolution {
public:
    int numSub(const std::string& s) {
        const long long MOD = 1000000007;
        long long count = 0;
        long long result = 0;

        for (char c : s) {
            if (c == '1') {
                ++count;
                result = (result + count) % MOD;
            } else {
                count = 0;
            }
        }

        return static_cast<int>(result);
    }
};

#endif