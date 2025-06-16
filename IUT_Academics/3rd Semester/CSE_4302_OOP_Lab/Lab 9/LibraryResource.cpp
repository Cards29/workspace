#include "LibraryResource.h"

LibraryResource::LibraryResource(string s1, string s2, int n1) : title(s1), author(s2), price(n1), no_of_copies(1) {}

void LibraryResource::resourceDetails() const {
    cout << "Title: " << title << endl
        << "Author: " << author << endl
        << "Price: " << price << endl
        <<"No. of copies: " << no_of_copies << endl;
}

int LibraryResource::get_no_of_copies() const{
    return no_of_copies;
}

void LibraryResource::set_no_of_copies(int n2){
    no_of_copies = n2;
}

int LibraryResource::getPrice() const{
    return price;
}
