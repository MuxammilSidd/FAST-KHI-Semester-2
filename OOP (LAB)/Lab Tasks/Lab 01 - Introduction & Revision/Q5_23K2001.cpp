//23k-2001 Muzammil
#include <iostream>
using namespace std;
int main()
{
    int a[3][3], b[3][3],x[3][3]={0};
    int i,j,l;
    cout<<"\tInput elements for matrice A:"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        cin>>a[i][j];
    }
    cout<<"\n\n\tInput elements for matrice B:"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        cin>>b[i][j];
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            x[i][j]+=a[i][j]-b[i][j];
        }
    }
    cout<<"\n\nAfter subtraction: \nAnswer: "<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        cout<<" "<<x[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}