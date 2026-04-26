#include "header.h"
#include <iostream>
using namespace std;


class Grade {
protected:
    int marks;

public:
    Grade(int m) { marks = m; }

    virtual void compute() = 0;   
};


class UG : public Grade {
public:
    UG(int m) : Grade(m) {}

    void compute() {
        if(marks >= 50) cout << "UG Pass\n";
        else cout << "UG Fail\n";
    }
};


class PG : public Grade {
public:
    PG(int m) : Grade(m) {}

    void compute() {
        if(marks >= 60) cout << "PG Pass\n";
        else cout << "PG Fail\n";
    }
};

int runProgram() {
    Grade* g;

    UG u(55);
    PG p(55);

    g = &u;
    g->compute();   

    g = &p;
    g->compute();   

    return 0;
}
