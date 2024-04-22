//23K2001 Muzammil
#include<iostream>
using namespace std;
typedef struct bankAccount{
    int acc_n;
    string ac_name;
    float balance;
}account;

void deposit(int cash, float *b)
{
    *b = *b+cash;
}
void withdraw(int cash, float *b)
{
    if(cash>*b){
    cout<<"Your balance is NOT enough!"<<endl;
    }
    else
    *b = *b-cash;
}
void displayAcc(account *a)
{
    cout<<"\nAccount number: ";
    cout<<a->acc_n;
    cout<<"\nAccount holder name: ";
    cout<<a->ac_name;
    cout<<"\nBalance: ";
    cout<<a->balance;
}
int main()
{
    account m;
    cout<<"Input Acc_Number: ";
    cin>>m.acc_n;
    cout<<"Input name: ";
    cin>>m.ac_name;
    m.balance = 0;
    cout<<"\n";
    int ch;
    do{
        cout<<"\n\n1. Display info\n2. Deposit\n3. Withdraw\n4. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:{
            displayAcc(&m);
            break;}

            case 2: 
            {
                int cash;
                cout<<"Input amount to deposit: ";
                cin>>cash;
                deposit(cash,&(m.balance));
                break;
            }
            case 3: 
            {
                int cash;
                cout<<"Input amount to withdraw: ";
                cin>>cash;
                withdraw(cash,&(m.balance));
                break;
            }

            case 4:
            return 0;
            
            default:
            cout<<"Invalid choice, enter again."<<endl;
        }
    }
    while(ch!=4);
    
    return 0;
}