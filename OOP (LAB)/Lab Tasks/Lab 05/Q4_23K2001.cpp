//23K2001 Muzammil Q4
#include<iostream>
using namespace std;
class book{
private:
string title;
float price;
public:
book():title(""),price(0.0){}
book(string title, float price):title(title),price(price){}
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
book *books;
int n=0;

public:
inventory() {
books = nullptr;
}
book* getBooks() const{
    return books;
}
int getNumBooks() const
{
    return n;
}
void addBook(const book& newbook)
{
    int i;
    n++;
    book *b = new book[n];
    for(i=0;i<n-1;i++)
    {
    b[i] = books[i];
    }
    delete[] books;
    books = b;
    books[n-1] = newbook;
    cout<<"\nBook added successfully!"<<endl;
}

void removeBook()
{
    int x,i;
    if(displayInv()==true){
        cout<<"Please select which book# to remove? ";
        cin>>x;
        if(x > 0 && x<=n)
        {
            for(i=x-1;i<n-1;i++)
            {
                books[i] = books[i+1];
            }
            
            n--;
            book* newBooks = new book[n];
            for(int i = 0; i < n; i++)
            {
                newBooks[i] = books[i];
            }
            delete[] books; 
            books = newBooks; 
            cout << "\nBook removed successfully!" << endl;
        }
        else
        cout<<"\nInvalid # , please try again!"<<endl;
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
        cout<<"\nNo books to display in inventory, please add some first!"<<endl;
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
payment p;

public:
order(int n) : x(n){
    b = new book[x];
}
void placeOrder(const inventory& inv)
{
    int i,j;
    int booknum[x];
    int booksinInv = inv.getNumBooks();
    float amount=0;
    cout<<"\nPlease select which book# to order? ";
    for(i=0;i<x;i++)
    {
        cout<<"\nBook "<<i+1<<": ";
        cin>>booknum[i];
        if(booknum[i]>booksinInv || booknum[i]==0)
        {
            cout<<"\nInvalid # , there is no book#"<<booknum[i]<<"!!!"<<endl;
            cout<<"Kindly select again: ";
            i--;
            continue;
        }
        cout<<"\nSelected Book#"<<booknum[i]<<endl;
        booknum[i]-=1;
    }
    for(i=0;i<x;i++)
    {
        b[i]=(inv.getBooks())[booknum[i]];
        amount+=b[i].getPrice();
    }
    p.setAmount(amount);
    displayOrderinfo();
    cout<<"\nTotal payment: "<<p.getAmount()<<endl;
    cout<<"Order placed successfully!"<<endl;
}
void displayOrderinfo()
{
    int i;
    cout<<"\nUser ordered "<<x<<" book/books:"<<endl;
    cout<<"\n#    Title:\tPrice:"<<endl;
    for(i=0;i<x;i++)
    {
        cout<<i+1<<"    "<<b[i].getTitle()<<"\t"<<b[i].getPrice()<<endl;
    }
}
~order(){
    delete[] b;
}
};

int main()
{
    inventory fastInventory;
    cout<<"\t\tWelcome to FAST INVENTORY SYSTEM\n"<<endl;
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

        switch(ch){
            case 1:
            {
                string title;
                float p;
                cout<<"Input title: ";
                cin>>title;
                cout<<"Input price: ";
                cin>>p;
                book b(title,p);
                fastInventory.addBook(b);
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
                if(fastInventory.displayInv()==true)
                {
                    int n;
                    cout<<"How many books you want to order: ";
                    cin>>n;
                    order recent(n);
                    recent.placeOrder(fastInventory);
                    break;
                }
                else
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