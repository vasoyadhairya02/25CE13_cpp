#include "header.h"
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n,a) {
        empID = id;
    }
};

class Manager : public Employee {
    string dept;

public:
    Manager(string n, int a, int id, string d)
        : Employee(n,a,id) {
        dept = d;
    }

    void show() {
        cout << "Name: " << name
             << " Age: " << age
             << " ID: " << empID
             << " Dept: " << dept << endl;
    }
};

int runProgram() {
    Manager m[2] = {
        Manager("A",30,101,"HR"),
        Manager("B",40,102,"IT")
    };

    for(int i=0;i<2;i++)
        m[i].show();

    return 0;
}
