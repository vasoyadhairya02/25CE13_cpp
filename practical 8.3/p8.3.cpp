#include "header.h"
#include <iostream>
using namespace std;

string logArr[20];
int idx = 0;

void log(string s) { logArr[idx++] = s; }


class InsufficientFunds {};

class BankAccount {
    double balance;

public:
    BankAccount(double b) { balance = b; }

    void deposit(double amt) {
        log("Enter deposit()");
        if(amt <= 0) throw "Invalid deposit!";
        balance += amt;
        log("Exit deposit()");
    }

    void withdraw(double amt) {
        log("Enter withdraw()");
        if(amt > balance) throw InsufficientFunds();
        balance -= amt;
        log("Exit withdraw()");
    }

    double getBalance() { return balance; }
};


void processWithdraw(BankAccount &acc, double amt) {
    log("Enter processWithdraw()");
    acc.withdraw(amt);   
    log("Exit processWithdraw()");
}

int runProgram() {
    BankAccount acc(1000);

    try {
        log("Start main");

        acc.deposit(500);        
        processWithdraw(acc, 200); 
        processWithdraw(acc, 2000); 

        log("End main");
    }

    catch(InsufficientFunds) {
        log("Caught InsufficientFunds");
        cout << "Error: Not enough balance!\n";
    }
    catch(const char* msg) {
        log("Caught Other Exception");
        cout << msg << endl;
    }

    
    cout << "\n--- Logs ---\n";
    for(int i=0;i<idx;i++)
        cout << logArr[i] << endl;

    cout << "\nFinal Balance: " << acc.getBalance();

    return 0;
}
