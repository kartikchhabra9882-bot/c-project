#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    bool available;

    Book(int i = 0, string t = "") {
        id = i;
        title = t;
        available = true;
    }
};

int main() {
    Book books[20];
    int count = 0, choice, id;
    string title;

    do {
        cout << "\n1. Add Book\n2. Show Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            books[count++] = Book(id, title);
            cout << "Book added successfully!\n";
        }

        else if (choice == 2) {
            cout << "\nID\tTitle\t\tStatus\n";

            for (int i = 0; i < count; i++) {
                cout << books[i].id << "\t" << books[i].title << "\t\t"
                     << (books[i].available ? "Available" : "Issued") << endl;
            }
        }

        else if (choice == 3) {
            cout << "Enter Book ID to issue: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].id == id) {
                    if (books[i].available) {
                        books[i].available = false;
                        cout << "Book issued successfully!\n";
                    } else {
                        cout << "Book is already issued!\n";
                    }
                    break;
                }
            }
        }

        else if (choice == 4) {
            cout << "Enter Book ID to return: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].id == id) {
                    books[i].available = true;
                    cout << "Book returned successfully!\n";
                    break;
                }
            }
        }

    } while (choice != 5);

    cout << "Program ended.\n";
    return 0;
}
