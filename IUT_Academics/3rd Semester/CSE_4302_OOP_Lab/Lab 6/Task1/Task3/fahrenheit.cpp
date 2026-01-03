#include <iostream>
#include "fahrenheit.h"

using namespace std;

fahrenheit::fahrenheit() :temp_f(0) {}
fahrenheit::fahrenheit(double temp) {
    assign(temp);
}
void fahrenheit::assign(double temp) {
    if (temp < -273.15) {
        cerr << "ERROR!!! Given temperature is below absolute zero" << endl;
        return;
    }
    temp_f = temp;
}
void fahrenheit::display() const {
    cout << "The temperature is " << temp_f << " Fahrenheit." << endl;
}

fahrenheit::operator celsius() const {
    double temp_f = (temp_f * 9) / 5 + 32;
    return fahrenheit(temp_f);
}
fahrenheit::operator kelvin() const {
    double temp_k = temp_f + 273.15;
    return kelvin(temp_k);
}