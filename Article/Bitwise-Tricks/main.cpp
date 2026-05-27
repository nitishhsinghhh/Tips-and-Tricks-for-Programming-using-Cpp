#include <iostream>
#include <cassert>

// --- Your Functions ---

bool isPowerOfTwo(int n) {
    if (n <= 0) 
        return false;
    while (n % 2 == 0)
        n /= 2;
    return n == 1;
}

bool isPowerOfThree(int n) {
    if (n <= 0) 
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

bool isPowerOfK(int n, int k) {
    if (n <= 0 || k <= 1) 
        return false;
    if (n == 1) return true; // k^0 = 1
    while (n % k == 0)
        n /= k;
    return n == 1;
}

// --- Test Suite ---

void testPowerOfTwo() {
    // Positive cases
    assert(isPowerOfTwo(1) == true);   // 2^0
    assert(isPowerOfTwo(2) == true);   // 2^1
    assert(isPowerOfTwo(16) == true);  // 2^4
    assert(isPowerOfTwo(1024) == true);// 2^10

    // Negative / Edge cases
    assert(isPowerOfTwo(0) == false);
    assert(isPowerOfTwo(-8) == false);
    assert(isPowerOfTwo(6) == false);  // Even but not a power of 2
    assert(isPowerOfTwo(15) == false); // Odd number
    std::cout << "isPowerOfTwo tests passed!\n";
}

void testPowerOfThree() {
    // Positive cases
    assert(isPowerOfThree(1) == true);   // 3^0
    assert(isPowerOfThree(3) == true);   // 3^1
    assert(isPowerOfThree(27) == true);  // 3^3
    assert(isPowerOfThree(81) == true);  // 3^4

    // Negative / Edge cases
    assert(isPowerOfThree(0) == false);
    assert(isPowerOfThree(-9) == false);
    assert(isPowerOfThree(12) == false); // Multiple of 3 but not a power
    assert(isPowerOfThree(26) == false);
    std::cout << "isPowerOfThree tests passed!\n";
}

void testPowerOfK() {
    // Standard validation
    assert(isPowerOfK(1, 5) == true);    // 5^0
    assert(isPowerOfK(5, 5) == true);    // 5^1
    assert(isPowerOfK(125, 5) == true);  // 5^3
    
    assert(isPowerOfK(1, 10) == true);   // 10^0
    assert(isPowerOfK(100, 10) == true); // 10^2

    // Edge cases for n
    assert(isPowerOfK(0, 5) == false);
    assert(isPowerOfK(-25, 5) == false);
    assert(isPowerOfK(20, 5) == false);  // Multiple of 5 but not a power

    // Constraints protection on k (k <= 1 validation)
    assert(isPowerOfK(5, 1) == false);
    assert(isPowerOfK(5, 0) == false);
    assert(isPowerOfK(5, -2) == false);
    std::cout << "isPowerOfK tests passed!\n";
}

int main() {
    std::cout << "--- Running Unit Tests ---\n";
    testPowerOfTwo();
    testPowerOfThree();
    testPowerOfK();
    std::cout << "All assertions passed successfully!\n";
    return 0;
}