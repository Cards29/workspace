#include "chicken.h"

chicken::chicken() : animal(), dailyEggCount(0) {
    setSound("buck buck.");
}
chicken::chicken(string s1, string s2, int n1, int n2, int m1) :
    animal(s1, s2, "buck buck.", n1, n2), dailyEggCount(m1) {
}
void chicken::make_sound() const {
    cout << "The chicken says: ";
    animal::make_sound();
}
int chicken::getEggCount() const {
    return dailyEggCount;
}
void chicken::displayInformation() const{
    animal::displayInformation();
}
