#ifndef LIBRARYRESOURCE_H
#define LIBRARYRESOURCE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class LibraryResource{
private:
    int no_of_copies;
    string title;
    string author;
    int price;
public:
    LibraryResource(string s1, string s2, int n1);
    virtual void resourceDetails() const = 0;
    int get_no_of_copies() const;
    void set_no_of_copies(int n2);
    int getPrice() const;
};

#endif // LIBRARYRESOURCE_H