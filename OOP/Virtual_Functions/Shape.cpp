#include <iostream>

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    shape1->draw(); // Calls the draw() function of the Circle class
    shape2->draw(); // Calls the draw() function of the Square class
    delete shape1;
    delete shape2;
    return 0;
}
