#include <iostream>
int main() {
    int a = 5; // Binary: 0101
    int b = 10; // Binary: 1010
    int c = 7; // Binary: 0111

    int flips  = 0;
    while(a || b || c) {
        if(c & 1) {
            if ((a & 1) == 0 & (b & 1) == 0)
                flips ++;
        } else {
            if (a & 1)
                flips ++;
            if(b & 1)
                flips ++;
        }
        a >>=1, b >>= 1, c >>= 1;
    }
    return flips ;
}
