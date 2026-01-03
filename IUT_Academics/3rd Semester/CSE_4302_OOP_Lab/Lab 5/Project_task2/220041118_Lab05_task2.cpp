#include<iostream>
#include "employee.h"
using namespace std;

int main() {
    employee e1;
    e1.getInfo();
    cout << endl;
    const employee e2("Monazir", 25, 7, 2001, 100000);
    e2.getInfo();
    cout << endl;
    e1.setInfo("Rahinur", 02, 04, 2004, 12345);
    e1.getInfo();
    cout << endl;
    employee e3;
    e3 = e1.EmployeeCompareAge(e2);
    e3.getInfo();
    return 0;
}