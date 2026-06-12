#include <iostream>
#include <bit>

bool isPowerOfTwo(int n) {
    return n > 0 && std::has_single_bit(static_cast<unsigned int>(n));
}

int main() {
    int testVals[] = {
        -8, -1, 0, 1, 2, 3, 4, 5,
        8, 12, 16, 31, 32, 64, 100, 1024
    };

    for (int n : testVals) {
        std::cout << n << " -> "
             << (isPowerOfTwo(n) ? "true" : "false")
             << '\n';
    }

    return 0;
}
