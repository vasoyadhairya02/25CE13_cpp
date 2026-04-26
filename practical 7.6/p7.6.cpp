#include "header.h"
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {   
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
    int* ptr;
public:
    Derived() {
        ptr = new int[5];
        cout << "Derived Constructor\n";
    }

    ~Derived() {
        delete[] ptr;
        cout << "Derived Destructor\n";
    }
};

int runProgram() {
    Base* b = new Derived();
    delete b;   
    return 0;
}
