#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class employee {
private:
    string employeeName;
    double salary;
    int dob_day;
    int dob_year;
    enum months { JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6, JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12 };
    months dob_month;
public:
    employee();
    employee(string name, int day, int month, int year, double salary);
    string getEmployeeName() const;
    double getSalary() const;
    string getBirthDay() const;

    void setEmployeeName(string name);
    void setSalary(double num);
    void setBirthDay(int day, int month, int year);

    void setInfo(string name, int day, int month, int year, double salary);
    void getInfo() const;
    employee EmployeeCompareAge(const employee e) const;
    ~employee();
};
#endif // EMPLOYEE_H