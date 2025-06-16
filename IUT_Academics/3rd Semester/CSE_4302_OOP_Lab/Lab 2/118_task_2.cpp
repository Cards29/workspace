#include <iostream>

using namespace std;

enum days_of_week {Sun=100,Mon,Tue,Wed,Thu,Fri,Sat};

int main()
{
    days_of_week day1,day2;
    day1=Sat;
    day2=Thu;

    switch (day1)
    {
    case Sat: 
        cout << "Saturday" << endl;
        break;
    case Mon:
        cout << "Monday" << endl;
        break;
    }
    cout<<day1<<endl<<day2<<endl;
    cout<<"Difference between days: "<<day1-day2<<endl;

    if(day1>day2)
        cout<<day1<<" is greater than "<<day2<<endl;
    else
        cout << day2 << " is greater than " << day1 << endl;

    return 0;
}