//23K2001 Muzammil
#include<iostream>
using namespace std;

class CustomerAccount{
    private:
    string name;
    int type;
    long long accNum;
    float balance;

    public:
    CustomerAccount()
    {
        name = "xyz";
        type = 2;
        accNum = 1234;
        cout<<"..default attributes assigned"<<endl;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setType(int type)
    {
        this->type = type;
    }
    void setAccno(long long accNum)
    {
        while (accNum>= 10000)
        {
            accNum /= 10;
    }
        this->accNum = accNum;
    }
    void setBalance(float balance)
    {
        this->balance += balance;
    }
    string getName()
    {
        return name;
    }
    int getType()
    {
        return type;
    }
    long long getAccno()
    {
        return accNum;
    }
    float getBalance()
    {
        return balance;
    }
    


    void initialAmount()
    {
        cout<<"..Setting initial balance (5000)"<<endl;
        balance = 5000;
    }
    void check(int amount)
    {
        if(balance > amount && amount<=25000){
        balance -= amount; 
        cout<<"Transaction succesful. Balance: "<<balance<<endl;
        }

        else
        cout<<"Transaction failed!"<<endl;
    }
    void info()
    {
        cout<<"\n..user requested info"<<endl;
        cout<<"\nDetails of Acc#"<<getAccno()<<":"<<endl;
        cout<<"Name: "<<name<<"\nBalance: "<<balance<<endl;
    }
};
int main()
{
    CustomerAccount myself;
    cout<<"Default attributes: "<<endl;
    cout<<"Name: "<<myself.getName()<<"\nType: "<<myself.getType()<<endl;
    cout<<"Account no#"<<myself.getAccno()<<endl;
    myself.initialAmount();

    string name;
    int type, ac_num;
    float balance;

    cout<<"Input name: ";
    cin>>name;
    myself.setName(name);

    cout<<"Input Account type (1. Savings\t2.Current): ";
    cin>>type;
    myself.setType(type);

    cout<<"Input Account number: ";
    cin>>ac_num;
    myself.setAccno(ac_num);

    cout<<"Input balance: ";
    cin>>balance;
    myself.setBalance(balance);
    myself.info();

    int amount;
    cout<<"Input amount to withdraw: ";
    cin>>amount;
    myself.check(amount);

    return 0;
}