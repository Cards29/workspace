#include "zabra.h"

zebra::zebra(string s1, string s2, int n1, int n2) : animal(s1,s2,"Uauaua",n1,n2) {}
void zebra::make_sound() const{
    cout<<"Zebra says: ";
    animal::make_sound();
}
