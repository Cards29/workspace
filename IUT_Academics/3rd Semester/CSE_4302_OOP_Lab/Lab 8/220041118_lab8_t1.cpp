#include <iostream>
#include "animal.h"
// #include "cow.h"
// #include "chicken.h"
// #include "cat.h"
// #include "petcat.h"
#include "zabra.h"
using namespace std;

int main(){
    // cow cow1("Goru.", "Khola Math.", 400, 140, 27.27);
    // cow1.make_sound();
    // chicken chicken1("Murgi.", "Math/Jongol.", 3, 60, 2);
    // chicken1.make_sound();
    // cat cat1("Bilai.", "Manusher basha er ash pash/Jongol.", 5, 25);
    // cat1.make_sound();
    // petcat petcat1("Bilai", "Omuker basha", 5, 17, "Oppenheimar");
    // petcat1.make_sound();

    // cout<<endl;

    // cow1.displayInformation();

    // cout<<endl;

    // chicken1.displayInformation();

    // cout<<endl;

    // cat1.displayInformation();

    // cout<<endl;

    // petcat1.displayInformation();

    zebra z1("jebra", "khola math", 100, 100);
    z1.make_sound();
    z1.displayInformation();
    return 0;
}