#include <cmath>
#include <iostream>
class PrimeFactors {
private:
    int n;

public:
    // Constructor
    PrimeFactors(int num) : n(num) {}

    void calculatePrimeFactors() {
        std::cout << "The prime factors are: ";
        if (n == 1) {
            std::cout << "none\n";
            return;
        }
        // Handle divisibility by 2 separately
        while (n % 2 == 0) {
            print(2);
            n /= 2;
        }
        // Handle divisibility by 3
        while (n % 3 == 0) {
            print(3);
            n /= 3;
        }
        // Handle remaining numbers
        for (int i = 5; i * i <= n; i += 6) {
            while (n % i == 0) {
                print(i);
                n /= i;
            }
            while (n % (i + 2) == 0) {
                print(i + 2);
                n /= (i + 2);
            }
        }
        if (n > 1) {
            print(n);
        }
    }

private:
    bool primeCheck(int x) {
        if (x <= 2 || x % 2 == 0)
            return false;
        if (x == 3 || x % 3 == 0)
            return false;

        for (int i = 5; i * i <= x; i += 6)
            if (x % i == 0 || x % (i + 2) == 0)
                return false;
        return true;
    }

    void print(int num) { std::cout << num << " "; }
};
int main() {
    int n;
    do {
        std::cout << "Please input positive number: ";
        std::cin >> n;
        if (n < 1) {
            std::cout << "Please enter positive integer\n";
        }
    } while (n < 1);
    PrimeFactors pf(n);
    pf.calculatePrimeFactors();

    system("pause");
    return 0;
}
/*
 * =====================OUTPUT==================
 * Input: n = 6
 * Output: The prime factors are: 2 3
 * ---------------------
 * Input: n = 1
 * Output: The prime factors are: none
 * ---------------------
 * Input: n = 88
 * Ouput: The prime factors are: 2 2 2 11
 */
