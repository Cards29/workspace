#include <iostream>

using namespace std;

typedef struct fraction
{
    int numerator;
    int denominator;

}fraction;

fraction sum(fraction f1, fraction f2)
{
    fraction summat;
    summat.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    summat.denominator = f1.denominator * f2.denominator;

    return summat;
}

int main()
{
    fraction f1,f2,sumF1F2;
    cout << "Enter first fraction: ";
    cin >> f1.numerator;
    cin.ignore();
    cin >> f1.denominator;
    cout << "Enter second fraction: ";
    cin >> f2.numerator;
    cin.ignore();
    cin >> f2.denominator;

    sumF1F2=sum(f1,f2);

    cout << "Sum = " << sumF1F2.numerator << '/' << sumF1F2.denominator << endl;
}