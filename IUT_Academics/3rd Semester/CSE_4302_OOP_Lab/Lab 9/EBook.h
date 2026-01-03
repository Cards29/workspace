#ifndef EBOOK_H
#define EBOOK_H
#include "LibraryResource.h"

class EBook: public LibraryResource{
private:
    double fileSize;
public: 
    EBook(string s1, string s2, int n1, double f);
    void resourceDetails() const;
};

#endif // EBOOK_H