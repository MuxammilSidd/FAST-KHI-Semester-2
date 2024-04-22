//23K2001 Muzammil Q4
#include<iostream>
using namespace std;
class book{
private:
string title;
float price;
public:
void setTitle(string title)
{
    this->title = title;
}
void setPrice(float price)
{
    this->price = price;
}
string getTitle()
{
    return title;
}
float getPrice()
{
    return price;
}
};
class payment{
private:
float amount;
public:
void setAmount(float a)
{
    amount = a;
}
float getAmount()
{
    return amount;
}
};

class inventory{
private:
int n=0;
book *books;
public:
inventory() {
books = nullptr;
}
void addBook()
{
string title;
float p;
int i;
n++;
book *b = new book[n];
for(i=0;i<n-1;i++)
{
b[i] = books[i];
}
delete books;
books = b;
cout<<"Input title: ";
cin>>title;
cout<<"Input price: ";
cin>>p;
books[n-1].setPrice(p);
books[n-1].setTitle(title);
cout<<"\nBook added successfully!"<<endl;
}

void removeBook()
{
int x,i,f=0;
    if(displayInv()==true){
        cout<<"Please select which book# to remove? ";
        cin>>x;
        if(x>0 && x<=n)
        {
        delete &books[x-1];
        for(i=x-1;i<n-1;i++)
        {
            books[i]=books[i+1];
        }
        n-=1;
        cout<<"\nBook removed successfully!"<<endl;
        }
        // f=1;
        // break;
        // if(f==1)
        // cout<<"\nBook removed successfully!"<<endl;
        else
        cout<<"\nInvalid # , please try again!"<<endl;
        // }
    }
}
bool displayInv()
{
    if(n!=0)
    {
        int i;
        cout<<"\n#    Title:\tPrice:"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<i+1;
            cout<<"    "<<books[i].getTitle()<<"\t"<<books[i].getPrice()<<endl;
        }
        return true;
    }
    else{
        cout<<"\nNo books to display, please add some first!"<<endl;
        return false;
    }
}

~inventory()
{
    delete[] books;
}
};

class order{
private:
int x;
book *b;
payment *p;

public:
void placeOrder()
{
    
}

};

int main()
{
    inventory fastInventory;
    
    int ch;
    do {
        cout<<"\nMenu:"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Remove Book"<<endl;
        cout<<"3. Display Entire Inventory"<<endl;
        cout<<"4. Place Order"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Input choice: ";
        cin>>ch;

        switch (ch) {
            case 1:
            {
                fastInventory.addBook();
                break;

            }
            case 2:
            {
                fastInventory.removeBook();
                break;

            }
            case 3:
            {
                fastInventory.displayInv();
                break;

            }
            case 4:{
                // Add code to place order
                break;

            }
            case 5:
                return 0;
            default:
                cout<<"Invalid input!"<<endl;
        }
    } while(ch!=5);
    return 0;
}