# Happy number
In number theory, a [happy number](https://en.wikipedia.org/wiki/Happy_number) is a number that, when replaced by the sum of the square of each of its digits, eventually reaches 1. For example, 13 is a happy number because 1^2 + 3^2 = 10, and 1^2 + 0^2 = 1. On the other hand, 4 is not a happy number because the sequence starting with 4^2 = 16 and 1^2 + 6^2 = 37 eventually reaches 2^2 + 0^2 = 4, and the process continues in an infinite cycle without reaching 1. A number that is not happy is called sad or unhappy.

More generally, a base-b happy number is a natural number in a given number base b that eventually reaches 1 when iterated over the perfect digital invariant function for b=2. The origin of happy numbers is uncertain. They were brought to the attention of Reg Allenby by his daughter, who had learned of them at school. However, they "may have originated in Russia"

##### A simple program in C++ to check if a number is happy:

```cpp
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        } while (slow != fast);
        return slow == 1;
    }

private:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};
```
