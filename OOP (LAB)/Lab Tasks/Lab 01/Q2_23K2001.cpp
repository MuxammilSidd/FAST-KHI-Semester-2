//23k-2001 Muzammil
#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	float wgt,hgt,bmi;
	cout<<"Enter weight in pounds: ";
	cin>>wgt;
	cout<<"Enter height in inches: ";
	cin>>hgt;
	bmi = (wgt/(pow(hgt,2)))*703;
	cout<<"\n\tFor user: \nWeight: "<<wgt<<"\nHeight: "<<hgt;
	cout<<"\n\tBodyMassIndex: "<<bmi<<endl;
	return 0;
}

