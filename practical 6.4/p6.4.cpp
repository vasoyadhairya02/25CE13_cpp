#include "header.h"
#include <iostream>
using namespace std;

class Account {
protected:
    int accNo;
    double balance;

public:
    Account(int a, double b) {
        accNo = a;
        balance = b;
    }

    void deposit(double amt) {
        balance += amt;
    }

    virtual void withdraw(double amt) {
        if(amt <= balance) balance -= amt;
        else cout << "Insufficient balance\n";
    }

    void show() {
        cout << "Acc: " << accNo
             << " Balance: " << balance << endl;
    }

    ~Account() {
        
    }
};

class Savings : public Account {
    double rate;

public:
    Savings(int a,double b,double r) : Account(a,b) {
        rate = r;
    }

    void addInterest() {
        balance += balance * rate / 100;
    }
};

class Current : public Account {
    double limit;

public:
    Current(int a,double b,double l) : Account(a,b) {
        limit = l;
    }

    void withdraw(double amt) {
        if(amt <= balance + limit)
            balance -= amt;
        else
            cout << "Over limit!\n";
    }
};

int runProgram() {
    Savings s(101,1000,5);
    Current c(102,2000,500);

    s.deposit(500);
    s.addInterest();
    s.show();

    c.withdraw(2300); 
    c.show();

    return 0;
}
