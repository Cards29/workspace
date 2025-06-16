#include <iostream>
using namespace std;

int main(){
    char s1[] = "Mahiul valo";
    char *s2 = "Mahiul valo";
    cout<<s1<<endl;
    cout<<s2<<endl;
    // s1++;
    s2++;
    cout<<s2<<endl;

    return 0;
}