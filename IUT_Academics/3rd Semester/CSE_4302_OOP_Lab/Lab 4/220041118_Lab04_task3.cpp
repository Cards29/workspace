/*
    this is 220041118, Rahinur Bin Naushad
*/
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int account_num;
    string holder_name;
    string account_type;
    double current_balance;
    const double minimum_balance;
    static int count_total;
    static int count_present;
    static double tax;
    double interest_percent;
public:
    BankAccount() :minimum_balance(10),interest_percent(0.03) {
        count_present++;
        count_total++;
    }
    void assign(int ac_n, string hn, string ac_t, double cb) {
        account_num = ac_n;
        holder_name = hn;
        account_type = ac_t;
        current_balance = cb + minimum_balance;
    }
    void assign(int ac_n, string hn, string ac_t, double cb, double ip) {
        account_num = ac_n;
        holder_name = hn;
        account_type = ac_t;
        current_balance = cb + minimum_balance;
        interest_percent = ip;
    }
    double showBalance() {
        cout << "Current Balance : " << current_balance << endl;
        return current_balance;
    }
    void deposit(double amount) {
        current_balance += amount;
    }
    void withdrawal(double amount) {
        if ((current_balance + minimum_balance) < amount) {
            cerr << "Invalid amount" << endl;
            return;
        }
        current_balance -= amount;
    }
    void giveInterest() {
        tax += (current_balance * interest_percent);
        current_balance += (current_balance * 0.03);
    }
    static int total_accounts() {
        return count_total;
    }
    static int present_accounts(){
        return count_present;
    }
    static double total_tax() {
        return tax;
    }
    double getBalance() const {
        double cb = current_balance;
        return cb;
    }
    ~BankAccount() {
        count_present--;
        cout << "Account of Mr. " << holder_name << " with account no " << account_num << " is destroyed with a balance BDT " << current_balance << endl;
    }
};
int BankAccount::count_total(0);
int BankAccount::count_present(0);
double BankAccount::tax(0);
void display_stat() {
    cout << "Total number of bank accounts created : " << BankAccount::total_accounts() << endl;
    cout << "Total number of bank accounts currently present : " << BankAccount::total_accounts() << endl;
    cout << "Total amount of tax collected : " << BankAccount::total_tax() << endl;
}
BankAccount Larger(const BankAccount A, const BankAccount B) {
    if (A.getBalance() > B.getBalance()) return A;
    return B;
}

int main() {
    BankAccount b1, b2, b3;

    b1.assign(118, "Rahinur", "savings", 0);
    b2.assign(109, "Mahiul", "savings", 0, 0.05);
    b3.assign(102, "Rafat", "savings", 0, 0.5);

    display_stat();

    b1.deposit(300);
    b2.deposit(400);
    b3.deposit(500);

    b1.showBalance();
    b2.showBalance();
    b3.showBalance();

    b1.giveInterest();
    b2.giveInterest();
    b3.giveInterest();

    b1.withdrawal(100);
    b2.withdrawal(1000);
    b3.withdrawal(1000);

    b1.showBalance();
    b2.showBalance();
    b3.showBalance();

    display_stat();

    return 0;
}