#include "header.h"
#include <iostream>
using namespace std;

int runProgram() {
    int a, b;

    try {
        cout << "Enter two integers: ";
        cin >> a >> b;

        
        if(cin.fail())
            throw "Invalid input! Enter integers only.";

        
        if(b == 0)
            throw "Division by zero error!";

        cout << "Result = " << a / b;
    }

    catch(const char* msg) {
        cout << "Error: " << msg;
    }

    return 0;
}
