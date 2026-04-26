#include "header.h"
#include <iostream>
using namespace std;

class Complex {
    int r, i;

public:
    Complex(int a=0, int b=0) {
        r = a; i = b;
    }

    
    Complex operator + (Complex c) {
        return Complex(r + c.r, i + c.i);
    }

    
    Complex operator - (Complex c) {
        return Complex(r - c.r, i - c.i);
    }

    void show() {
        cout << r << " + " << i << "i\n";
    }
};

int runProgram() {
    Complex c1(3,2), c2(1,4);

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    cout << "Addition: ";
    c3.show();

    cout << "Subtraction: ";
    c4.show();

    return 0;
}
