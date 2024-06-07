//23K2001 Muzammil Q2
#include<iostream>
using namespace std;
class carRent{
    private:
    float perday = 50.75;
    const string name;
    int days;
    double rent;

    public:
    carRent(string name,int days) : name(name), days(days)
    {
        rent = days*perday;
    }
    void withDiscount()
    {
        if(days>7){
        cout<<"Congrats you got one-day off discount! Previous rent: "<<rent<<endl;
        rent-=perday;
        cout<<"After discount, rent: "<<rent<<endl;
        }
        else{
        cout<<"Sorry, no discount applicable!"<<endl;
        withoutDiscount();
        }
    }
    void withoutDiscount()
    {
        cout<<"Your rent: "<<rent<<endl;
    }
    void display() const{
        cout<<"\nName: "<<name<<endl;
        cout<<"Days: "<<days<<endl;
        cout<<"Rent amount: "<<rent<<endl;
    }
};

int main()
{
    carRent toyota("Mr. Ahmed",5);
    carRent honda("Ms. Noor",18);

    cout<<"Object with <7 days:"<<endl;
    toyota.withDiscount();
    toyota.display();

    cout<<"\nObject with >7 days:"<<endl;
    honda.withDiscount();
    honda.display();
    return 0;
}