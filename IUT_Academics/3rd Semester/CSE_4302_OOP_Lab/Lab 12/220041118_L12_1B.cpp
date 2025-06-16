#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book() :title("Panther Panchali"), author("Bibhutibhushan Bandyopadhyay"), ISBN("1234561234567") {}

    void getBookData(string _title, string _author, string _ISBN) {
        title = _title;
        author = _author;
        ISBN = _ISBN;
    }

    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << endl;
    }

    string bookInfoForFIle() const {
        string str;
        str += title;
        str += ", ";
        str += author;
        str += ", ";
        str +=  ISBN;
        return str;
    }

    bool operator == (const Book& _book) const {
        return ISBN == _book.ISBN;
    }
};

class Library {
private:
    vector<Book> inventory;
    deque<Book> borrowedBooks;
    list<Book> archivedBooks;
public:
    void addBook(string _title, string _author, string _ISBN) {
        Book b1;
        b1.getBookData(_title, _author, _ISBN);
        inventory.push_back(b1);
    }
    void addBook(Book _book) {
        inventory.push_back(_book);
    }
    void borrowBook(string _title, string _author, string _ISBN) {
        Book b1;
        b1.getBookData(_title, _author, _ISBN);
        if (find(inventory.begin(), inventory.end(), b1) == inventory.end()) {
            cerr << "Book not found" << endl;
            return;
        }
        borrowedBooks.push_back(b1);
        inventory.erase(find(inventory.begin(), inventory.end(), b1));
    }
    void borrowBook(Book b1) {
        if (find(inventory.begin(), inventory.end(), b1) == inventory.end()) {
            cerr << "Book not found" << endl;
            return;
        }
        borrowedBooks.push_back(b1);
        inventory.erase(find(inventory.begin(), inventory.end(), b1));
    }
    void returnBook(string _title, string _author, string _ISBN) {
        Book b1;
        b1.getBookData(_title, _author, _ISBN);
        if (find(borrowedBooks.begin(), borrowedBooks.end(), b1) == borrowedBooks.end()) {
            cerr << "Book not found" << endl;
            return;
        }
        inventory.push_back(b1);
        borrowedBooks.erase(find(borrowedBooks.begin(), borrowedBooks.end(), b1));
    }
    void returnBook(Book b1) {
        if (find(borrowedBooks.begin(), borrowedBooks.end(), b1) == borrowedBooks.end()) {
            cerr << "Book not found" << endl;
            return;
        }
        inventory.push_back(b1);
        borrowedBooks.erase(find(borrowedBooks.begin(), borrowedBooks.end(), b1));
    }
    void archiveBook(string _title, string _author, string _ISBN) {
        Book b1;
        b1.getBookData(_title, _author, _ISBN);
        if (find(inventory.begin(), inventory.end(), b1) == inventory.end()) {
            cerr << "Book not found" << endl;
            return;
        }
        archivedBooks.push_back(b1);
        inventory.erase(find(inventory.begin(), inventory.end(), b1));
    }
    void archiveBook(Book b1) {
        if (find(inventory.begin(), inventory.end(), b1) == inventory.end()) {
            cerr << "Book not found" << endl;
            return;
        }
        archivedBooks.push_back(b1);
        inventory.erase(find(inventory.begin(), inventory.end(), b1));
    }
    void displayInventory() const {
        cout << "Inventory:\n";
        for (auto i : inventory)
            i.displayBook();
    }
    void displayBorrowed() const {
        cout << "Borrowed Books:\n";
        for (auto i : borrowedBooks)
            i.displayBook();
    }
    void displayArchive() const {
        cout << "Archived Books:\n";
        for (auto i : archivedBooks)
            i.displayBook();
    }
    void saveInventory() const {
        ofstream o1("inventory.txt");
        for (auto i : inventory)
            o1 << i.bookInfoForFIle() << endl;
    }
    void saveBorrowedBooks() const {
        ofstream o1("borrowedBooks.txt");
        for (auto i : borrowedBooks)
            o1 << i.bookInfoForFIle() << endl;
    }
    void saveArchivedBooks() const {
        ofstream o1("archivedBooks.txt");
        for (auto i : archivedBooks)
            o1 << i.bookInfoForFIle() << endl;
    }
    void loadInventory() const {
        ifstream i1("inventory.txt");
        string str;
        int sz = inventory.size();
        while (sz--) {
            getline(i1,str);
            cout << str << endl;
        }
    }
    void loadBorrowedBooks() const {
        ifstream i1("borrowedBooks.txt");
        string str;
        int sz = borrowedBooks.size();
        while (sz--) {
            getline(i1,str);
            cout << str << endl;
        }
    }
    void loadArchivedBooks() const {
        ifstream i1("archivedBooks.txt");
        string str;
        int sz = archivedBooks.size();
        while (sz--) {
            getline(i1,str);
            cout << str << endl;
        }
    }
};

void giveBookData(Book &b1) {
    string s1,s2,s3;
    cout << "Enter Book details:\n"
            <<"Title: ";
            cin >> s1;
            cout << "Author: ";
            cin >> s2;
            cout << "ISBN";
            cin >> s3;
            b1.getBookData(s1,s2,s3);
}

int main() {
    Library l1;

    int n;
    string s1,s2,s3;
    Book b1;
    do {
        cout<<"1. Add Book\n"
            <<"2. Borrow Book\n"
            <<"3. Return Book\n"
            <<"4. Archive Book\n"
            <<"5. Display Books\n"
            <<"6. Save Data\n"
            <<"7. Load Data\n"
            <<"8. Exit\n"
            <<"Enter your choice: ";
        cin >> n;
        if(n == 8) break;
        switch (n) {
        case 1:
            giveBookData(b1);
            l1.addBook(b1);
            break;
        case 2:
            giveBookData(b1);
            l1.borrowBook(b1);
            break;
        case 3:
            giveBookData(b1);
            l1.returnBook(b1);
            break;
        case 4:
            giveBookData(b1);
            l1.archiveBook(b1);
            break;
        case 5:
            l1.displayInventory();
            l1.displayBorrowed();
            l1.displayArchive();
            break;
        case 6:
            l1.saveInventory();
            l1.saveBorrowedBooks();
            l1.saveArchivedBooks();
            break;
        case 7:
            l1.loadInventory();
            l1.loadBorrowedBooks();
            l1.loadArchivedBooks();
            break;
        default:
            break;
        }
    } while (n!=8);
    

    

    return 0;
}