#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

    static int totalAccounts;

public:
    Account(int accNo, string accName, double bal) {
        accountNumber = accNo;
        name = accName;
        balance = bal;
        totalAccounts++;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return false;
        }
        if (balance < amount) {
            cout << "Insufficient balance.\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    bool transfer(Account &receiver, double amount) {
        if (withdraw(amount)) {
            receiver.deposit(amount);
            cout << "Transfer successful.\n";
            return true;
        }
        return false;
    }

    void updateName(string newName) {
        name = newName;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

Account* findAccount(vector<Account> &accounts, int accNo) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            return &acc;
        }
    }
    return nullptr;
}

int main() {
    cout<<"Name : Dhairya Vasoya"<<endl;
    cout<<"ID : 25CE135"<<endl;
    vector<Account> accounts;
    int choice;

    do {
        cout << "\n===== BANK SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Transfer Money\n";
        cout << "4. Update Account Name\n";
        cout << "5. Total Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            accounts.push_back(Account(accNo, name, balance));
            cout << "Account created successfully.\n";
        }

        else if (choice == 2) {
            for (auto &acc : accounts) {
                acc.display();
            }
        }

        else if (choice == 3) {
            int senderNo, receiverNo;
            double amount;

            cout << "Enter Sender Account No: ";
            cin >> senderNo;
            cout << "Enter Receiver Account No: ";
            cin >> receiverNo;
            cout << "Enter Amount: ";
            cin >> amount;

            Account* sender = findAccount(accounts, senderNo);
            Account* receiver = findAccount(accounts, receiverNo);

            if (sender == nullptr || receiver == nullptr) {
                cout << "Invalid account number.\n";
            } else {
                sender->transfer(*receiver, amount);
            }
        }

        else if (choice == 4) {
            int accNo;
            string newName;

            cout << "Enter Account Number: ";
            cin >> accNo;

            Account* acc = findAccount(accounts, accNo);
            if (acc == nullptr) {
                cout << "Account not found.\n";
            } else {
                cout << "Enter New Name: ";
                cin >> newName;
                acc->updateName(newName);
                cout << "Name updated successfully.\n";
            }
        }

        else if (choice == 5) {
            cout << "Total Accounts: " << Account::getTotalAccounts() << endl;
        }

    } while (choice != 6);

    return 0;
}
