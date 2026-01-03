#include "cat.h"

cat::cat() : animal() {
    setSound("meow.");
}
cat::cat(string s1, string s2, int n1, int n2) :
    animal(s1, s2, "meow.", n1, n2) {
}
void cat::make_sound() const {
    cout << "The cat says: ";
    animal::make_sound();
}
void cat::displayInformation() const{
    animal::displayInformation();
}
