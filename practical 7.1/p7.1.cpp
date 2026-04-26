#include "header.h"
#include <iostream>
using namespace std;

class Calc {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    float add(int a, float b) {
        return a + b;
    }

    
    int add(int arr[], int n) {
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        return sum;
    }
};

int runProgram() {
    Calc c;

    cout << "Int: " << c.add(2,3) << endl;
    cout << "Float: " << c.add(2.5f,3.5f) << endl;
    cout << "Mixed: " << c.add(2,3.5f) << endl;

    int arr[3] = {1,2,3};
    cout << "Array Sum: " << c.add(arr,3);

    return 0;
}
