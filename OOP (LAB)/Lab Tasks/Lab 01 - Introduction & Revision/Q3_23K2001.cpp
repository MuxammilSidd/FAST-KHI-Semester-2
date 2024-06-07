//23k-2001 Muzammil
#include <iostream>
using namespace std;
void find_two_largest(int num[], int size, int *largest, int *second_largest){
	int j,k,t;
	for(j=0;j<size;j++)
	{
		for(k=0;k<size-1;k++){
		if(num[k]>num[k+1])
		{
			t=num[k+1];
			num[k+1]=num[k];
			num[k]=t;
		}	
		}
		
	}
	*largest = num[size-1];
	*second_largest = num[size-2];
}
int main()
{
	int l,i;
	cout<<"Enter length of array: ";
	cin>>l;
	int arr[l];
	int greatest,sec_greatest;
	cout<<"Enter values :\n";
	for(i=0;i<l;i++){
		cin>>arr[i];
	}
	find_two_largest(arr,l,&greatest,&sec_greatest);
	cout<<"\nGreatest is: "<<greatest<<"\n2nd-Greatest is: "<<sec_greatest;
	return 0;
}

