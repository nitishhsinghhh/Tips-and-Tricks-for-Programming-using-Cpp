#include <iostream>

using namespace std;

void stackMemory() {
    int x = 5; // Integer variable allocated on the stack
    int y = 10;
    int z = x + y;
    cout << "Stack memory: " << z << endl;
}

void heapMemory() {
    int size = 5;
    int* array = new int[size]; // Allocate an array on the heap
    int sum = 0;
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
        sum += array[i];
    }
    cout << "Heap memory: " << sum << endl;
    delete[] array; // Deallocate the array from the heap
}

int main() {
    stackMemory();
    heapMemory();
    return 0;
}
