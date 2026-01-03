#include <bits/stdc++.h>

using namespace std;

class Temperature
{
private:
    double temperature_value;
    string unit;

public:
    Temperature() : temperature_value(0), unit("Kelvin")
    {
    }
    void assign(double value, string assign_unit)
    {
        if (assign_unit != "Celsius" && assign_unit != "Fahrenheit" && assign_unit != "Kelvin")
        {
            cerr << "Inappropriate unit" << endl;
            return;
        }
        if (assign_unit == "Celsius" && value < (-273.15))
        {
            cerr << "Inappropriate value for the given unit" << endl;
            return;
        }
        if (assign_unit == "Fahrenheit" && value < (-459.67))
        {
            cerr << "Inappropriate value for the given unit" << endl;
            return;
        }
        if (assign_unit == "Kelvin" && value < 0)
        {
            cerr << "Inappropriate value for the given unit" << endl;
            return;
        }

        temperature_value = value;
        unit = assign_unit;
    }

    void convert(string assign_unit)
    {
        if (assign_unit == "Celsius")
        {
            if (unit == "Fahrenheit")
            {
                temperature_value = (5 * (temperature_value - 32))/9;
                unit = "Celsius";
            }
            else if (unit == "Kelvin")
            {
                temperature_value -= 273.15;
                unit = "Celsius";
            }
        }
        else if (assign_unit == "Fahrenheit")
        {
            if (unit == "Celsius")
            {
                temperature_value = (9 * temperature_value)/5 + 32;
                unit = "Fahrenheit";
            }
            else if (unit == "Kelvin")
            {
                temperature_value = (9 * (temperature_value - 273.15))/5 + 32;
                unit = "Fahrenheit";
            }
        }
        else if (assign_unit == "Kelvin")
        {
            if (unit == "Fahrenheit")
            {
                temperature_value = (5  * (temperature_value - 32))/9 + 273.15;
                unit = "Kelvin";
            }
            else if (unit == "Celsius")
            {
                temperature_value += 273.15;
                unit = "Kelvin";
            }
        }
        else
            cerr << "Inappropriate unit" << endl;
    }

    void print()
    {
        cout << "The temperature is " << temperature_value << " " << unit << endl;
    }
};

int main()
{
    Temperature t1;

    t1.assign(36,"Celsius");
    t1.print();

    // Inappropriate unit won't work and it will print the previous assigned value
    t1.assign(-274, "Celsi");
    t1.print();

    // Inappropriate value for the unit won't work and it will print the previous assigned value
    t1.assign(-274, "Celsius");
    t1.print();

    t1.assign(-470, "Fahrenheit");
    t1.print();

    t1.assign(-1, "Kelvin");
    t1.print();

    // conversion
    t1.convert("Fahrenheit");
    t1.print();

    // Inappropriate unit won't work and it will print the previous assigned value
    t1.convert("Fahren");
    t1.print();

    t1.convert("Kelvin");
    t1.print();

    t1.convert("Celsius");
    t1.print();
    
    return 0;
}
