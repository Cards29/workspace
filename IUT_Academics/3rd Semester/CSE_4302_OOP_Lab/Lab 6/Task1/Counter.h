#ifndef COUNTER_H
#define COUNTER_H
class Counter
{
private:
    int count;
    int increment_step;
    int flag;

public:
    Counter();
    Counter(int c);
    Counter(int c, int i);
    void setIncrementStep(int step_val);
    int getCount() const;
    void increment();
    void resetCount(int step);
    Counter operator + (const Counter& c)const;
    bool operator == (const Counter& c) const;
    bool operator <= (const Counter& c) const;
    bool operator >= (const Counter& c) const;
    bool operator != (const Counter& c) const;
    bool operator < (const Counter& c) const;
    bool operator > (const Counter& c) const;
    Counter operator ++() ;
    Counter operator ++(int) ;
    void operator +=(const Counter& c);
};

#endif // COUNTER_H