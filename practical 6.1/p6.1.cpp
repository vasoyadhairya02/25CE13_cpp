#include "header.h"
#include <iostream>
using namespace std;

class Shape {
protected:
    double r;   

public:
    void setRadius(double x) {
        if(x > 0) r = x;
        else r = 0;
    }
};

class Circle : public Shape {
public:
    double area() {
        return 3.14 * r * r;
    }

    void show() {
        cout << "Radius: " << r
             << " Area: " << area() << endl;
    }
};

int runProgram() {
    int n = 3;
    Circle c[3];   

    for(int i=0;i<n;i++) {
        double x;
        cout << "Enter radius: ";
        cin >> x;
        c[i].setRadius(x);
    }

    cout << "\nResults:\n";
    for(int i=0;i<n;i++)
        c[i].show();

    return 0;
}
