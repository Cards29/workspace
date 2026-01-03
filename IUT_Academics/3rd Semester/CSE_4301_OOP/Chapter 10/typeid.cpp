#include <iostream>
#include <typeinfo>           //for typeid()
using namespace std;
////////////////////////////////////////////////////////////////
class Base
{
    virtual void virtFunc()    //needed for typeid
    {
    }
};
class Derv1: public Base
{
};
class Derv2 : public Base
{
};
////////////////////////////////////////////////////////////////
void displayName(Base* pB)
{
    cout << "pointer to an object of ";  //display name of class
    string s = typeid(*pB).name();
    s=s.substr(1);
    cout << s << endl;  //pointed to by pB
}
//-------------------------------------------------------------
int main()
{
    Base* pBase = new Derv1;

    displayName(pBase);   //”pointer to an object of class Derv1”
    pBase = new Derv2;
    displayName(pBase);   //”pointer to an object of class Derv2”
    return 0;
}