// Approach 2

#ifndef FORMULA_BLOCK_HPP
#define FORMULA_BLOCK_HPP

#include <string>

class FormulaBlockSolution {
public:
    int numSub(const std::string& s) {
        const long long MOD = 1000000007;
        long long count = 0;
        long long result = 0;

        for (char c : s) {
            if (c == '1') {
                ++count;
            } else {
                result = (result + (count * (count + 1) / 2) % MOD) % MOD;
                count = 0;
            }
        }

        result = (result + (count * (count + 1) / 2) % MOD) % MOD;

        return static_cast<int>(result);
    }
};

#endif