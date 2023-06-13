// https://leetcode.com/problems/prime-in-diagonal/description/

class Solution {
public:
    bool isPrime(int n){
        if (n <= 2 || n % 2 == 0) 
            return n == 2;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }      
    int diagonalPrime(vector<vector<int>>& n) {
        int p = 0;
        for (int i = 0; i < n.size(); ++i)
            p = max({p, isPrime(n[i][i]) * n[i][i], 
                isPrime(n[i][n.size() - i - 1]) * n[i][n.size() - i - 1]});
        return p;
    }
};

// Solution 2: Sieve of Eratosthenes

bool sieve[4000001] =  { true, true }; 
class Solution {
    public:
    void buildSieve() {
        for (int p = 2; p * p < 400001; ++p)
            if (!sieve[p])
                for (int i = p * p; i < 400001; i += p)
                    sieve[i] = true;
    }
    int diagonalPrime(vector<vector<int>>& n) {
        if (!sieve[4])
            buildSieve();
        int p = 0;
        for (int i = 0; i < n.size(); ++i)
            p = max({p, !sieve[n[i][i]] * n[i][i], 
                !sieve[n[i][n.size() - i - 1]] * n[i][n.size() - i - 1]});
        return p;
    }
};
