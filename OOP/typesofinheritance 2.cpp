#include <iostream>

class Shape {
public:
    virtual double area() const {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    std::cout << "Area of the circle: " << circle.area() << std::endl;
    std::cout << "Area of the rectangle: " << rectangle.area() << std::endl;
    return 0;
}
