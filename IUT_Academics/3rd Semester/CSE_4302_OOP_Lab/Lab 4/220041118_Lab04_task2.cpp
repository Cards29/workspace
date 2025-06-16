/*
    this is 220041118, Rahinur Bin Naushad
*/
#include <iostream>
#include <string>

using namespace std;

class Plane {
private:
    int flight_num;
    string destination;
    float distance;
    float MaxFuelCapacity;
    double CalFuel() {
        if (distance <= 1000)
            return 500;
        if (distance > 1000 && distance <= 2000)
            return 110;
        if (distance > 2000)
            return 2200;
    }
public:
    Plane() :flight_num(0), destination(""), distance(0), MaxFuelCapacity(0) {}
    void FeedInfo(int fn, string des, float dis, float mfc) {
        flight_num = fn;
        destination = des;
        distance = dis;
        MaxFuelCapacity = mfc;
    }
    void ShowInfo() {
        cout << "Flight number : " << flight_num << endl
            << "Destination : " << destination << endl
            << "Distance : "<<distance<<endl
            << "Max Fuel Capacity : "<<MaxFuelCapacity<<endl;

        if(MaxFuelCapacity>=CalFuel()){
            cout << "Fuel capacity is fit for this flight distance"<<endl;
        }
        else if (MaxFuelCapacity < CalFuel()) {
            cout << "Not sufficient Fuel Capacity for this flight." << endl;
        }
    }
    ~Plane() {
        cout<<"Destructor called for this plane object"<<endl;
    }
};


int main() {

    Plane p;

    p.FeedInfo(118,"Chattogram",250,1000);
    p.ShowInfo();

    return 0;
}
