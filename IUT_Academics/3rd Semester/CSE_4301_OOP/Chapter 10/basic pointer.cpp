#include <iostream>

using namespace std;

int main()
{
    int* a;
    int test;
    char ch;
    // a = &ch; // mismatched type


    void* v;
    v = &ch;
    v = &test;

    // *v = 10; //you cannot assign value using void pointer

    // (int*)v // this cast the void pointer to int*
    // *(int*)v // this makes dereference to assign or use the value stored in the address
    *(int*)v = 10;




    const int* cptrInt;
    //cptrInt is a pointer to constant int

    cptrInt = &test; // you can assign address
    test = 10; // you can change the value using original variable
    //    *cptrInt = 10; // you cannot change the value using pointer
    cout << *cptrInt;

    int* const ptrcInt = new int;
    //ptrcInt is a constant pointer to int
    //once assign an address to ptrcInt, you cannot use ptrcInt to point any other address
    //    ptrcInt = new int;


}
