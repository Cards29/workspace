#include <iostream>

using namespace std;

void func(int& r, char& s)
{
    r=3435;
    s='p';
}

int main()
{
    int a=10;
    char bb='b';

    func(a,bb);

    cout<<a<<' '<<bb<<endl;

    return 0;
}