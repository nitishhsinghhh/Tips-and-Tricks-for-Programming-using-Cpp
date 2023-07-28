#include <iostream>
using namespace std;

class Base {
public:
    void publicMethod() {
        cout << "Public method of Base class" << endl;
    }
protected:
    void protectedMethod() {
        cout << "Protected method of Base class" << endl;
    }
private:
    void privateMethod() {
        cout << "Private method of Base class" << endl;
    }
};

// Private Inheritance
class DerivedPrivate : private Base {
public:
    void accessBaseMembers() {
        publicMethod();       // OK
        protectedMethod();   // OK
        // privateMethod();   // Error: Not accessible
    }
};

// Protected Inheritance
class DerivedProtected : protected Base {
public:
    void accessBaseMembers() {
        publicMethod();       // OK
        protectedMethod();   // OK
        // privateMethod();   // Error: Not accessible
    }
};

// Public Inheritance
class DerivedPublic : public Base {
public:
    void accessBaseMembers() {
        publicMethod();       // OK
        protectedMethod();   // OK
        // privateMethod();   // Error: Not accessible
    }
};

int main() {
    DerivedPrivate derivedPrivate;
    derivedPrivate.accessBaseMembers();  // Calls Base class methods

    DerivedProtected derivedProtected;
    derivedProtected.accessBaseMembers();  // Calls Base class methods

    DerivedPublic derivedPublic;
    derivedPublic.accessBaseMembers();  // Calls Base class methods

    return 0;
}
