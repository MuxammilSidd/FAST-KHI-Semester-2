#include<iostream>
using namespace std;

class bankAccount{
    public:
        string accName;
        float balance;
        void set_balance(int amount)
        {
            balance = amount;
            cout<<"Balance initialized successfully."<<endl;
        }
        void deposit(int amount)
        {
            balance += amount;
            cout<<"Amount deposited successfully. \nBalance is: "<<balance<<endl;
        }
        int withdraw(int amount)
        {
            if(balance<amount)
            cout<<"Insufficient balance. Please deposit!"<<endl;
            else
            {
                balance -= amount;
                cout<<"Amount withdrawed successfully. \nBalance is: "<<balance<<endl;
            }
        }
};

int main()
{
    int choice;
    bankAccount john;
    do
    {
    cout<<"\nSelect option: \n1. Initialize balance.\n2. Deposit amount.\n3. Withdraw amount.\n4. Exit"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        john.set_balance(1000); break;

        case 2:
        john.deposit(1500); break;

        case 3:
        john.withdraw(800); break;

        case 4:
        return 0;

        default:
        cout<<"Invalid choice!"<<endl;
    }
    } while(choice!=4);

    return 0;
}