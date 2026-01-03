#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class person {                     //class of persons
protected:
    char name[80];              //person’s name
    short age;                  //person’s age
public:
    void getData() {             //get person’s data
        cout << "Enter name : "; cin >> name;
        cout << "Enter age : "; cin >> age;
    }
};

int main() {
    person pers;
    pers.getData();

    ofstream outfile("PERSON.dat", ios::binary);

    outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));

    return 0;
}