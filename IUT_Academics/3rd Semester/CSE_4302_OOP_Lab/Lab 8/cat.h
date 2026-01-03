#include "animal.h"

#ifndef CAT_H
#define CAT_H
class cat : private animal {
public:
    cat();
    cat(string s1, string s2, int n1, int n2);
    void make_sound() const;
    void displayInformation() const;
};
#endif // CAT_H