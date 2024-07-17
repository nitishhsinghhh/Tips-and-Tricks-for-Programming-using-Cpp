#include <iostream>

// Global variable
int x = 10;

// Namespace
namespace Math {
    int add(int a, int b) {
        return a + b;
    }
}

// Class
class MyClass {
public:
    int myVariable;

    void myFunction() {
        std::cout << "This is a member function." << std::endl;
    }

    static int myStaticVariable;

    static void myStaticFunction() {
        std::cout << "This is a static member function." << std::endl;
    }
};

int MyClass::myStaticVariable = 42;

int main() {
    // Local variable
    int x = 5;

    // Output local and global variables
    std::cout << "Local variable x: " << x << std::endl;
    std::cout << "Global variable x: " << ::x << std::endl;

    // Output namespace function
    std::cout << "Math::add(2, 3): " << Math::add(2, 3) << std::endl;

    // Output class member variable and function
    MyClass obj;
    obj.myVariable = 10;
    std::cout << "obj.myVariable: " << obj.myVariable << std::endl;
    obj.myFunction();

    // Output class static member variable and function
    MyClass::myStaticVariable = 20;
    std::cout << "MyClass::myStaticVariable: " << MyClass::myStaticVariable << std::endl;
    MyClass::myStaticFunction();

    return 0;
}
/*
Local variable x: 5
Global variable x: 10
Math::add(2, 3): 5
obj.myVariable: 10
This is a member function.
MyClass::myStaticVariable: 20
This is a static member function.
*/
