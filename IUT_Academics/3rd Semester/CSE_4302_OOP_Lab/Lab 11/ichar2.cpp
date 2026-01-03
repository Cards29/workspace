#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    char ch;
    ifstream infile("TEST.txt");

    cout << infile.rdbuf();
    cout<<endl;

    cout << endl;

    return 0;
}