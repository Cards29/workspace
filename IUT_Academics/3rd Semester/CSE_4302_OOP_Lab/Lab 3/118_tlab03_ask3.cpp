#include <iostream>

using namespace std;

class Counter
{
private:
    int count;
    int increment_step;
    int second;

public:
    Counter() : count(0), increment_step(0), second(0)
    {
    }

    int hours()
    {
        return count;
    }
    int minutes()
    {
        return increment_step;
    }
    int seconds()
    {
        return second;
    }
    void reset(int h, int m, int s)
    {
        count = h;
        increment_step = m;
        second = s;
    }
    void advance(int h, int m, int s)
    {
        second += s;
        second %= 60;
        increment_step += m + s / 60;
        increment_step %= 60;
        count += h + (m + s / 60) / 60;
        count %= 24;
    }
    void print()
    {
        cout << "Current time is " << hours() << " hour(s) " << minutes() << " minute(s) " << seconds() << " second(s)" << endl;
    }
};

int main()
{
    Counter t1;

    t1.reset(0, 0, 0);
    t1.print();

    t1.advance(0, 100, 100);
    t1.print();


    return 0;
}