#ifndef KELVIN_H
#define KELVIN_H

#include "celsius.h"
#include "fahrenheit.h"
class celsius;
class fahrenheit;
class kelvin {
private:
    double temp_k;
public:
    kelvin();
    kelvin(double temp);
    void assign(double temp);
    void display() const;
    operator celsius() const;
    operator fahrenheit() const;
};

#endif // KELVIN_H