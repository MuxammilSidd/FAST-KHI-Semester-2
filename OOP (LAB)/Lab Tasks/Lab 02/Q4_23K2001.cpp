//23K2001 Muzammil
#include<iostream>
using namespace std;

typedef struct product{
    int code, qt;
    string name;
    float price;
} product;

void add_prod(product *&p, int &n){
    n++;
    int i;
    product *sample = new product[n];
    for (i=0; i< n - 1;i++) {
        sample[i] = p[i];
    }
    delete[] p;
    p = sample;
    cout<<"|Enter product details|"<<endl;
    cout<<"for product#"<<n<<endl;
    cout<<"\nEnter product code: ";
    cin>>p[n-1].code;
    cout<<"\nEnter product name: ";
    cin>>p[n-1].name;
    cout<<"\nEnter product quantity: ";
    cin>>p[n-1].qt;
    cout<<"\nEnter product price: ";
    cin>>p[n-1].price;
    cout<<"\nProduct '"<<p[n-1].name<<"' added successfully"<<endl;
}

int disp_prod(product *p,string p_name,int n){
    
    int i,f= 0;
    if(p_name == "all")
    {
        for(i=0; i<n; i++)
        {
            cout<<"\nProduct#"<<i+1<<" :"<<endl;
            cout<<"Code: "<<p[i].code<<endl;
            cout<<"Name: "<<p[i].name<<endl;
            cout<<"Quantity: "<<p[i].qt<<endl;
            cout<<"Price: "<<p[i].price<<endl;
        }
        return 1;
    }
    
    else{
        for(i=0; i<n; i++)
        {
            if(p[i].name == p_name)
            {
                cout<<"\nProduct#"<<i+1<<" :"<<endl;
                cout<<"Code: "<<p[i].code<<endl;
                cout<<"Name: "<<p[i].name<<endl;
                cout<<"Quantity: "<<p[i].qt<<endl;
                cout<<"Price: "<<p[i].price<<endl;
                f = 1;
                return 1;
            }
        }
    }
    if(f==0)
    return 0;
}

int main()
{
    int ch;
    int n = 0, i;
    product *pr = new product[n];
    cout<<"*****Welcome to Inventory*****"<<endl;
    do{
        cout<<"\n\n1. Add product\n2. Display product\n3. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                add_prod(pr,n);
                break;
            }
            case 2:
            {
                if(n==0)
                cout<<"No products to display, please add some before."<<endl;
                else{
                    cout<<"\n1. Display all products\n\tOR\n0. Display a specific product"<<endl;
                    int d;
                    cin>>d;
                    if(d)
                    disp_prod(pr,"all",n);
                    
                    else{
                    string p_name;
                    cout<<"Input product name: ";
                    cin>>p_name;
                    if(disp_prod(pr,p_name,n)==0)
                    cout<<"No such product!"<<endl;
                    }
                }
                break;
            }
            case 3:
            {
                break;
            }
            default:
            cout<<"Invalid choice!"<<endl;
        }
    }while (ch!=3);

    delete[] pr;
    return 0;
}