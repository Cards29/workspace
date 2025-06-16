#include <iostream>
using namespace std;

int main()
{
    int& i = *(new int);
    i = 10;
    cout << i << endl;
    delete& i;
    return 0;
}
/*In essence:

A new integer is created on the heap. // (new int)
A reference i is created and bound to this newly created integer.
Any modification to i will directly affect the value of the dynamically allocated integer.*/
