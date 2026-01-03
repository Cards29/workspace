#ifndef CELSIUS_H
#define CELSIUS_H

#include "fahrenheit.h"
#include "kelvin.h"
class kelvin;
class fahrenheit;
class celsius {
private:
    double temp_c;
public:
    celsius();
    celsius(double temp);
    void assign(double temp);
    void display() const;
    operator kelvin() const;
    operator fahrenheit() const;
};

#endif // CELSIUS_H