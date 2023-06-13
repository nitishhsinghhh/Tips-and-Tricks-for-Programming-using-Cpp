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
