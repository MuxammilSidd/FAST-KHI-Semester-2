//23K2001 Muzammil
#include<iostream>
using namespace std;
class waterbottle{
    private:

    string company, color;
    float mililiter,liter;
    public:
    void setCompany(string c_name)
    {
        company = c_name;
    }
    string getCompany()
    {
        return company;
    }
    void setColor(string col_name)
    {
        color = col_name;
    }
    string getColor()
    {
        return color;
    }
    void setMililiter(float ml)
    {
        mililiter = ml;
    }
    float getMililiter()
    {
        return mililiter;
    }
    void setliter()
    {
        liter = mililiter/1000;
    }
    float getliter()
    {
        return liter;
    }
    void update(float drink)
    {
        if(drink<mililiter)
        {
            mililiter-=drink;
            liter = mililiter/1000;
            cout<<"After person drink "<<drink<<" mL, now bottle contains:"<<endl;
            cout<<"In liter: "<<liter<<"\nIn milliliter: "<<mililiter<<endl;
        }
        else
        cout<<"You cannot drink more than bottle capacity, please input correct values."<<endl;
    }
    
};
int main()
{
    waterbottle cool;
    string namecompany,namecolor;
    cout<<"Input company name: ";
    cin>>namecompany;
    cool.setCompany(namecompany);
    cout<<"Input color: ";
    cin>>namecolor;
    cool.setColor(namecolor);
    int consumed, capacity;
    cout<<"Input capacity: ";
    cin>>capacity;
    cool.setMililiter(capacity);
    cool.setliter();
    cout<<"How much u drinked? ";
    cin>>consumed;
    cout<<"\nCompany: "<<cool.getCompany()<<endl;
    cout<<"Color: "<<cool.getColor()<<endl;
    cool.update(consumed);

    return 0;
}