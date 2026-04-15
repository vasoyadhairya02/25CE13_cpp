#include<iostream>
#include<cmath>
using namespace std;
class loan
{
private:
    int lid;
    string name;
    long double amount;
    float rate;
    int tenure;
    double emi;


public:

    void calculateEMI();
    void addACC();
    void display();
    int getID()
    {
        return lid;
    }

};

void loan::calculateEMI()
{

    cout<<"Enter Principal Amount: ";
    cin>>amount;
    cout<<"Enter Rate: ";
    cin>>rate;
    cout<<"Enter tenure:";
    cin>>tenure;

    emi=amount*(rate/1200)*pow(1+(rate/1200),tenure)/(pow(1+(rate/1200),tenure)-1);

    cout<<"The calculated emi is: "<<emi<<endl;
}

void loan::addACC()
{
    fflush(stdin);
    cout<<"Enter Applicant Name: ";
    getline(cin,name);
    cout<<"Enter Loan ID: ";
    cin>>lid;
}

void loan::display()
{
    cout<<endl<<"Name of the Account Holder: "<<name<<endl<<"Loan ID: "<<lid<<endl<<"Total Loan Amount: "<<amount<<endl<<"Annual Interest Rate: "<<rate<<endl<<"Loan Tenure(months): "<<tenure<<endl<<"EMI: "<<emi<<endl<<endl;
}

int main()
{
    cout<<"Name : Dhairya Vasoya"<<endl;
    cout<<"ID : 25CE135"<<endl;
    loan account[10];
    int n=0;
    int searchid;
    bool found;
    int i;
    menu:
    cout<<endl<<"1. Add Loan Account and Calculate EMI"<<endl;
    cout<<"2. Display Account Details"<<endl;
    cout<<"3. Exit"<<endl<<endl;

    int choice;
    cout<<"Enter Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        if(n<10)
        {
            account[n].addACC();
            cout<<"Account created successfully!"<<endl;
            account[n].calculateEMI();
            n++;
        }
        else
            cout<<"No more space for new account.";
            goto menu;

    case 2:
        cout << "Enter Loan ID to search: ";
        cin >> searchid;
        found = false;
        for(i = 0; i < n; i++)
            {
            if(account[i].getID() == searchid)
            {
                account[i].display();
                found = true;
                break;
            }
            }
            if(!found)
                cout << "Account not found." << endl;
        goto menu;

    case 3:
        cout<<"Exiting..";
    default:
        cout<<"Enter a valid choice"<<endl;
    }


}
