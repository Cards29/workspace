#include "cow.h"

cow::cow() :animal(), milkProductionInLiters(0) {
    setSound("moo.");
}
cow::cow(string s1, string s2, int n1, int n2, double m1) :
    animal(s1, s2, "moo.", n1, n2), milkProductionInLiters(m1) {
}
void cow::make_sound() const {
    cout << "The cow says: ";
    animal::make_sound();
}
double cow::getMilkProduction() const {
    return milkProductionInLiters;
}
