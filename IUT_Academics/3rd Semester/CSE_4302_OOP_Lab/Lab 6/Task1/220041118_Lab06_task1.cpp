#include <iostream>
#include "Counter.h"

using namespace std;


int main()
{
    Counter c1,c2(8),c3(10),c4;
    // cout << c1.getCount()<<endl;

    c1=c2.operator+(c3);
    c4=c2+c3;
    cout << c1.getCount()<<' '<< c4.getCount() << endl;


    // c2+=c1;
    // cout << c1.getCount() << endl;
    // cout << c2.getCount() << endl;
    return 0;
}