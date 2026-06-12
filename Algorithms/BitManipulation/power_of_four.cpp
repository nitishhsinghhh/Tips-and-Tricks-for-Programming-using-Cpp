#include <iostream>
using namespace std;

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

    while (n % k == 0)
        n /= k;

    return n == 1;
}

int main() {
    cout << isPowerOfTwo(16) << '\n';   // 1
    cout << isPowerOfThree(27) << '\n'; // 1
    cout << isPowerOfK(81, 3) << '\n';  // 1
    cout << isPowerOfK(20, 3) << '\n';  // 0

    return 0;
}
