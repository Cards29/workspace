#include <iostream>
#include "Counter.h"

using namespace std;

Counter::Counter() : count(0), increment_step(1), flag(0)
{}
Counter::Counter(int c) :count(c), increment_step(1), flag(0) {}
Counter::Counter(int c, int i) :count(c) {
    flag=1;
    setIncrementStep(i);
}
void Counter::setIncrementStep(int step_val)
{
    if(step_val<0){
        cout<<"ERROR!!! negative value is passed as increment step"<<endl;
        if(flag)
            increment_step=1;
        return;
    }
    if(count==0)
        increment_step = step_val;
    else{
        cout<<"ERROR!!! Cannot set the increment step,  count is not zero"<<endl;
    }
}
int Counter::getCount() const
{
    return count;
}
void Counter::increment()
{
    count += increment_step;
}
void Counter::resetCount(int step = 1)
{
    count = 0;
    increment_step = step;
}
Counter Counter::operator + (const Counter& c) const {
    int count1=count;
    if (increment_step==c.increment_step){
        return Counter(count1 += c.count, increment_step);
    }
    else{
        cout<<"ERROR!! Increment step is not same"<<endl;
        return Counter();
    }
}
bool Counter:: operator == (const Counter& c) const {
    if(count==c.count) return true;
    else return false;
}
bool Counter:: operator <= (const Counter& c) const {
    if (count <= c.count) return true;
    else return false;
}
bool Counter:: operator >= (const Counter& c) const {
    if (count >= c.count) return true;
    else return false;
}
bool Counter:: operator != (const Counter& c) const {
    if (count != c.count) return true;
    else return false;
}
bool Counter:: operator < (const Counter& c) const {
    if (count < c.count) return true;
    else return false;
}
bool Counter:: operator > (const Counter& c) const {
    if (count > c.count) return true;
    else return false;
}
Counter Counter::operator ++ () {
    return Counter(++count);
}
Counter Counter::operator ++ (int) {
    return Counter(count++);
}
void Counter::operator +=(const Counter& c) {
    count+=c.count;
    increment_step=max(increment_step,c.increment_step);
}


