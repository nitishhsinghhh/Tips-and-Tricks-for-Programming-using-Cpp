#  What is the difference between compile-time and runtime polymorphism in C++?
- Compile-time polymorphism is achieved via function overloading and operator overloading. The decision of which function to call is made at compile time.
- Runtime polymorphism is achieved via virtual functions and inheritance. The function call is resolved at runtime using vtable and vptr mechanisms

# What is a virtual function and how does it enable polymorphism?
A virtual function is a member function in a base class that you expect to override in derived classes. It enables runtime polymorphism by allowing the program to decide at runtime which function to invoke based on the actual object type.
```cpp
class Base {
public:
    virtual void show() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived\n"; }
};
```

# What is the diamond problem in C++ and how is it resolved?
The diamond problem occurs in multiple inheritance when two base classes inherit from the same grandparent class, and a derived class inherits from both. This causes ambiguity due to multiple copies of the grandparent.

Solution: Use virtual inheritance to ensure only one shared instance of the grandparent class exists.
```cpp
class A { public: int x; };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {}; // Only one A
```

# Can a constructor be virtual in C++?
No, constructors cannot be virtual in C++. However, destructors should be virtual in base classes to ensure proper cleanup of derived objects when deleted via a base pointer.

#  What is the difference between virtual and friend in C++
- **virtual** enables runtime polymorphism and is used for functions meant to be overridden.
- **friend** grants access to private/protected members of a class to another class or function. It breaks encapsulation intentionally for specific use cases like operator overloading or helper functions.

# What is an abstract class?
An abstract class contains at least one pure virtual function and cannot be instantiated. It serves as a blueprint for derived classes.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual
};
```

# How does virtual inheritance affect the object layout in memory?
With virtual inheritance, the compiler ensures only one instance of the virtual base class exists, even if it’s inherited multiple times. This introduces a level of indirection (via vtable) and may slightly increase memory overhead but resolves ambiguity.
