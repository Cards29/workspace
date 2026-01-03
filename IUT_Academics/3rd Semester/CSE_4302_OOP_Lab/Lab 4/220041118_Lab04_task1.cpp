/*
    this is 220041118, Rahinur Bin Naushad
*/
#include <iostream>

using namespace std;

class Calculator {
private:
    int current_value;
    int get() {
        return current_value;
    }
    void set(int value) {
        current_value = value;
    }
public:
    Calculator() :current_value(0)
    {};
    Calculator(int value) :current_value(value)
    {};
    void add(int value) {
        current_value += value;
    }
    void subtract(int value) {
        current_value -= value;
    }
    void multiply(int value) {
        current_value *= value;
    }
    int divideBy(int value) {
        if (value == 0) {
            cerr << "Invalid arithmetic operation." << endl;
            return 0;
        }
        int temp = current_value;
        current_value /= value;
        return temp % value;
    }
    void clear() {
        set(0);
    }
    void display() {
        cout << "Calculator display : " << get() << endl;
    }
    ~Calculator() {
        cout <<"Current value: "<< current_value << endl << "Destructor of the Calculator object is called." << endl;
    };
};


int main() {
    Calculator c;

    c.add(10);
    c.display();

    c.subtract(5);
    c.display();

    c.multiply(34);
    c.display();

    c.divideBy(0);
    c.display();

    c.divideBy(4);
    c.display();

    c.clear();
    c.display();


    return 0;
}