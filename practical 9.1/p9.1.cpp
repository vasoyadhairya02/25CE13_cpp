#include "header.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int runProgram() {
    vector<int> v;
    int n, x;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i=0;i<n;i++) {
        cin >> x;
        v.push_back(x);
    }

    
    reverse(v.begin(), v.end());

    cout << "\nReversed (STL): ";
    for(auto i : v) cout << i << " ";

    
    vector<int> v2 = v;  
    auto start = v2.begin();
    auto end = v2.end() - 1;

    while(start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    cout << "\nReversed (Manual): ";
    for(auto i : v2) cout << i << " ";

    return 0;
}
