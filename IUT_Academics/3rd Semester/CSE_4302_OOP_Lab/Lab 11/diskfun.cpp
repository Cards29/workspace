#include <fstream>                //for file streams
#include <iostream>
using namespace std;

class person {                     //class of persons
protected:
    char name[80];              //person's name
    int age;                    //person's age
public:
    void getData()              //get person's data
    {
        cout << "\n   Enter name: "; cin >> name;
        cout << "   Enter age: "; cin >> age;
    }
    void showData()             //display person's data
    {
        cout << "\n   Name: " << name;
        cout << "\n   Age: " << age;
    }
};

int main() {
    char ch;
    person pers;
    fstream file;

    file.open("GROUP.dat", ios::trunc | ios::out | ios::binary);
    file.close();

    file.open("GROUP.dat", ios::app | ios::out | ios::in | ios::binary);

    do
    {
        cout << "\nEnter person's data:";
        pers.getData();

        file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
        cout << "Enter another person (y/n)?\n";
        cin >> ch;
    } while (ch=='y');

    file.seekg(0);

    file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    while(!file.eof()){
        cout<<"\nPerson:";
        pers.showData();
        file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    }
    cout << endl;
    
    return 0;
}