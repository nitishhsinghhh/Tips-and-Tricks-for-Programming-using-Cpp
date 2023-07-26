#include <iostream>
#include <array>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    array<int, 5> arr = {1, 2, 3, 4, 5};

    cout << "Accessing array elements:" << endl;
    cout << "numbers[2]: " << numbers[2] << endl;
    cout << "arr[3]: " << arr[3] << endl;

    return 0;
}
