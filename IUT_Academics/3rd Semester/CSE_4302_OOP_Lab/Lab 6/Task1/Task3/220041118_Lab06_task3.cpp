#include <iostream>
#include "celsius.h"
#include "kelvin.h"
#include "fahrenheit.h"

using namespace std;

int main(){
    celsius c1(5000);
    kelvin k1(8);
    fahrenheit f1;
    c1.display();
    k1=c1;
    f1=c1;
    k1.display();
    f1.display();
    
    return 0;
}