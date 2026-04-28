#include <iostream>

#include <string>

#include <cmath>

// ============================================================

// CLASS DEFINITIONS

// ============================================================

class Point {

private:

    double x;

    double y;

public:

    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }

    double getY() const { return y; }

    void display() const { std::cout << "(" << x << ", " << y << ")"; }

    friend class Rectangle;

};

class Rectangle {

private:

    Point topLeft;

    Point bottomRight;

public:

    Rectangle(double x1, double y1, double x2, double y2)

        : topLeft(x1, y1), bottomRight(x2, y2) {}

    double getWidth() const { return std::abs(bottomRight.x - topLeft.x); }

    double getHeight() const { return std::abs(topLeft.y - bottomRight.y); }

    double getArea() const { return getWidth() * getHeight(); }

    void display() const {

        std::cout << "Rectangle[";

        topLeft.display();

        std::cout << " to ";

        bottomRight.display();

        std::cout << "]";

    }

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);

};

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {

    return r1.getArea() == r2.getArea();

}

class ConstDemo {

private:

    int value;

public:

    ConstDemo(int v) : value(v) {}

    int getValue() const { return value; }

    void doubleValue() { value *= 2; }

    int constGetDouble() const { return value * 2; }

};

// ============================================================

// MAIN

// ============================================================

int main() {

    std::cout << "--- Rectangle & Point Test ---" << std::endl;

    Rectangle rect1(0, 10, 5, 0);

    Rectangle rect2(2, 5, 7, -5);

    rect1.display();

    std::cout << "\nArea of rect1: " << rect1.getArea() << std::endl;

    rect2.display();

    std::cout << "\nArea of rect2: " << rect2.getArea() << std::endl;

    std::cout << "Are rect1 and rect2 the same size? "
<< (isSameSize(rect1, rect2) ? "Yes" : "No") << std::endl;

    std::cout << "\n--- ConstDemo Test ---" << std::endl;

    ConstDemo demo(10);

    std::cout << "Original demo value: " << demo.getValue() << std::endl;

    demo.doubleValue();

    std::cout << "After doubleValue(): " << demo.getValue() << std::endl;

    const ConstDemo constDemo(100);

    std::cout << "\nConst obj initial value: " << constDemo.getValue() << std::endl;

    std::cout << "Const obj constGetDouble() result: "
<< constDemo.constGetDouble() << std::endl;

    std::cout << "Const obj value remains unchanged: "
<< constDemo.getValue() << std::endl;

    return 0;

}
 
