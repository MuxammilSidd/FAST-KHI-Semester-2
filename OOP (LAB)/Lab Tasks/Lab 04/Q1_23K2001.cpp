//23K2001 Muzammil
#include<iostream>
using namespace std;
class bankAccount{
	private:
	int accNum;
	string accHolder;
	float bal;
	
	public:
	void setNum(int num)
	{
		accNum = num;
	}
	void setHol(string name)
	{
		accHolder = name;
	}
	void setBal(int balance)
	{
		bal = balance;
	}
	int getNum()
	{
		return accNum;
	}
	string getHol()
	{
		return accHolder;
	}
	int getBal()
	{
		return bal;
	}
	bankAccount(int num, string name, float balance)
	{
		accNum = num;
		accHolder = name;
		bal = balance;
	}
	void deposit(int amt)
	{
		bal+=amt;
		cout<<"Amount was deposited succesfully."<<endl;
		cout<<"Balance: "<<bal;
	}
	void withdraw(int amt)
	{
		if(bal>amt)
		{
			bal-=amt;
			cout<<"Amount was withdrawed succesfully."<<endl;
			cout<<"Balance: "<<bal<<endl;
		}
		else
		cout<<"Not enough balance is present."<<endl;
	}
	~bankAccount()
	{
		cout<<"\n\nDestructor called, memory released!"<<endl;
	}
};
int main()
{
    bankAccount fastian(230000,"student",5000);
    cout<<"Values passed through parameterized constructor: \n"<<endl;
    cout<<"Account number: "<<fastian.getNum()<<endl;
    cout<<"Holder name: "<<fastian.getHol()<<endl;
    cout<<"Balance: "<<fastian.getBal()<<endl;
    int num;
    string name;
    float balance;
    cout<<"\nInput account number: ";
    cin>>num;
    cout<<"Input account holder name: ";
    cin>>name;
    cout<<"Input balance: ";
    cin>>balance;
	fastian.setNum(num);
	fastian.setHol(name);
	fastian.setBal(balance);
	cout<<"\nValues set by user: \n"<<endl;
    cout<<"Account number: "<<fastian.getNum()<<endl;
    cout<<"Holder name: "<<fastian.getHol()<<endl;
    cout<<"Balance: "<<fastian.getBal()<<endl;
    
    float amount;
    int ch;
    do{
    	cout<<"\n1. Deposit\n2. Withdraw\n0. Exit"<<endl;
    	cin>>ch;
	    switch(ch)
	    {
	    	case 0:		
	    	return 0;
	    	
	    	case 1:
	    		{
	    		cout<<"\nInput amount to deposit: ";
				cin>>amount;
				fastian.deposit(amount);	
				break;
				}
			case 2:
			{
			cout<<"\nInput amount to withdraw: ";
			cin>>amount;
			fastian.withdraw(amount);
			break;	
			}
			default:
			cout<<"Invalid choice!"<<endl;
		}	
	}while(ch!=0);
    	
    return 0;
}