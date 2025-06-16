#include <iostream>

using namespace std;

class Counter
{
private:
    int count;
    int increment_step;

public:
    Counter() : count(0)
    {
    }
    void setIncrementStep(int step)
    {
        increment_step = step;
    }
    int getCount()
    {
        return count;
    }

    void increment()
    {
        count += increment_step;
    }

    void resetCount()
    {
        count = 0;
    }
};

int main()
{
    Counter c1;

    cout << "Count is equal to " << c1.getCount() << endl;

    c1.setIncrementStep(5);
    c1.increment();
    cout << "Count is equal to " << c1.getCount() << endl;

    c1.setIncrementStep(-3);
    c1.increment();
    cout << "Count is equal to " << c1.getCount() << endl;

    c1.resetCount();

    c1.setIncrementStep(15);
    c1.increment();
    cout << "Count is equal to " << c1.getCount() << endl;

    c1.setIncrementStep(-10);
    c1.increment();
    cout << "Count is equal to " << c1.getCount() << endl;

    c1.resetCount();

    c1.setIncrementStep(32);
    c1.increment();
    cout << "Count is equal to " << c1.getCount() << endl;

    return 0;
}