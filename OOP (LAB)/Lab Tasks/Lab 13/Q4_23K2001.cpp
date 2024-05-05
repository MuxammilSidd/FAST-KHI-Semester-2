//23k2001  Q4
#include<iostream>
using namespace std;
template<class T>T factorial(T num){
    if(num==1 || num==0)
    return 1;

    return num*factorial(num-1);
}
int main()
{
	int n = 7;
    cout<<"Factorial for "<<n<<" is ";
    cout<<factorial(n);
	return 0;
}