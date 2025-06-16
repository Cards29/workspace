#include <iostream>
#include "kelvin.h"

using namespace std;

kelvin::kelvin():temp_k(0) {}
kelvin::kelvin(double temp) {
    assign(temp);
}
void kelvin::assign(double temp) {
    if (temp < 0) {
        cerr << "ERROR!!! Given temperature is below absolute zero" << endl;
        return;
    }
    temp_k = temp;
}
void kelvin::display() const {
    cout << "The temperature is " << temp_k << " Celsius." << endl;
}
kelvin::operator fahrenheit() const {
    double temp_f = ((temp_k - 273.15) * 9)/5 + 32;
    return fahrenheit(temp_f);
}
kelvin::operator celsius() const {
    double temp_c=temp_k-273.15;
    return celsius(temp_c);
}