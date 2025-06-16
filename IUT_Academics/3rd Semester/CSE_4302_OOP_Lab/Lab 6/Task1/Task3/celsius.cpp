#include <iostream>
#include "celsius.h"

using namespace std;

celsius::celsius():temp_c(0) {}
celsius::celsius(double temp) {
    assign(temp);
}
void celsius::assign(double temp){
    if(temp<-273.15){
        cerr<<"ERROR!!! Given temperature is below absolute zero"<<endl;
        return;
    }
    temp_c = temp;
}
void celsius::display() const{
    cout<<"The temperature is "<<temp_c<<" Celsius."<<endl;
}

celsius::operator fahrenheit() const{
    double temp_f = (temp_c*9)/5+32;
    return fahrenheit(temp_f);
}
celsius::operator kelvin() const{
    double temp_k = temp_c + 273.15;
    return kelvin(temp_k);
}