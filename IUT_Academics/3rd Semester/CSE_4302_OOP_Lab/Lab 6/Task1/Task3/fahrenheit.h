#ifndef FAHRENHEITE_H
#define FAHRENHEITE_H

#include "celsius.h"
#include "kelvin.h"
class celsius;
class kelvin;
class fahrenheit {
private:
    double temp_f;
public:
    fahrenheit();
    fahrenheit(double temp);
    void assign(double temp);
    void display() const;
    operator kelvin() const;
    operator celsius() const;
};

#endif // FAHRENHEITE_H