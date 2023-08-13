# Virtual Functions

A virtual function is a member function that you expect to be redefined in derived classes. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.

Virtual functions ensure that the correct function is called for an object, regardless of the expression used to make the function call.

Suppose a base class contains a function declared as virtual and a derived class defines the same function. The function from the derived class is invoked for objects of the derived class, even if it is called using a pointer or reference to the base class. The following example shows a base class that provides an implementation of the `PrintBalance` function and two derived classes

Please use the following link to access the [CPP Code](./PrintBalance%20.cpp)


In the preceding code, the calls to PrintBalance are identical, except for the object pAccount points to. Because PrintBalance is virtual, the version of the function defined for each object is called. The PrintBalance function in the derived classes CheckingAccount and SavingsAccount "override" the function in the base class Account.

If a class is declared that does not provide an overriding implementation of the PrintBalance function, the default implementation from the base class Account is used.

Functions in derived classes override virtual functions in base classes only if their type is the same. A function in a derived class cannot differ from a virtual function in a base class in its return type only; the argument list must differ as well.

When calling a function using pointers or references, the following rules apply:

1. A call to a virtual function is resolved according to the underlying type of object for which it is called.
2. A call to a nonvirtual function is resolved according to the type of the pointer or reference.
