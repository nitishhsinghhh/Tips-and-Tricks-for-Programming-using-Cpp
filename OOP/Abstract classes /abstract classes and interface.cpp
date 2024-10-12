#include <iostream>

using namespace std;

// Abstract class
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() = 0;
    // Normal member function
    void sleep() {
        cout << "Zzz..." << endl;
    }
};

// Interface
class Drawable {
public:
    // Pure virtual functions
    virtual void draw() = 0;
    virtual void setPosition(int x, int y) = 0;
};

// Class that inherits from Animal and implements Drawable interface
class Cat : public Animal, public Drawable {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
    void draw() override {
        cout << "Drawing a cat..." << endl;
    }
    void setPosition(int x, int y) override {
        cout << "Setting cat position to (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Cat cat;
    cat.makeSound(); // Meow!
    cat.draw(); // Drawing a cat...
    cat.setPosition(10, 20); // Setting cat position to (10, 20)
    cat.sleep(); // Zzz...
    return 0;
}
