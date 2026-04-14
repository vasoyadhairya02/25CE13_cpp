#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    int copies;

public:
    Book(int i, string t, string a, int c) {
        id = i;
        title = t;
        author = a;
        copies = c;
    }

    int getId() {
        return id;
    }

    void issueBook() {
        if (copies > 0) {
            copies--;
            cout << "Book issued successfully.\n";
        } else {
            cout << "No copies available.\n";
        }
    }

    void returnBook() {
        copies++;
        cout << "Book returned successfully.\n";
    }

    void display() {
        cout << "ID: " << id
             << ", Title: " << title
             << ", Author: " << author
             << ", Copies: " << copies << endl;
    }
};

class Library {
private:
    Book* books[50];
    int count;

public:
    Library() {
        count = 0;
    }

    void addBook() {
        int id, copies;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Number of Copies: ";
        cin >> copies;

        books[count++] = new Book(id, title, author, copies);
        cout << "Book added successfully!\n";
    }

    void issueBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getId() == id) {
                books[i]->issueBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getId() == id) {
                books[i]->returnBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void displayTotalBooks() {
        cout << "Total books in library: " << count << endl;
    }
};

int main() {
    cout<<"Name   : Dhairya Vasoya "<<endl;
    cout<<"ID no. : 25CE135 "<<endl;
    Library lib;
    int choice, id;

    do {
        cout << "\n1. Add Book\n2. Issue Book\n3. Return Book\n4. Display Total Books\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.addBook();
            break;
        case 2:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            lib.issueBook(id);
            break;
        case 3:
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
            break;
        case 4:
            lib.displayTotalBooks();
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
