#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cout << "Enter first fraction: ";
    cin >> a;
    cin.ignore();
    cin >> b;
    cout << "Enter second fraction: ";
    cin >> c;
    cin.ignore();
    cin >> d;

    e = a * d + b * c;
    f = b * d;

    cout << "Sum = " << e << '/' << f << endl;
}