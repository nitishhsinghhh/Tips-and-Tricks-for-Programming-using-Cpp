// A program that calculates the GCD of two numbers. Take the numbers as input.
#include <iostream>
class GCD {
private:
    int n, m;
    // calculate the GCD of two numbers
    int calcGCD(int n, int m) {
        if (n == m)
            return n;
        if (n == 0)
            return m;
        else if (m == 0)
            return n;
        if (n > m)
            calcGCD(n % m, m);
        else if (m > n)
            calcGCD(m % n, n);
    }

public:
    // constructor
    GCD(int a, int b) : n(a), m(b) {}
    void findGCD() {
        int res = calcGCD(n, m);
        std::cout << "The GCD of the numbers: " << res << std::endl;
    }
};
int main() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    GCD gcd(a, b);
    gcd.findGCD();
    return 0;
}

/*
===================OUTPUT SECTION=============================
INPUT: a = 5, b = 4
OUTPUT: 1
-------------------
INPUT: a = 7, b = 35
OUTPUT: 7
-------------------
INPUT: a = 0, b = 8
OUTPUT: 8
-------------------
INPUT: a = 2, b = 2
OUTPUT: 2
================================================================
*/
