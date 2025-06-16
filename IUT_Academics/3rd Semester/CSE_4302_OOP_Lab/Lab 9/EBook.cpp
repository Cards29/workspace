#include "EBook.h"

EBook::EBook(string s1, string s2, int n1, double f) :
    LibraryResource(s1, s2, n1), fileSize(f) {
}

void EBook::resourceDetails() const {
    LibraryResource::resourceDetails();
    cout << "File size: " << fileSize << " MB" << endl << endl;
}