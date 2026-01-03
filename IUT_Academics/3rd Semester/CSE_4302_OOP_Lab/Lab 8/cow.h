#include "animal.h"

#ifndef COW_H
#define COW_H
class cow : public animal {
private:
    double milkProductionInLiters;
public:
    cow();
    cow(string s1, string s2, int n1, int n2, double m1);
    void make_sound() const;
    double getMilkProduction() const;
};
#endif // COW_H