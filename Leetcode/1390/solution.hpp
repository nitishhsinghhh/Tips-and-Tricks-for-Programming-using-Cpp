#include <vector>
#include <cmath>

class Solution {
public:
    int sumFourDivisors(std::vector<int>& nums) {
        int total = 0;

        for (int n : nums) {
            // Case 1: p^3
            int p = round(cbrt(n));
            if ((long long)p * p * p == n && isPrime(p)) {
                total += 1 + p + p * p + n;
                continue;
            }

            // Case 2: p * q
            for (int i = 2; (long long)i * i <= n; ++i) {
                if (n % i == 0) {
                    int j = n / i;
                    if (i != j && isPrime(i) && isPrime(j)) {
                        total += 1 + i + j + n;
                    }
                    break; // only need first factor
                }
            }
        }
        return total;
    }

private:
    bool isPrime(int x) {
        if (x < 2)
            return false;
        for (int i = 2; (long long)i * i <= x; ++i)
            if (x % i == 0)
                return false;
        return true;
    }
};