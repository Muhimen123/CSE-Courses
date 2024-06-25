/*
A book shop maintains the inventory of books that are being sold at the shop. The list
includes details such as author, title, price and stock position.
For selling books, the salesperson inputs the title and the system searches the list and
displays whether it is available or not. If it is not, an appropriate message is displayed. If
it is, then the system displays the book details and requests for the number of copies
required. If the requested copies are available, the total cost of the requested copies is
displayed; otherwise "Required copies not in stock" is displayed.

Design a system using a class called books with suitable member functions,
constructors and destructors.
*/

#include <bits/stdc++.h>
using namespace std;

class Book {
    string author, title;
    float price;
    int stock;

    public:
    Book() {
        author = "";
        title = "";
        price = 0;
        stock = 0;
    }

    Book(string a, string t, float p, int s) {
        author = a;
        title = t;
        price = p;
        stock = s;
    }

    void setter(string a, string t, float p, int s) {
        author = a;
        title = t;
        price = p;
        stock = s;
    }

    void checkAvailability(string t, int n) {
        if (title == t) {
            if (stock >= n) {
                cout << "Book details: " << endl;
                cout << "Author: " << author << endl;
                cout << "Title: " << title << endl;
                cout << "Price: " << price << endl;
                cout << "Stock: " << stock << endl;
                cout << "Total cost: " << price * n << endl;
            } else {
                cout << "Required copies not in stock" << endl;
            }
        }
    }

    ~Book() {
    }
};

int main() {
    Book available[3]; // This syntax won't work without a default constructor
    for(int i = 0; i < 3; i++) {
        string a, t;
        float p;
        int s;
        cout << "Enter author: ";
        cin >> a;
        cout << "Enter title: ";
        cin >> t;
        cout << "Enter price: ";
        cin >> p;
        cout << "Enter stock: ";
        cin >> s;
        Book new_book(a, t, p, s);

        available[i] = new_book;
    }

    string title;
    cout << "Enter title of book to search: ";
    cin >> title;
    int n;
    cout << "Enter number of copies required: ";
    cin >> n;

    for(int i = 0; i < 3; i++) {
        available[i].checkAvailability(title, n);
    }

    return 0;
}