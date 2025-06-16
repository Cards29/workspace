#ifndef BOOK_H
#define BOOK_H
#include "LibraryResource.h"

enum class coverType{Hardcover, Paperback};

class Book: public LibraryResource{
private:
    coverType c;
public:
    Book(string s1, string s2, int n1, coverType c1);
    void resourceDetails() const;
};

#endif // BOOK_H