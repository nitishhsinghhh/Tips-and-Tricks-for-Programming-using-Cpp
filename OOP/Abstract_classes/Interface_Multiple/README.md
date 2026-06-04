# Abstract class

In C++, **abstract classes** and **interfaces** are both mechanisms to define contracts that derived classes must follow.  
They rely on **pure virtual functions**, which declare a function signature without providing an implementation.

While languages like Java or C# have an explicit interface keyword, C++ does not. Instead, C++ uses abstract classes to achieve both concepts:

- Abstract Class: A class that has at least one pure virtual function. It can still contain state (member variables) and regular functions with actual code.
- Interface (Conceptual): In C++, an "interface" is just a specialized abstract class. It is a class where every single function is pure virtual, and it has no member variables (except maybe static constants).

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
    virtual ~Animal() = default; // Essential for safe polymorphic deletion!
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
    virtual ~Drawable() = default; // Essential!
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

Note: Whenever a class has virtual functions, it must have a virtual destructor, omitting the virtual destructor results in undefined behavior.

- Virtual Destructors: Always declare a virtual ~Base() = default; in abstract classes/interfaces to ensure safe polymorphic deletion.

## UML Diagram

```UML
            +--------------------------+       +--------------------------+
            |         Animal           |       |        Drawable          |
            |        {abstract}        |       |        {abstract}        |
            +--------------------------+       +--------------------------+
            | + ~Animal()              |       | + ~Drawable()            |
            | + makeSound() = 0        |       | + draw() = 0             |
            | + sleep()                |       | + setPosition() = 0      |
            +--------------------------+       +--------------------------+
                         \                                  /
                          \                                /
                            \                             /
                             \                           /
                            +----------------------------+
                            |            Cat             |
                            +----------------------------+
                            | + ~Cat()                   |
                            | + makeSound()              |
                            | + draw()                   |
                            | + setPosition()            |
                            +----------------------------+
```

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

- C++ allows a class to inherit from multiple base classes. Useful for combining behaviors from multiple sources.
- while C++ allows multiple inheritance, We should ideally only inherit from one heavy abstract class (with state) and multiple pure interfaces (without state) to avoid structural complexity.
- Potentially risky because of the diamond problem, which can be resolved with virtual inheritance when needed. when two base classes inherit from the same grand-base class, causing duplicate data members in the derived class
- override acts as a compiler safeguard and prevents silent bugs. If you accidentally misspell the function name or change the parameters in Cat (e.g., void makeSounds()), the compiler will throw an error telling you that I'm not actually overriding anything.
- You cannot create an object of an abstract class directly. However, you can create pointers and references to it (e.g., Animal* ptr = new Cat();), which is the foundation of runtime polymorphism.

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

---

## The Normal Chain of Destruction (Without Polymorphism)

In C++, objects are destroyed in the exact reverse order of their construction. If you create a Cat object normally on the stack:

- Construction: Animal constructor runs first → Cat constructor runs second.
- Destruction: Cat destructor runs first → Animal destructor runs second.

This ensures that the derived class cleans up its own mess first, and then the base class cleans up the rest. Everything is fine.

### Upcasting WITHOUT a Virtual Destructor

The problem arises when you use a base class pointer to manage a derived object, which is incredibly common when using abstract classes or interfaces:

```Cpp
Animal* pet = new Cat(); // Upcasting
// ...
delete pet; // Static binding occurs here if not virtual!
```

If ~Animal() is not marked as virtual, the compiler looks at the type of the pointer (Animal*), not the type of the actual object (Cat).

- The Broken Chain: The compiler statically binds the delete call to ~Animal().
- The Result: Only ~Animal() is called. ~Cat() is completely skipped.
- The Consequence: Any memory allocated inside Cat (like strings, vectors, or raw pointers) is leaked. This is undefined behavior.

When you add the virtual keyword to the base class destructor:

```Cpp
virtual ~Animal() = default;
```

You are telling the compiler to look at the vtable (virtual table) of the actual object at runtime.

Now, when you call delete pet;, the execution chain looks like this:

```txt
[delete pet] 
     │
     ▼
Look up vtable ──► Triggers Cat's Destructor (~Cat())
                         │
                         ▼
             Cat cleans up its resources
                         │
                         ▼
             Automatically chains down ──► Triggers Animal's Destructor (~Animal())
                                                 │
                                                 ▼
                                     Animal cleans up its resources
```

