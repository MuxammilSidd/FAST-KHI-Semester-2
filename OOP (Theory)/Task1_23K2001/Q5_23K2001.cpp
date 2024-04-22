//23K2001 Muzammil
#include<iostream>
using namespace std;

class AddAmount{
    private:
    int amount =50;

    public:
    AddAmount()
    {
        cout<<"Constructor invoked WITHOUT any parameter, no amount added.\n"<<endl;
    }
    AddAmount(int deposit)
    {
        cout<<"Constructor invoked WITH one parameter, amount deposit successful!\n"<<endl;
        amount+=deposit;
    }
    int getAmount()
    {
        return amount;
    }
};

int main()
{
    AddAmount loan;
    int m;
    cout<<"Input amount to store in PiggyBank: ";
    cin>>m;
    AddAmount saving(m);
    cout<<"Final amount: "<<saving.getAmount()<<endl;
    return 0;
}