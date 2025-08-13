# Abstract classes

Abstract classes act as expressions of general concepts from which more specific classes can be derived. You can't create an object of an abstract class type. However, you can use pointers and references to abstract class types.

You create an abstract class by declaring at least one pure virtual member function. That's a virtual function declared by using the *pure* specifier (= 0) syntax. Classes derived from the abstract class must implement the pure virtual function or they, too, are abstract classes.

The intent of class `Account` is to provide general functionality, but objects of type `Account` are too general to be useful. That means `Account` is a good candidate for an abstract class:

```cpp
/**
 * @brief Demonstrates abstract classes and pure virtual functions in C++.
 * @details
 * This example defines an abstract class `Account` with a pure virtual function
 * and a derived class `SavingsAccount` that provides an implementation.
 * 
 * Compile with:
 * @code
 * cl /LD deriv_AbstractClasses.cpp
 * @endcode
 */

#include <iostream>

/**
 * @class Account
 * @brief Abstract base class representing a generic account.
 */
class Account {
public:
    /**
     * @brief Constructs an Account with the given balance.
     * @param d Initial account balance.
     */
    Account(double d) : _balance(d) {}

    /**
     * @brief Retrieves the current balance.
     * @return The account balance.
     */
    virtual double GetBalance() {
        return _balance;
    }

    /**
     * @brief Prints the account balance.
     * @note This is a pure virtual function and must be implemented by derived classes.
     */
    virtual void PrintBalance() = 0;

protected:
    double _balance; ///< Current account balance.
};

/**
 * @class SavingsAccount
 * @brief Represents a savings account derived from Account.
 */
class SavingsAccount : public Account {
public:
    /**
     * @brief Constructs a SavingsAccount with the given balance.
     * @param d Initial account balance.
     */
    SavingsAccount(double d) : Account(d) {}

    /**
     * @brief Prints the savings account balance to standard output.
     */
    void PrintBalance() override {
        std::cout << "Savings Account Balance: $" << GetBalance() << "\n";
    }
};

/**
 * @brief Main entry point of the program.
 * @return Exit status code.
 */
int main() {
    SavingsAccount sa(1000.50);
    sa.PrintBalance();
    return 0;
}
```

The only difference between this declaration and the previous one is that `PrintBalance` is declared with the pure specifier (`= 0`).

## Restrictions on abstract classes

Abstract classes can't be used for:
- Variables or member data
- Argument types
- Function return types
- Types of explicit conversions

If the constructor for an abstract class calls a pure virtual function, either directly or indirectly, the result is undefined. However, constructors and destructors for abstract classes can call other member functions.

## Defined pure virtual functions

Pure virtual functions in abstract classes can be *defined*, or have an implementation. You can only call such functions by using the fully qualified syntax:

*abstract-class-name*::*function-name*()

Defined pure virtual functions are helpful when you design class hierarchies whose base classes include pure virtual destructors. That's because base class destructors are always called during object destruction. Consider the following example:

```cpp
/**
 * @brief Demonstrates restrictions and usage of abstract classes with a pure virtual destructor.
 * @details
 * This example defines an abstract base class with a pure virtual destructor.
 * Even though the destructor is pure virtual, it must still have a definition.
 * The derived class overrides the destructor (implicitly or explicitly), and 
 * objects of the derived class can be created.
 */

#include <iostream>

/**
 * @class base
 * @brief Abstract base class with a pure virtual destructor.
 * @details
 * Declaring a pure virtual destructor makes the class abstract,
 * but a definition for the destructor is still required to ensure
 * proper cleanup of derived objects.
 */
class base {
public:
    /**
     * @brief Default constructor for base.
     */
    base() {}

    /**
     * @brief Pure virtual destructor.
     * @note Even though it's pure virtual, it **must** be defined
     *       outside the class to allow proper destruction.
     */
    virtual ~base() = 0;
};

// Definition of the pure virtual destructor
base::~base() {}

/**
 * @class derived
 * @brief Concrete class derived from base.
 */
class derived : public base {
public:
    /**
     * @brief Default constructor for derived.
     */
    derived() {}

    /**
     * @brief Destructor for derived.
     */
    ~derived() {}
};

/**
 * @brief Program entry point.
 * @return int Exit code.
 */
int main() {
    derived aDerived; ///< Destructor will be called automatically at scope end.
    return 0;
}
```

The example shows how a Microsoft compiler extension lets you add an inline definition to pure virtual `~base()`. You can also define it outside the class by using `base::~base() {}`.

When the object `aDerived` goes out of scope, the destructor for class `derived` is called. The compiler generates code to implicitly call the destructor for class `base` after the `derived` destructor. The empty implementation for the pure virtual function `~base` ensures that at least some implementation exists for the function. Without it, the linker generates an unresolved external symbol error for the implicit call.

> [!NOTE]
> In the preceding example, the pure virtual function `base::~base` is called implicitly from `derived::~derived`. It's also possible to call pure virtual functions explicitly by using a fully qualified member-function name. Such functions must have an implementation, or the call results in an error at link time.
