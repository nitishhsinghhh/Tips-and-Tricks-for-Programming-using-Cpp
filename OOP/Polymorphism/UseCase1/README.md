# Understanding and Implementing Polymorphism in C++: An Example with Shapes
Polymorphism is one of the fundamental principles of object-oriented programming (OOP). It allows objects of different classes to be treated as objects of a common base class. This article explores polymorphism in C++ using a practical example involving shapes, such as circles and squares.

## Problem Statement
We aim to demonstrate polymorphism by creating a base class Shape with a virtual function draw(), and two derived classes, Circle and Square, that override the draw() function. Additionally, we will manage dynamic memory and ensure proper cleanup using a virtual destructor. Finally, we will initialize and access a data member in one of the derived classes.

### Step-by-Step Solution
1. Define the Base Class: 
   The base class Shape includes a virtual draw() function and a virtual destructor to ensure proper cleanup of derived objects.
2. Define Derived Classes: 
   The derived classes Circle and Square override the draw() function to provide specific implementations for drawing a circle and a square, respectively. The Square class also includes a data member data initialized through a constructor.
3. Demonstrate Polymorphism: 
   In the main function, we create objects of Circle and Square dynamically, call their draw() functions through base class pointers, and access the data member of the Square object.

## Implementation
```cpp
#include <iostream>

class Shape {
public:
    // Virtual function for drawing a shape
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    // Override the draw function to draw a circle
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    int data;

    // Constructor to initialize data
    Square() { data = 10; }

    // Override the draw function to draw a square
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw(); // Calls the draw() function of the Circle class
    shape2->draw(); // Calls the draw() function of the Square class

    std::cout << "Square data: " << dynamic_cast<Square*>(shape2)->data << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}

```

## Explanation
1. Base Class Shape: The Shape class defines a virtual draw() function, which will be overridden by derived classes. The virtual destructor ensures that the derived class destructors are called correctly, preventing memory leaks.
2. Derived Class Circle: The Circle class overrides the draw() function to print "Drawing a circle." This demonstrates specific behavior for the circle shape.
3. Derived Class Square: The Square class overrides the draw() function to print "Drawing a square." It also includes a data member data initialized to 10 through a constructor.
4. Dynamic Memory Allocation and Polymorphism: 
- In the main function, we create Circle and Square objects dynamically using new and store them in Shape* pointers. This demonstrates polymorphism, where the base class pointer can point to derived class objects.
- The draw() function is called on these pointers, which invokes the correct overridden function based on the actual object type.
- We use dynamic_cast to safely cast the Shape* pointer to a Square* pointer to access the data member.

### Output:

When running the program, the following output is produced:

```cpp
Drawing a circle.
Drawing a square.
Square data: 10
```

## Conclusion
This example demonstrates the power and flexibility of polymorphism in C++. By defining a base class with virtual functions and overriding these functions in derived classes, we can create a flexible and extensible design. The use of virtual destructors ensures that resources are cleaned up correctly, preventing memory leaks. This approach is fundamental in designing robust and maintainable object-oriented software.
