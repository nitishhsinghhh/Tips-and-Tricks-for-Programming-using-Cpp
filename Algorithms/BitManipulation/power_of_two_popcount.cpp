#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && __builtin_popcount(static_cast<unsigned int>(n)) == 1;
}

int main() {
    int n = 32;
    cout << (isPowerOfTwo(n) ? "true" : "false") << '\n';
    return 0;
}
