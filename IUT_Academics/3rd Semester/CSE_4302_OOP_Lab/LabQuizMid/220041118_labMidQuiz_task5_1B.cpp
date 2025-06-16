#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Motorbike{
private:
    string modelno;
    double price;
    string manufacturer;

public:
    Motorbike():modelno("123"),price(3435),manufacturer("Faisal") {}
    Motorbike(string m, double p, string mn):modelno(m),price(p),manufacturer(mn) {}

    void display() const {
        cout<<"Model no. "<<modelno<<endl
            <<"Price: "<<price<<endl
            <<"Manufacturer: "<<manufacturer;
    }
    bool compare(Motorbike m1) const {
        return manufacturer>m1.manufacturer;
    }

    // ~Motorbike(){
    //     cout<<"Object was destroyed"<<endl;
    // }
};

void sortbymanufacturer(Motorbike m[]){
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(m[i].compare(m[j])){
                Motorbike temp=m[i];
                m[i]=m[j];
                m[j]=temp;
            }
        }
    }
}

int main(){
    Motorbike m[10];
    sortbymanufacturer(m);
    for(int i=0;i<10;i++){
        m[i].display();
        cout<<endl<<endl;
    }

    return 0;
}