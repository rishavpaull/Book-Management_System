#include <iostream>
#include <conio.h>
#include <ctime> // for handling dates
using namespace std;

class bookVAR
{
public:
    int book_id, price, pages;
    string name, aut, pub;
    bookVAR()
    {
        book_id = 0;
        name = "";
        aut = "";
        pub = "";
        price = 0;
        pages = 0;
    }
    ~bookVAR() {}
    virtual void menu() {}
    friend void showBook(bookVAR);
    friend bool operator==(bookVAR, bookVAR);
} b[500];

class bookFUNC : public bookVAR
{

public:
    static int i;
    inline void menu();
    inline void add();
    inline void search();
    inline void update();
    inline void del();
    inline void show();
    inline void borrowBook();
    inline void returnBook();
    inline double calculateFine(int daysLate);
};

int bookFUNC::i;

void bookFUNC::menu()
{
p:
    system("cls");
    int choice;
    cout << "\n\n--------------------------Book Management System--------------------------";
    cout << "\n\n 1: Add New Book ";
    cout << "\n\n 2. Search Book ";
    cout << "\n\n 3. Update Book ";
    cout << "\n\n 4. Delete Book ";
    cout << "\n\n 5. Show Books ";
    cout << "\n\n 6. Borrow Book ";
    cout << "\n\n 7. Return Book ";
    cout << "\n\n 8. Exit ";
    cout << "\n\n : ";
    cin >> choice;
    switch (choice)
    {
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
        borrowBook();
        break;
    case 7:
        returnBook();
        break;
    case 8:
        exit(0);
    default:
        cout << "\n\n Invalid choice....Please try again....";
    }
    getch();
    goto p;
}

