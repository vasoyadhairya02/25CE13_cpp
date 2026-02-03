#include<iostream>
using namespace std;

class bank_account
{
    char account_name[20];
    double balance;

public:

    double account_number;
    void setdetail(char nam[20],double num,double bal);
    void deposit(int d);
    void withdraw(int w);
    void showbalance();
    void numberofaccount(int i);

};

int main()
{
    bank_account b[10];
    int choice;
    double accnumber,bal;
    char accname[20];
    int depo,withdr;
    int i=0;
    int found=-1;
    cout<<"Name   : Dhairya Vasoya "<<endl;
    cout<<"ID no. : 25CE135 "<<endl;

menu:

    cout<<endl;
    cout<<"\n1.Create Account\n2.Deposit\n3.Withdraw\n4.CheckBalance\n5.Exit\n";

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"Enter the Account Holder name: ";
        cin>>accname;

        cout<<"Enter the Account Number: ";
        cin>>accnumber;

        cout<<"Add some intial balance(>500): ";
        cin>>bal;

        b[i].setdetail(accname,accnumber,bal);

        i++;
        goto menu;

    case 2:

        cout<<"Enter account number: ";
        cin>>accnumber;

        for(int i=0; i<9; i++)
        {
            if(b[i].account_number==accnumber)
            {
                found=i;
            }
        }

        if(found==-1)
        {
            cout<<"Account not found!!";
            goto menu;
        }
        else
        {
            cout<<"Account Found\n";
        }



        cout<<"Enter amount you want to deposit: ";
        cin>>depo;

        b[found].deposit(depo);

        b[found].showbalance();

        goto menu;

    case 3:



        cout<<"Enter account number: ";
        cin>>accnumber;
        for(int i=0; i<9; i++)
        {
            if(b[i].account_number==accnumber)
            {
                found=i;
            }
        }

        if(found==-1)
        {
            cout<<"Account not found!!";
            goto menu;
        }
        else
        {
            cout<<"Account Found\n";
        }

        cout<<"Enter amount to be withdraw: ";
        cin>>withdr;

        b[found].withdraw(withdr);

        b[found].showbalance();

        goto menu;

    case 4:


        cout<<"Enter account number: ";
        cin>>accnumber;
        for(int i=0; i<9; i++)
        {
            if(b[i].account_number==accnumber)
            {
                found=i;
            }
        }

        if(found==-1)
        {
            cout<<"Account not found!!";
            goto menu;
        }
        else
        {
            cout<<"Account Found\n";
        }

        b[found].showbalance();

        goto menu;

    case 5:

        break;


    default:
        cout<<"Enter a Valid choice!!";

        goto menu;
    }
    cout<<endl;
    cout<<"Thank you!";
}
void bank_account::setdetail(char nam[20],double num,double bal)
{
    account_name[20]=nam[20];
    account_number=num;
    balance=bal;
}

void bank_account::deposit(int d)
{
    balance+=d;
}

void bank_account::withdraw(int w)
{
    if(w>balance)
    {
        cout<<"Insufficient Balance!!\n";
    }
    else
    {
        balance-=w;
        cout<<"Withdraw amount is: "<<w<<endl;
    }
}
void bank_account::showbalance()
{
    cout<<"Balance: "<<balance;
}
void bank_account::numberofaccount(int i)
{
    i++;
}
