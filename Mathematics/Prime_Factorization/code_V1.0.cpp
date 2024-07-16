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
        // Iterate over odd numbers starting from 3
        for (int i = 3; i * i <= n; i += 2)
            while (n % i == 0) {
                if (primeCheck(i))
                    print(i);
                n /= i;
            }

        // If number is not divided above and greater than 2
        if (n > 1 && primeCheck(n))
            print(n);
    }

private:
    bool primeCheck(int x) {
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0)
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
  =====================OUTPUT==================
  Input: n = 6
  Output: The prime factors are: 2 3
  ---------------------
  Input: n = 1
  Output: The prime factors are: none
  ---------------------
  Input: n = 88
  Ouput: The prime factors are: 2 2 2 11
*/
