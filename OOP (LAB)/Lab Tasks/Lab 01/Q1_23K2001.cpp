//23k-2001 Muzammil
#include<iostream>
using namespace std;
int main(){
	int ch,amt,bal=0;
    cout<<"Welcome to AL Habib Banking System"<<endl;

    do{
    	cout<<"\n\t1. Deposit fund\n\t2. Withdraw fund\n\t3. Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>ch;
    switch(ch){
    	case 1:
    		{
    			cout<<"Enter amount to deposit: ";
    			cin>>amt;
    			bal+=amt;
    			cout<<"\nDeposit successful. New balance is: "<<bal<<endl;
    			break;
			}
		case 2:
    		{
    			cout<<"Enter amount to withdraw: ";
    			cin>>amt;
    			if(bal<amt)
    			{
    				cout<<"\nNOT ENOUGH BALANCE!!PlEASE DEPOSIT FIRST\n";
				}
				else{
					bal-=amt;
    		    cout<<"\nWithdraw successful. New balance is: "<<bal<<endl;
				}
				break;
			}
		case 3:
    		{
    			return 0;
			}
		default:{
			cout<<"\n\tPlease enter valid option.";
		}	
	}
	}
	while(ch!=3);
    return 0;
}
