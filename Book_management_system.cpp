#include <iostream>
#include <cstdlib> // For system("cls")
using namespace std;

// Base Class
class bookVAR {
public:
    int book_id, price, pages;
    string name, aut, pub;

    // Constructor
    bookVAR() {
        book_id = 0;
        name = "";
        aut = "";
        pub = "";
        price = 0;
        pages = 0;
    }

    // Destructor
    ~bookVAR() {}

    // Virtual Function 
    virtual void menu() {}

    // Friend Function declaration
    friend void showBook(const bookVAR&);

    // Operator Overloading declaration
    friend bool operator==(const bookVAR&, const bookVAR&);
} b[500];

// Derived Class
class bookFUNC : public bookVAR {
public:
    // Static Variable
    static int i;

    // Inline Functions
    inline void menu();
    inline void add();
    inline void search();
    inline void update();
    inline void del();
    inline void show();
};

// Operator Overloading definition
bool operator==(const bookVAR& book1, const bookVAR& book2) {
    return book1.book_id == book2.book_id;
}

// Static Variable Initialization
int bookFUNC::i = 0;

void bookFUNC::menu() {
    int choice;
    while (true) {
        system("cls");
        cout << "\n\n--------------------------Book Management System--------------------------";
        cout << "\n\n 1: Add New Book ";
        cout << "\n\n 2. Search Book ";
        cout << "\n\n 3. Update Book ";
        cout << "\n\n 4. Delete Book ";
        cout << "\n\n 5. Show Books ";
        cout << "\n\n 6. Exit ";
        cout << "\n\n : ";
        cin >> choice;

        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        case 5:
            show();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\n Invalid choice....Please try again....";
        }
        cin.ignore();
        cin.get(); // To pause the system and wait for the user to press a key
    }
}

void bookFUNC::add() {
    system("cls");
    cout << "\n\n--------------------------Book Management System--------------------------";
    cout << "\n\nEnter Book ID : ";
    cin >> b[i].book_id;

    for (int a = 0; a < i; a++) {
        if (b[a] == b[i]) {
            cout << "\n\n Book ID Already Exists....";
            cin.get();
            return;
        }
    }

    cout << "\n\nEnter Book Name : ";
    cin >> b[i].name;
    cout << "\n\nEnter Author Name : ";
    cin >> b[i].aut;
    cout << "\n\nEnter Publisher Name : ";
    cin >> b[i].pub;
    cout << "\n\nEnter Pages : ";
    cin >> b[i].pages;
    cout << "\n\nEnter Price : ";
    cin >> b[i].price;
    cout << "\n\n\n\t\t New Book Added Successfully....";
    i++;
}

void bookFUNC::search() {
    system("cls");
    int id, found = 0, choice;
    string name;
    cout << "\n\n--------------------------Book Management System--------------------------";
    if (i == 0) {
        cout << "\n\n\n Data Base is Empty....";
        return;
    }

    cout << "\n\n 1.Search According to Book ID ";
    cout << "\n\n 2.Search According to Book Name ";
    cout << "\n\n 3.Search According to Author Name ";
    cout << "\n\n 4.Search According to Publisher Name ";
    cout << "\n\n : ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\n\nEnter Book ID : ";
        cin >> id;
        for (int a = 0; a < i; a++) {
            if (id == b[a].book_id) {
                system("cls");
                showBook(b[a]);
                found++;
            }
        }
        if (!found) cout << "\n\n Book ID not found....";
        break;

    case 2:
        cout << "\n\nEnter Book Name : ";
        cin >> name;
        for (int a = 0; a < i; a++) {
            if (name == b[a].name) {
                showBook(b[a]);
                found++;
            }
        }
        if (!found) cout << "\n\n Book Name not found....";
        break;

    case 3:
        cout << "\n\nEnter Author Name : ";
        cin >> name;
        for (int a = 0; a < i; a++) {
            if (name == b[a].aut) {
                showBook(b[a]);
                found++;
            }
        }
        if (!found) cout << "\n\n Author Name not found....";
        break;

    case 4:
        cout << "\n\nEnter Publisher Name : ";
        cin >> name;
        for (int a = 0; a < i; a++) {
            if (name == b[a].pub) {
                showBook(b[a]);
                found++;
            }
        }
        if (!found) cout << "\n\n Publisher Name not found....";
        break;

    default:
        cout << "\n\n Invalid choice....";
    }
}

void bookFUNC::update() {
    system("cls");
    int id, found = 0;
    cout << "\n\n--------------------------Book Management System--------------------------";

    if (i == 0) {
        cout << "\n\n Data Base is Empty...";
        return;
    }

    cout << "\n\nEnter Book ID For Update : ";
    cin >> id;
    for (int a = 0; a < i; a++) {
        if (id == b[a].book_id) {
            system("cls");
            cout << "\n\nEnter new details for the book:";

            cout << "\n\n Book Name : ";
            cin >> b[a].name;
            cout << "\n\n Author Name : ";
            cin >> b[a].aut;
            cout << "\n\n Publisher Name : ";
            cin >> b[a].pub;
            cout << "\n\n Pages : ";
            cin >> b[a].pages;
            cout << "\n\n Price : ";
            cin >> b[a].price;

            cout << "\n\n\n\t Book Updated Successfully...";
            found++;
        }
    }
    if (!found) cout << "\n\n Book ID not found...";
}

void bookFUNC::del() {
    system("cls");
    int id, found = 0;
    cout << "\n\n--------------------------Book Management System--------------------------";

    if (i == 0) {
        cout << "\n\n Data Base is Empty...";
        return;
    }

    cout << "\n\nEnter Book ID For Deletion : ";
    cin >> id;
    for (int a = 0; a < i; a++) {
        if (id == b[a].book_id) {
            for (int k = a; k < i - 1; k++) {
                b[k] = b[k + 1];
            }
            cout << "\n\n\n\t Book Deleted Successfully.....";
            i--;
            found++;
            break;
        }
    }
    if (!found) cout << "\n\n Book ID not found...";
}

void bookFUNC::show() {
    system("cls");
    cout << "\n\n--------------------------Book Management System--------------------------";

    if (i == 0) {
        cout << "\n\n Data Base is Empty....";
    } else {
        for (int a = 0; a < i; a++) {
            showBook(b[a]);
        }
    }
}

// Friend Function Definition
void showBook(const bookVAR& book) {
    cout << "\n\n Book ID : " << book.book_id;
    cout << "\n\n Book Name : " << book.name;
    cout << "\n\n Author Name : " << book.aut;
    cout << "\n\n Publisher Name : " << book.pub;
    cout << "\n\n Pages : " << book.pages;
    cout << "\n\n Price : " << book.price;
    cout << "\n\n\n===============================";
}

int main() {
    bookVAR *p;
    bookFUNC obj;
    p = &obj;
    p->menu();
    return 0;
}
