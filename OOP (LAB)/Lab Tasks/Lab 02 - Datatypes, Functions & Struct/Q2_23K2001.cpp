//23K2001 Muzammil
#include<iostream>
using namespace std;
void num_swap(int *x,int *y)
{
    *x = *x+*y;
    *y = *x - *y;
    *x = *x - *y;
}
int main(){
    int m,n;
    cout<<"Input 2 numbers: m:? n:?"<<endl;
    cin>>m>>n;
    cout<<"(Swapped by function): "<<endl;
    num_swap(&m,&n);
    cout<<"m: "<<m<<"\tn: "<<n<<endl;

    return 0;
}