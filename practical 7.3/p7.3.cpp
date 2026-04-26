#include "header.h"
#include <iostream>
using namespace std;

class Fahrenheit;  

class Celsius {
    float c;

public:
    Celsius(float x=0) { c = x; }

    
    operator Fahrenheit();

    float get() { return c; }
};

class Fahrenheit {
    float f;

public:
    Fahrenheit(float x=0) { f = x; }

    
    operator Celsius() {
        return Celsius((f - 32) * 5 / 9);
    }

    
    bool operator == (Fahrenheit x) {
        return f == x.f;
    }

    float get() { return f; }

    friend class Celsius;
};


Celsius::operator Fahrenheit() {
    return Fahrenheit((c * 9 / 5) + 32);
}

int runProgram() {
    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;   
    cout << "Fahrenheit: " << f1.get() << endl;

    Celsius c2;
    c2 = f1;   
    cout << "Celsius: " << c2.get() << endl;

    
    Fahrenheit f2(77);
    if(f1 == f2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    return 0;
}
