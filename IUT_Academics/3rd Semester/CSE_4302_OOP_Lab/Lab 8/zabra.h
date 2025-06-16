#ifndef ZEBRA_H
#define ZEBRA_H

#include "animal.h"

class zebra: public animal{
private:
    int stripesCount;
public:
    zebra(string s1, string s2, int n1, int n2);
    void make_sound() const;
};


#endif // ZEBRA_H