#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    constexpr int maxPowerOf3 = 1162261467;

    return n > 0 && maxPowerOf3 % n == 0;
}

int main() {
    int testVals[] = {1, 3, 9, 27, 81, 10, 45};

    for (int n : testVals) {
        cout << n << " -> "
             << (isPowerOfThree(n) ? "true" : "false")
             << '\n';
    }

    return 0;
}
