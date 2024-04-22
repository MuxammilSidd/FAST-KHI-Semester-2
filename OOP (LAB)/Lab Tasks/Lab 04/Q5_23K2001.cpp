//23K2001 Muzammil
#include<iostream>
using namespace std;
class phone{
    private:
    string area,exc,num;

    public:
    phone(string telephone)
    {
        
        area = telephone.substr(0,3);
        exc = telephone.substr(3,4);
        num = telephone.substr(7,4);

    }
    void displayDetails()
    {
        cout<<"Your area code is:- "<<area<<endl;
        cout<<"Your exchange code is:- "<<exc<<endl;
        cout<<"Your consumer no# is:- "<<num<<endl;
    }
};
int main()
{
    cout<<"Input your contact number (11 digit): ";
    string p;
    cin>>p;
    phone me(p);
    me.displayDetails();
    return 0;
}