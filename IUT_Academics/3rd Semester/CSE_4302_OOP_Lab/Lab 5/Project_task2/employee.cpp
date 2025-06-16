#include "employee.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

employee::employee() :
    employeeName("John Doe"),
    dob_day(1),
    dob_month(static_cast<months>(1)),
    dob_year(2002),
    salary(10000)
{}
employee::employee(string name, int day, int month, int year, double salary1) :
    employeeName(name),
    dob_day(day),
    dob_month(static_cast<months>(month)),
    dob_year(year),
    salary(salary1)
{} // this is for constant objects where we can't use setInfo()

string employee::getEmployeeName() const {
    return employeeName;
}
double employee::getSalary() const {
    return salary;
}
string employee::getBirthDay() const {
    string s = "";
    s += to_string(dob_day);
    s += "/";
    s += to_string(dob_month);
    s += "/";
    s += to_string(dob_year);
    return s;
}
void employee::setEmployeeName(string name) {
    if (name.length() < 2) return;
    employeeName = name;
}
void employee::setSalary(double num) {
    if (num < 10000 || num>100000) return;
    salary = num;
}
void employee::setBirthDay(int day, int month, int year) {
    if (day == 1 && year == 2006 && month == 10) return; // today's date
    dob_day = day;
    dob_month = static_cast<months>(month);
    dob_year = year;
}
void employee::setInfo(string name, int day, int month, int year, double salary) {
    setEmployeeName(name);
    setSalary(salary);
    setBirthDay(day, month, year);
}
void employee::getInfo() const {
    cout << "Name: " << getEmployeeName() << endl;
    cout << "Date of Birth: " << getBirthDay() << endl;
    cout << "Salary: " << getSalary() << endl;
}
employee employee::EmployeeCompareAge(const employee e) const {
    employee temp;
    if (temp.dob_year > e.dob_year) return e;
    else if (temp.dob_year < e.dob_year) return temp;
    else {
        if (temp.dob_month > e.dob_month) return e;
        else if (temp.dob_month < e.dob_month) return temp;
        else {
            if (temp.dob_day > e.dob_day)return e;
            else if (temp.dob_day < e.dob_day) return temp;
        }
    }
    return temp; // if they have the same birthday, we return any of them
}

employee::~employee() {}