#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int copies;
};

Book books[50];
int bookCount = 0;

void addBook() {
    cout << "Enter Book ID: ";
    cin >> books[bookCount].id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, books[bookCount].title);

    cout << "Enter Author: ";
    getline(cin, books[bookCount].author);

    cout << "Enter Number of Copies: ";
    cin >> books[bookCount].copies;

    bookCount++;
    cout << "Book added successfully!\n";
}


void issueBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].copies > 0) {
                books[i].copies--;
                cout << "Book issued successfully.\n";
            } else {
                cout << "No copies available.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}


void returnBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            books[i].copies++;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}


void displayTotalBooks() {
    cout << "Total number of books: " << bookCount << endl;
}

int main() {
    cout<<"Name   : Dhairya Vasoya "<<endl;
    cout<<"ID no. : 25CE135 "<<endl;
    int choice, id;

    do {
        cout << "\n1. Add Book\n2. Issue Book\n3. Return Book\n4. Display Total Books\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            issueBook(id);
            break;
        case 3:
            cout << "Enter Book ID to return: ";
            cin >> id;
            returnBook(id);
            break;
        case 4:
            displayTotalBooks();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

