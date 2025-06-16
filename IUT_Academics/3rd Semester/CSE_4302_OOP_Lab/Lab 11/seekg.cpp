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
    person pers;
    ifstream infile;
    infile.open("GROUP.dat", ios::in | ios::binary);

    infile.seekg(0, ios::end);
    int endposition = infile.tellg();
    int n = endposition / sizeof(person);
    cout << "\nThere are " << n << " persons in file";

    cout << "\nEnter person number : ";
    cin >> n;
    int position = (n - 1) * sizeof(person);  
    infile.seekg(position);        
    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    pers.showData();               
    cout << endl;


    return 0;
}