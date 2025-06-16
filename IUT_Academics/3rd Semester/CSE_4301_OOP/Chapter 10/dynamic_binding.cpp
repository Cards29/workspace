#include <iostream> 
using namespace std;
class Base {
public:
    virtual void display() { // because of virtual keyword 
        cout << "Displayed from base class" << endl;
    }
};
class Derv : public Base {
public:
    void display() override { // "Override is used for safe polymorphism and error prevention" 
        cout << "Displayed from derived class" << endl;
    }
};
int main() {
    Base* b;
    Derv d;
    b = &d;
    b->display(); // Output is determined at runtime 
    return 0;
}