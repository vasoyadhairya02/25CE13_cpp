#include <iostream>
using namespace std;

class Wallet
{
    int walletId;
    string userName;
    double balance;

public:
    void setWallet(int id, string name, double bal)
    {
        walletId = id;
        userName = name;
        balance = bal;
    }

    int getWalletId()
    {
        return walletId;
    }

    double getBalance()
    {
        return balance;
    }

    void loadMoney(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Money loaded successfully.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    void transferMoney(Wallet &receiver, double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid transfer amount.\n";
        }
        else if (balance >= amount)
        {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful.\n";
        }
        else
        {
            cout << "Insufficient balance.\n";
        }
    }

    void display()
    {
        cout << "\nWallet ID : " << walletId;
        cout << "\nUser Name : " << userName;
        cout << "\nBalance   : ₹" << balance << endl;
    }
};

int main()
{
    cout<<"Name   : Dhairya Vasoya "<<endl;
    cout<<"ID no. : 25CE135 "<<endl;
    int n;
    cout << "Enter number of users: ";
    cin >> n;

    Wallet w[n];

    for (int i = 0; i < n; i++)
    {
        int id;
        string name;
        double bal;

        cout << "\nEnter details for user " << i + 1 << endl;
        cout << "Wallet ID: ";
        cin >> id;
        cout << "User Name: ";
        cin >> name;
        cout << "Initial Balance: ";
        cin >> bal;

        w[i].setWallet(id, name, bal);
    }

    int choice;
    do
    {
        cout << "\n---- Digital Wallet Menu ----";
        cout << "\n1. Load Money";
        cout << "\n2. Transfer Money";
        cout << "\n3. Display Wallet Details";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            double amt;
            cout << "Enter Wallet ID: ";
            cin >> id;
            cout << "Enter amount to load: ";
            cin >> amt;

            for (int i = 0; i < n; i++)
            {
                if (w[i].getWalletId() == id)
                {
                    w[i].loadMoney(amt);
                }
            }
            break;
        }

        case 2:
        {
            int fromId, toId;
            double amt;
            cout << "Sender Wallet ID: ";
            cin >> fromId;
            cout << "Receiver Wallet ID: ";
            cin >> toId;
            cout << "Enter amount: ";
            cin >> amt;

            Wallet *sender = nullptr;
            Wallet *receiver = nullptr;

            for (int i = 0; i < n; i++)
            {
                if (w[i].getWalletId() == fromId)
                    sender = &w[i];
                if (w[i].getWalletId() == toId)
                    receiver = &w[i];
            }

            if (sender && receiver)
                sender->transferMoney(*receiver, amt);
            else
                cout << "Invalid wallet ID.\n";

            break;
        }

        case 3:
        {
            int id;
            cout << "Enter Wallet ID: ";
            cin >> id;

            for (int i = 0; i < n; i++)
            {
                if (w[i].getWalletId() == id)
                {
                    w[i].display();
                }
            }
            break;
        }

        case 4:
            cout << "Thank you. Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    }
    while (choice != 4);

    return 0;
}
