#include "Book.h"

Book::Book(string s1, string s2, int n1, coverType c1): 
    LibraryResource(s1,s2,n1), c(c1) {}

    
void Book::resourceDetails() const{
    LibraryResource::resourceDetails();
    string s;
    if(c==coverType::Hardcover) s="Hardcover";
    else s="Paperback";
    cout<<"Cover type: "<< s <<endl << endl;
}