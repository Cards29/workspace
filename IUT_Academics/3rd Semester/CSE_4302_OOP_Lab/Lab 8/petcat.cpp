#include "petcat.h"

petcat::petcat() : cat(), petName("Oppenheimar") {
    // setSound("meow.");
}
petcat::petcat(string s1, string s2, int n1, int n2, string m1) :
    cat(s1, s2, n1, n2), petName(m1) {
}
void petcat::make_sound() const {
    cout << petName << " is a cat. ";
    cat::make_sound();
}
void petcat::displayInformation() const{
    cat::displayInformation();
    cout<<"Pet's Name: "<<petName<<endl;
}