The virtual keyword guarantees that the destruction starts at the most derived class (Cat). Once ~Cat() finishes executing, C++ automatically and implicitly calls the base class destructor (~Animal()).

Interview Gold Rule: You only need to declare the destructor as virtual in the base class. Once a function (including a destructor) is marked virtual in a base class, it remains virtual all the way down the inheritance chain automatically.

You do not need to explicitly write virtual in the derived class destructor. Once a destructor (or any function) is marked virtual in the base class, it is permanently and automatically virtual for all classes that inherit from it, no matter how deep the inheritance tree goes.

### How the Compiler Sees It

Even if you write a plain, non-virtual looking destructor in your derived class like this:

```Cpp
class Cat : public Animal {
public:
    ~Cat() { /* Clean up cat stuff */ } // Automatically virtual!
};
```

The compiler secretly treats it as if you wrote:

```Cpp
class Cat : public Animal {
public:
    virtual ~Cat() override { /* Clean up cat stuff */ } 
};
````

Because Animal declared ~Animal() as virtual, Cat's destructor is placed into the virtual table (vtable) automatically.

What if another class inherits from Cat? (The Deep Chain)

Imagine you expand your code later for a specific breed of cat:

```txt
[Animal] (Explicitly virtual)
   │
   ▼
 [Cat]   (Automatically virtual)
   │
   ▼
[Persian] (Automatically virtual)
```

If you have a pointer to the grand-base class: Animal* myPet = new Persian(); and you call delete myPet;, the virtual chain still works perfectly:

1. It calls ~Persian()
2. It automatically drops down to ~Cat()
3. It automatically drops down to ~Animal()

#### Interview Tip: Best Practice for writing Derived Destructors

While the virtual keyword is optional in the derived class, modern C++ guidelines recommend using the override keyword if you choose to explicitly declare it. This signals your architectural intent clearly to anyone reading your code:

```cpp
class Cat : public Animal {
public:
    ~Cat() override = default; // Clear, clean, and safe!
};
```

Destruction always happens in the exact reverse order of construction.

Think of it like a stack of plates: the first plate you put down (the base class) must be the last plate you take off. The last plate you put on top (the most derived class) is the first one you remove.

Here is exactly how the step-by-step timeline looks for a Cat object that inherits from Animal:

#### Phase 1: Construction (Top-Down)

When you create the object (Animal* pet = new Cat();), C++ builds it from the foundational base upward:

- First: Animal constructor allocates and initializes the base properties.
- Second: Cat constructor runs to initialize the specific cat properties.

#### Phase 2: Destruction (Bottom-Up / Reverse Order)

When you call delete pet; (and the destructor is virtual), C++ tears it down from the top layer back down to the foundation:

- First: ~Cat() runs. It cleans up everything exclusive to the Cat class (e.g., freeing unique memory or resources Cat managed).
- Second: ~Animal() runs automatically right after. It cleans up the foundational base class properties.

### Why does C++ do it this way?

It is a safety mechanism. While Cat is being destroyed, it might still need to look at or use variables that belong to Animal.
If C++ destroyed Animal first, then Cat's destructor would be trying to access a dead, non-existent base class, causing immediate crashes or corrupted data. By destroying Cat first, the base class stays completely alive and valid until the derived class is totally finished cleaning itself up.

---

### Intereview concise definitions

- override: It shifts a silent runtime bug into a loud compile-time error.
- destruction order philosophy: Derived depends on Base. Therefore, Base must outlive Derived to prevent dangling references during teardown.
- why C++ doesn't have an interface keyword: C++ relies on the power of multiple inheritance and pure virtual classes to achieve interfaces structurally, giving the developer structural control without adding keywords to the language grammar.

---

Alternative A: CRTP (Curiously Recurring Template Pattern)

When you want compile-time polymorphism (static polymorphism) to eliminate the performance overhead of vtable lookups and extra pointer indirection:

```C++
template <typename Derived>
class Animal {
public:
    void makeSound() {
        static_cast<Derived*>(this)->implementationMakeSound();
    }
};

class Cat : public Animal<Cat> {
public:
    void implementationMakeSound() { cout << "Meow!" << endl; }
};
```

---

### Alternative B: std::variant and std::visit (C++17)

Modern C++ architecture often favors value semantics over reference semantics (inheritance hierarchies). Instead of an abstract class pointer, you can use a type-safe variant wrapper, which keeps data contiguous in memory:

```C++
using MyPet = std::variant<Cat, Dog>;
// No virtual pointers, no heap allocation required for polymorphism!
```
