#include "Audiobook.h"

Audiobook::Audiobook(string s1, string s2, int n1, int d):
    LibraryResource(s1,s2,n1), duration(d) {}

void Audiobook::resourceDetails() const {
    LibraryResource::resourceDetails();
    cout << "Duration: " << duration << " minutes" << endl << endl;
}