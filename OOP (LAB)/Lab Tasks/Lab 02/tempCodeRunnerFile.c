//23K2001 Muzammil
#include<iostream>
using namespace std;

typedef struct product{
    int code, qt;
    string name;
    float price;
} product;

void add_prod(product *p){

}

void disp_prod(product *p){

}

int main()
{
    int ch=0;
    cout<<"*****Welcome to Inventory*****"<<endl;
    do{
        cout<<"\n\n1. Add product\n2. Display product\n3. Exit"<<endl;
    }while (ch==3);
    return 0;
}