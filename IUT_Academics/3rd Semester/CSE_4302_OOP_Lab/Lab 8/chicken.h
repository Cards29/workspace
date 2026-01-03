#include "animal.h"
#ifndef CHICKEN_H
#define CHICKEN_H
class chicken : protected animal {
private:
    int dailyEggCount;
public:
    chicken();
    chicken(string s1, string s2, int n1, int n2, int m1);
    void make_sound() const;
    int getEggCount() const;
    void displayInformation() const;
};
#endif // CHICKEN_H