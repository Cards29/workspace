#include "cat.h"
#include "animal.h"

#ifndef PETCAT_H
#define PETCAT_H
class petcat: public cat{
private:
    string petName;
public:
    petcat();
    petcat(string s1, string s2, int n1, int n2, string m1);
    void make_sound() const;
    void displayInformation() const;
};
#endif // PETCAT_H