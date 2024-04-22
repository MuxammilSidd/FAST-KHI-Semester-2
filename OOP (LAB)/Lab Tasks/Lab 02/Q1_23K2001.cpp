//23K2001 Muzammil
#include<iostream>
using namespace std;
int num_gcd(int x, int y)
{
    int z;

    if(y==0)
	return x;

	else
	{
		return num_gcd(y,x%y);	}	
	
}

int num_lcm(int x,int y,int res) 
{
    if (res% x == 0 && res % y == 0) 
    {
        return res;

    }
    
    return num_lcm(x,y,res+1);
}

int main()
{
    int m,n;
    cout<<"Enter two numbers for GCD and LCM"<<endl;
    cin>>m>>n;
    cout<<"GCD: "<<num_gcd(m,n)<<endl;
    cout<<"LCM: "<<num_lcm(m,n,1)<<endl;
    return 0;
}
