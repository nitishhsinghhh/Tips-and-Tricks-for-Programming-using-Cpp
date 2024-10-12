// A program that calculates the LCM of two numbers. Taking the numbers as input from the user.
#include <iostream>
class LCM {
private:
    int a, b;
    // calculate gcd using Euclidean Algorithm
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        if (a == b)
            return b;
        if (a > b)
            gcd(a % b, b);
        else if (b > a)
            gcd(a, b % a);
    }
    // calculate lcm where [LCM = (a*b)/gcd(a,b)]
    long long calcLCM(int x, int y) {
        long long mul = x;
        mul *= y;
        long long res = mul / gcd(x, y);
        return res;
    }

public:
    // constructor
    LCM(int _a, int _b) : a(_a), b(_b) {}

    void findLCM() {
        int res = calcLCM(a, b);
        std::cout << "The LCM of the numbers: " << res << std::endl;
    }
};
int main() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    LCM lcm(a, b);
    lcm.findLCM();
    return 0;
}
/*
============================OUTPUT SECTION================================
INPUT: a = 12, b = 8
OUTPUT: 24
----------------------
INPUT: a = 4, b = 5
OUTPUT: 20
-----------------------
INPUT: a = 1, b = 7
OUTPUT: 7
-----------------------
INPUT: a = 10, b = 10
OUTPUT: 10
-----------------------
*/
