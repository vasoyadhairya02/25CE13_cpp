#include "header.h"
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "No shape\n";
    }
};

class Rectangle : public Shape {
    int l, w;
public:
    Rectangle(int a, int b) { l=a; w=b; }

    void area() {
        cout << "Rectangle Area: " << l*w << endl;
    }
};

class Circle : public Shape {
    int r;
public:
    Circle(int x) { r=x; }

    void area() {
        cout << "Circle Area: " << 3.14*r*r << endl;
    }
};

int runProgram() {
    Shape* s;

    Rectangle r(4,5);
    Circle c(3);

    s = &r;
    s->area();   

    s = &c;
    s->area();   

    return 0;
}
