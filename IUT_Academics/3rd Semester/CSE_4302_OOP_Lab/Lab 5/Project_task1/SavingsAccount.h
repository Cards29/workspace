#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include<string>
using namespace std;
class SavingsAccount {
private:
    string accountName;
    string holderName;
    string address;
    double annualInterestRate;
    double currentBalance;
public:
    SavingsAccount();
    void get();
    void set();
    void deposit();
    void withdrawal();
    double calculateInterest(int periodInMonths);
    void disburseInterest(int periodInMonths);
    ~SavingsAccount();
};
#endif