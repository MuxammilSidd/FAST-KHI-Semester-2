//23k-2001 Muzammil
#include <iostream>
using namespace std;
int main()
{
	int num[10],j;
	cout<<"Please enter values: "<<endl;
	for(j=0;j<10;j++)
	{
		cin>>num[j];
	}
	cout<<"\nBefore replacing: \n";
	for(j=0;j<10;j++)
	cout<<num[j]<<" ";
	
	cout<<"\nAfter replacing: \n";
	for(j=0;j<10;j++)
	{
		if(num[j]%2==1)
		{
			num[j]=0;
		}
		else
		{
			num[j]=1;
		}
	}

	for(j=0;j<10;j++)
	cout<<num[j]<<" ";
	return 0;
}

