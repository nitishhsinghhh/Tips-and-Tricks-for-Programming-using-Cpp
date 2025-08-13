In C++, **abstract classes** and **interfaces** are both mechanisms to define contracts that derived classes must follow.  
They rely on **pure virtual functions**, which declare a function signature without providing an implementation.

This example demonstrates:
- An **abstract class** (`Animal`) with a pure virtual function and a regular member function.
- An **interface-like** class (`Drawable`) containing only pure virtual functions.
- A **concrete class** (`Cat`) that inherits from **both**, illustrating multiple inheritance.


```Cpp
/**
 * @brief Demonstrates abstract classes, interfaces, and multiple inheritance in C++.
 * @details
 * This program defines:
 * - An abstract class `Animal` with a pure virtual function.
 * - An interface-like class `Drawable` with pure virtual functions.
 * - A concrete class `Cat` that inherits from both and implements all required functions.
 */

#include <iostream>

using std::cout;
using std::endl;

/**
 * @class Animal
 * @brief Abstract base class representing a generic animal.
 */
class Animal {
public:
    /**
     * @brief Makes the sound of the animal.
     * @note This is a pure virtual function, making `Animal` an abstract class.
     */
    virtual void makeSound() = 0;

    /**
     * @brief Simulates the animal sleeping.
     */
    void sleep() {
        cout << "Zzz..." << endl;
    }
};

/**
 * @class Drawable
 * @brief Interface for drawable objects.
 */
class Drawable {
public:
    /**
     * @brief Draw the object.
     */
    virtual void draw() = 0;

    /**
     * @brief Set the object's position.
     * @param x X-coordinate of the position.
     * @param y Y-coordinate of the position.
     */
    virtual void setPosition(int x, int y) = 0;
};

/**
 * @class Cat
 * @brief A concrete class representing a cat, which is both an animal and drawable.
 * @details Inherits from `Animal` and `Drawable`, implementing all pure virtual functions.
 */
class Cat : public Animal, public Drawable {
public:
    /**
     * @brief Makes a "Meow!" sound.
     */
    void makeSound() override {
        cout << "Meow!" << endl;
    }

    /**
     * @brief Draws the cat.
     */
    void draw() override {
        cout << "Drawing a cat..." << endl;
    }

    /**
     * @brief Sets the position of the cat.
     * @param x X-coordinate of the position.
     * @param y Y-coordinate of the position.
     */
    void setPosition(int x, int y) override {
        cout << "Setting cat position to (" << x << ", " << y << ")" << endl;
    }
};

/**
 * @brief Program entry point.
 * @return Exit code (0 if successful).
 */
int main() {
    Cat cat;
    cat.makeSound();        ///< Output: Meow!
    cat.draw();             ///< Output: Drawing a cat...
    cat.setPosition(10, 20);///< Output: Setting cat position to (10, 20)
    cat.sleep();            ///< Output: Zzz...
    return 0;
}

```

## UML Diagram

     +----------------+       +------------------+
     |     Animal     |       |     Drawable     |
     +----------------+       +------------------+
     | +makeSound()=0 |       | +draw()=0        |
     | +sleep()       |       | +setPosition()=0 |
     +----------------+       +------------------+
                  \                  /
                   \                /
                    \              /
                     \            /
                    +---------------+
                    |      Cat      |
                    +---------------+
                    | +makeSound()  |
                    | +draw()       |
                    | +setPosition()|
                    +---------------+


## Interface in C++
C++ does not have a native interface keyword like Java or C#.
Instead, an interface can be represented as:
A class containing only pure virtual functions.
No data members (by convention).
Public inheritance from it signals "implements this contract."
```Cpp
class Drawable {
public:
    virtual void draw() = 0;
    virtual void setPosition(int x, int y) = 0;
};
```
## Multiple Inheritance
C++ allows a class to inherit from multiple base classes:
Useful for combining behaviors from multiple sources.
Potentially risky because of the diamond problem, which can be resolved with virtual inheritance when needed.
In our example, Cat inherits from both Animal and Drawable.
```Cpp
class Cat : public Animal, public Drawable {
    ...
};
```

## Best Practices
- Use abstract classes when you want partial implementation and shared state among derived classes.
- Use interfaces (pure virtual classes) when you only want to enforce a contract.
- In multiple inheritance, avoid ambiguous base class paths — consider virtual inheritance if needed.
- Clearly document which base class provides which responsibility.
