#include <iostream>

class fibonacci {
public:
    // Types & Type Aliases
    typedef int (*FibFunc)(int);                                 // Function pointer to static function
    typedef int (fibonacci::*MemberFibFunc)(int);               // Function pointer to non-static member function

    // Member Functions
    int fibByValue(int num);                                    // Non-static, pass by value
    static int fibByValueStatic(int num);                       // Static, pass by value
    int fibByRef(const int& num);                               // Non-static, pass by reference
    int fibByPointer(int* num);                                 // Non-static, pass by pointer

    // Callback Function
    static void runFib(int n, FibFunc fibFunc); 
};

// --- Implementation ---

int fibonacci::fibByValue(int num) {
    if (num == 1 || num == 2) {
        return 1;
    } else {
        return fibonacci::fibByValue(num - 1) + fibonacci::fibByValue(num - 2);
    }
}

int fibonacci::fibByValueStatic(int num) {
    if (num == 1 || num == 2) {
        return 1;
    } else {
        return fibonacci::fibByValueStatic(num - 1) + fibonacci::fibByValueStatic(num - 2);
    }
}

int fibonacci::fibByRef(const int& num) {
    if (num == 1 || num == 2) {
        return 1;
    } else {
        return fibonacci::fibByRef(num - 1) + fibonacci::fibByRef(num - 2);
    }
}

int fibonacci::fibByPointer(int* num) {
    if (*num == 1 || *num == 2) {
        return 1;
    } else {
        // We create new local integers for recursion because directly 
        // decrementing the pointer would lead to invalid memory access.
        int n1 = *num - 1;
        int n2 = *num - 2;
        return fibonacci::fibByPointer(&n1) + fibonacci::fibByPointer(&n2);
    }
}

void fibonacci::runFib(int n, FibFunc fibFunc) {
    std::cout << "Callback Result: " << fibFunc(n) << std::endl;
}

// --- Main Driver ---

int main() {
    fibonacci fib;

    // 1. Non-static pass by value
    std::cout << "Non-static Value (5): " << fib.fibByValue(5) << std::endl;

    // 2. Static pass by value
    std::cout << "Static Value (5): " << fibonacci::fibByValueStatic(5) << std::endl;

    // 3. Non-static pass by reference
    int numRef = 6;
    std::cout << "Non-static Reference (6): " << fib.fibByRef(numRef) << std::endl;

    // 4. Non-static pass by pointer
    int numPtr = 7;
    std::cout << "Non-static Pointer (7): " << fib.fibByPointer(&numPtr) << std::endl;

    // 5. Static Function Pointer Usage
    fibonacci::FibFunc fPtr = &fibonacci::fibByValueStatic;
    std::cout << "Static Pointer Result (10): " << fPtr(10) << std::endl;

    // 6. Member Function Pointer Usage
    fibonacci::MemberFibFunc memberPtr = &fibonacci::fibByValue;
    std::cout << "Member Pointer Result (11): " << (fib.*memberPtr)(11) << std::endl;

    // 7. Callback Execution
    fibonacci::runFib(6, fibonacci::fibByValueStatic);

    return 0;
}