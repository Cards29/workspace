#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;
class animal {
private:
    string nameOfAnimal;
    string habitat_area;
    string sound;
    int weight;
    int height;
protected:
    int faisalSir;
public:
    animal();
    animal(string s1, string s2, string s3, int n1, int n2);
    void displayInformation() const;
    void make_sound() const;
    void changeWeight(int _weight);
    // string getSound() const;
    void setSound(string s1);

};
#endif // ANIMAL_H