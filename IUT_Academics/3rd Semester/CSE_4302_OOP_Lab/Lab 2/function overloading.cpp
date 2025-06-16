#include <iostream>

using namespace std;

inline int add(int a, int b)
{
    return a + b;
}
inline int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    int a=2, b=3, c=4;
    
    cout<<add(a,b)<<endl;
    cout<<add(a,b,c)<<endl;

    return 0;
}