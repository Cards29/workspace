#include "animal.h"

animal::animal() :
    nameOfAnimal(""), habitat_area(""), sound(""), weight(0), height(0) {
}
animal::animal(string s1, string s2, string s3, int n1, int n2) :
    nameOfAnimal(s1), habitat_area(s2), sound(s3), weight(n1), height(n2) {
}

void animal::displayInformation() const {
    cout << "Name: " << nameOfAnimal << endl
        << "Habitat: " << habitat_area << endl
        << "Sound: " << sound  << endl
        << "Weight: " << weight << " kg" << endl
        << "Height: " << height << " cm" << endl;
}

void animal::make_sound() const {
    cout << sound << endl;
}
void animal::changeWeight(int _weight) {
    weight = _weight;
}
void animal::setSound(string s1) {
    sound = s1;
}
// string animal::getSound() const {
//     return sound;
// }

