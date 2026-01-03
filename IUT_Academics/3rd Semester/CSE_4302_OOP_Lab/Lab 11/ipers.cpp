#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class person {                     //class of persons
protected:
    char name[80];              //person’s name
    short age;                  //person’s age
public:
    void showData() {            //display person’s data
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    person pers;
    ifstream infile("PERSON.dat", ios::binary);

    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    pers.showData();

    return 0;
}