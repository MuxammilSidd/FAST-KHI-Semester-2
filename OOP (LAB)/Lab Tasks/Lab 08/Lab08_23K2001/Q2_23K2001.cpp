//23K2001 Q2
#include<iostream>
using namespace std;

class account{
protected:
double balance;

public:
account(double balance) : balance(balance){
    if(balance<0)
    {
        balance = 0.0;
        cout<<"Invalid initial balance set, now it is set to 0.0!"<<endl;
    }
}
void credit(double amount)
{
    balance+=amount;
    cout<<"Amount deposit successfully"<<endl;
}
bool debit(double amount)
{
    if(amount<=balance)
    {
        balance-=amount;
        cout<<"Amount withdraw successfully"<<endl;
        return true;
    }
    else
    {
    cout<<"Debit exceeded user account balance!"<<endl;
    return false;
    }
}
double getBalance()
{
    return balance;
}

};

class savAccount : public account{
protected:
double interest;

public:
savAccount(double bal,double I) : account(bal), interest(I){}

double calcInterest()
{
    return interest*getBalance();
}

};

class checkAcc : public account{
protected:
double fee;

public:
checkAcc(double bal, double fee) : account(bal),fee(fee){}

void credit(double amount)
{
    account::credit(amount-fee);
    cout<<"(Fee deducted successfully)"<<endl;
}
bool debit(double amount)
{
    // if(account::debit(amount)==true)
    // {
    //     if(account::debit(fee)==true)
    //     cout<<"(Fee deducted successfully)"<<endl;
    //     else
    //     cout<<"(Not enough balance for fees)"<<endl;
    // }

    if(account::debit((amount+fee))==true)
    {
        cout<<"(Fee deducted successfully)"<<endl;
    }
    else
    cout<<"Insufficient balance!"<<endl;

}
};

int main()
{
    account muz(34600.56908);
    savAccount s1(8950.2378,0.25);
    checkAcc c1(6720.9054,160.10);
    cout<<"Functions for account class: "<<endl;
    muz.credit(450.90);
    muz.debit(5000.2350);
    cout<<"Balance: "<<muz.getBalance()<<endl;

    cout<<"\nFunctions for savingAccount class: "<<endl;
    s1.credit(520.963);
    s1.debit(10000);
    cout<<"Balance: "<<s1.getBalance()<<endl;
    cout<<"Interest: "<<s1.calcInterest()<<endl;
    s1.credit(s1.calcInterest());
    cout<<"Balance after added interest: "<<s1.getBalance()<<endl;

    cout<<"\nFunctions for checkAccount class: "<<endl;
    c1.credit(1400.87);
    c1.debit(500.490);
    cout<<"Balance: "<<c1.getBalance()<<endl;
    return 0;
}