#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H
#include "LibraryResource.h"

class Audiobook: public LibraryResource{
private:
    int duration;
public:
    Audiobook(string s1, string s2, int n1, int d);
    void resourceDetails() const;
};

#endif // AUDIOBOOK_H