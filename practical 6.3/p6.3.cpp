#include "header.h"
#include <iostream>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) {
        fuelType = f;
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string b) {
        brandName = b;
    }
};

class Car : public Fuel, public Brand {
public:
    Car(string f, string b) : Fuel(f), Brand(b) {}

    void show() {
        cout << "Brand: " << brandName
             << " Fuel: " << fuelType << endl;
    }
};

int runProgram() {
    
    Car c[3] = {
        Car("Petrol","Toyota"),
        Car("Diesel","Hyundai"),
        Car("Electric","Tesla")
    };

    for(int i=0;i<3;i++)
        c[i].show();

    return 0;
}