bool operator==(bookVAR book1, bookVAR book2)
{
    if (book1.book_id == book2.book_id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bookFUNC::add()
{
p:
    system("cls");
    cout << "\n\n--------------------------Book Management System--------------------------";
    cout << "\n\nEnter Book ID : ";
    cin >> b[i].book_id;
    for (int a = 0; a < i; a++)
    {
        if (operator==(b[a], b[i]))
        {
            cout << "\n\n Book ID Already Exist....";
            getch();
            goto p;
        }
    }
    
    cin.ignore();
    cout << "\n\nEnter Book Name : ";
getline(cin, b[i].name);

cout << "\n\nEnter Author Name : ";
getline(cin, b[i].aut);

cout << "\n\nEnter Publisher Name : ";
getline(cin, b[i].pub);


    cout << "\n\nEnter Pages : ";
    cin >> b[i].pages;
    cout << "\n\nEnter Price : ";
    cin >> b[i].price;
    cout << "\n\n\n\t\t New Book Added Successfully....";
    i++;
}

void bookFUNC::search()
{
    system("cls");
    int id, found = 0, choice;
    string name;
    cout << "\n\n--------------------------Book Management System--------------------------";
    if (i == 0)
    {
        cout << "\n\n\n Data Base is Empty....";
    }
    else
    {
        cout << "\n\n 1.Search According Book ID ";
        cout << "\n\n 2.Search According Book Name ";
        cout << "\n\n 3.Search According Author Name ";
        cout << "\n\n 4.Search According Publisher Name ";
        cout << "\n\n : ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\n\nEnter Book ID : ";
            cin >> id;
            cout << "\n\n--------------------------Book Management System--------------------------";

            for (int a = 0; a < i; a++)
            {
                if (id == b[a].book_id)
                {
                    system("cls");
                    cout << "\n\n Book ID " << b[a].book_id;
                    cout << "\n\n Book Name : " << b[a].name;
                    cout << "\n\n Author Name : " << b[a].aut;
                    cout << "\n\n Publisher Name : " << b[a].pub;
                    cout << "\n\n Pages : " << b[a].pages;
                    cout << "\n\n Price : " << b[a].price;
                    cout << "\n\n\n=============================";
                    found++;
                }
            }
            if (found == 0)
            {
                cout << "\n\n\n Book Id not found....";
            }
        }
        else if (choice == 2)
        {
            cout << "\n\nEnter Book Name : ";
            cin >> name;
            system("cls");
            cout << "\n\n--------------------------Book Management System--------------------------";

            for (int a = 0; a < i; a++)
            {
                if (name == b[a].name)
                {
                    cout << "\n\n\n Book Id : " << b[a].book_id;
                    cout << "\n\n Book Name " << b[a].name;
                    cout << "\n\n Author Name : " << b[a].aut;
                    cout << "\n\n Publisher Name : " << b[a].pub;
                    cout << "\n\n Pages : " << b[a].pages;
                    cout << "\n\n Price : " << b[a].price;
                    cout << "\n\n\n===============================";
                    found++;
                }
            }
            if (found == 0)
            {
                cout << "\n\n Book Name Not found ";
            }
        }
        else if (choice == 3)
        {
            cout << "\n\nEnter Author Name : ";
            cin >> name;
            system("cls");
            cout << "\n\n--------------------------Book Management System--------------------------";

            for (int a = 0; a < i; a++)
            {
                if (name == b[a].aut)
                {
                    cout << "\n\n Book Id : " << b[a].book_id;
                    cout << "\n\n Book Name : " << b[a].name;
                    cout << "\n\n Author Name : " << b[a].aut;
                    cout << "\n\n Publisher Name : " << b[a].pub;
                    cout << "\n\n Pages : " << b[a].pages;
                    cout << "\n\n Price : " << b[a].price;
                    cout << "\n\n\n===============================";
                    found++;
                }
            }
            if (found == 0)
            {
                cout << "\n\n Author Name Not found ";
            }
        }
        else
        {
            cout << "\n\nEnter Publisher Name : ";
            cin >> name;
            system("cls");
            cout << "\n\n--------------------------Book Management System--------------------------";

            for (int a = 0; a < i; a++)
            {
                if (name == b[a].pub)
                {
                    cout << "\n\n Book Id : " << b[a].book_id;
                    cout << "\n\n Book Name : " << b[a].name;
                    cout << "\n\n Author Name : " << b[a].aut;
                    cout << "\n\n Publisher Name : " << b[a].pub;
                    cout << "\n\n Pages : " << b[a].pages;
                    cout << "\n\n Price : " << b[a].price;
                    cout << "\n\n\n===============================";
                    found++;
                }
            }
            if (found == 0)
            {
                cout << "\n\n Publisher Name Not found ";
            }
        }
    }
}

void bookFUNC::update()
{
    system("cls");
    int id, found = 0;
    cout << "\n\n--------------------------Book Management System--------------------------";

    if (i == 0)
    {

        cout << "\n\n Data Base is Empty...";
    }
    else
    {
        cout << "\n\nEnter Book ID For Update : ";
        cin >> id;
        for (int a = 0; a < i; a++)
        {
            if (id == b[a].book_id)
            {
                system("cls");
                cout << "\n\n--------------------------Book Management System--------------------------";

                cout << "\n\n Book Id : ";
                cin >> b[a].book_id;
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
        if (found == 0)
        {
            cout << "\n\n Book ID not found...";
        }
    }
}

void bookFUNC::del()
{
    system("cls");
    int id, found = 0;
    cout << "\n\n--------------------------Book Management System--------------------------";
 
    if (i == 0)
    {
        cout << "\n\n Data Base is Empty...";
    }
    else
    {
        cout << "\n\nEnter Book ID For Delete : ";
        cin >> id;
        for (int a = 0; a < i; a++)
        {
            if (id == b[a].book_id)
            {
                for (int k = a; k < i; k++)
                {
                    b[k].book_id = b[k + 1].book_id;
                    b[k].name = b[k + 1].name;
                    b[k].aut = b[k + 1].aut;
                    b[k].pub = b[k + 1].pub;
                    b[k].pages = b[k + 1].pages;
                    b[k].price = b[k + 1].price;
                }
                cout << "\n\n\n\t Book Deleted Successfully.....";
                i--;
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Book ID not found...";
        }
    }
}

void bookFUNC::show()
{
    while (true) {
        system("cls");
        cout << "\n\n--------------------------Book Management System--------------------------";

        if (i == 0) {
            char choice;
            cout << "\nIn Data Base is Empty....";
            cout << "\n\nWould you like to add a book? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                add(); // Adding a book
            }
            else {
                break; // Exit the loop if the user doesn't want to add more books
            }
        }
        else {
            for (int a = 0; a < i; a++) {
                showBook(b[a]);
            }
            break; // Exit the loop if books are already added and displayed
        }
    }
}

//New Fetures added for borrowing and returning book.
void bookFUNC::borrowBook()
{
    system("cls");
    int id, found = 0;
    cout << "\n\n--------------------------Book Borrowing System--------------------------";
    if (i == 0)
    {
        cout << "\n\n Data Base is Empty...";
    }
    else
    {
        cout << "\n\nEnter Book ID to Borrow : ";
        cin >> id;
        for (int a = 0; a < i; a++)
        {
            if (id == b[a].book_id)
            {
                system("cls");
                cout << "\n\n--------------------------Book Borrowing System--------------------------";
                cout << "\n\n Book Id : " << b[a].book_id;
                cout << "\n\n Book Name : " << b[a].name;
                cout << "\n\n Author Name : " << b[a].aut;
                cout << "\n\n Publisher Name : " << b[a].pub;
                cout << "\n\n Pages : " << b[a].pages;
                cout << "\n\n Price : " << b[a].price;
                cout << "\n\n\n\t Book Borrowed Successfully...";
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Book ID not found...";
        }
    }
}

void bookFUNC::returnBook()
{
    system("cls");
    int id, found = 0;
    cout << "\n\n--------------------------Book Returning System--------------------------";
    if (i == 0)
    {
        cout << "\n\n Data Base is Empty...";
    }
    else
    {
        cout << "\n\nEnter Book ID to Return : ";
        cin >> id;
        for (int a = 0; a < i; a++)
        {
            if (id == b[a].book_id)
            {
                system("cls");
                cout << "\n\n--------------------------Book Returning System--------------------------";
                cout << "\n\n Book Id : " << b[a].book_id;
                cout << "\n\n Book Name : " << b[a].name;
                cout << "\n\n Author Name : " << b[a].aut;
                cout << "\n\n Publisher Name : " << b[a].pub;
                cout << "\n\n Pages : " << b[a].pages;
                cout << "\n\n Price : " << b[a].price;
                int daysLate;
                cout << "\n\nEnter number of days late (0 if on time): ";
                cin >> daysLate;
                double fine = calculateFine(daysLate);
                cout << "\n\nFine for late return: $" << fine;
                cout << "\n\n\n\t Book Returned Successfully...";
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\n Book ID not found...";
        }
    }
}

double bookFUNC::calculateFine(int daysLate)
{
    const double fineRate = 0.50; // Fine rate per day
    return daysLate * fineRate;
}

void showBook(bookVAR book)
{
    cout << "\n\n Book ID : " << book.book_id;
    cout << "\n\n Book Name : " << book.name;
    cout << "\n\n Author Name : " << book.aut;
    cout << "\n\n Publisher Name : " << book.pub;
    cout << "\n\n Pages : " << book.pages;
    cout << "\n\n Price : " << book.price;
    cout << "\n\n\n===============================";
}

int main()
{
    bookFUNC obj;
    obj.menu();
    return 0;
}
