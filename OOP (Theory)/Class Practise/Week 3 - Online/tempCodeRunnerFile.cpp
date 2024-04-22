#include<iostream>
using namespace std;
const int h()
{
    return 1;
}
void f(const int i)
{
    // i++;
}
int main()
{
    const int j = h();
    int k = h();
    cout<<j<<endl;
    cout<<k<<endl;
    int i = 10;
    cout<<f(i);
    return 0;
}