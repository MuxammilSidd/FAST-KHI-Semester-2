//23K2001 Muzammil Q5
#include<iostream>
using namespace std;
class book{
private:
string title, author,isbn,genre;
bool status;
public:
book(string t,string a,string i,string g,bool s=true)
{
    title = t;
    author = a;
    isbn = i;
    genre = g;
    status = s;
}
book(){}
void displayBookinfo()
{
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"ISBN: "<<isbn<<endl;
    cout<<"Genre: "<<genre<<endl;
    cout<<"Availablity: ";
    if(status==true)
    cout<<"Available"<<endl;
    else
    cout<<"Issued"<<endl;
}
string getTitle(){
    return title;
}
string getAuthor(){
    return author;
}
string getisbn(){
    return isbn;
}
string getGenre(){
    return genre;
}
void setStatus(bool s)
{
    status = s;
}
bool getStatus() const {
    return status;
}
};

void displayBooks(book b[],int n)
{
    int i;
    cout<<"# "<<"Title:\t\t"<<"\tStatus:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<i+1<<" "<<b[i].getTitle()<<"-------------------(";
        if(b[i].getStatus()==true)
        cout<<"Available)"<<endl;
        else
        cout<<"Issued)"<<endl;
    }
}

class patron{
private:
string name;
int n=0;
book *borrowed;

public:
patron(){borrowed = nullptr;}
patron(string name):name(name){
    borrowed = nullptr;
}
~patron(){delete[] borrowed;}

void borrowBook(book& b)
{
    int i;

    if (borrowed == nullptr && b.getStatus()==true) {
        n++;
        borrowed = new book[n];
        b.setStatus(false);
        borrowed[0] = b;
        cout<<"\nBook borrowed successfully by "<<name<<"!"<<endl;
    }

    else if(b.getStatus()==true)
    {
        n++;
        book *updated = new book[n];
        for(i=0;i<n-1;i++)
        {
            updated[i] = borrowed[i];
        }
        delete[] borrowed;
        b.setStatus(false);
        borrowed = updated;
        borrowed[n-1]=b;
        cout<<"\nBook borrowed successfully by "<<name<<"!"<<endl;
    }
    else
    cout<<"This book is not available, please select some other."<<endl;
}
void returnBook()
{
    cout<<endl;
    if(displayBorrowed()==true)
    {
    int x,i;
    cout<<"\nSelect which book to return: ";
    cin>>x;
    if(x>0 && x<=n)
    {
        borrowed[x-1].setStatus(true);
        for(i=x-1;i<n-1;i++)
        {
            borrowed[i]=borrowed[i+1];
        }
        delete &borrowed[n-1];
        n-=1;
        cout<<"\nBook returned successfully!"<<endl;
    }
    else
        cout<<"\nInvalid # , please try again!"<<endl;
    }
}
void displayPatroninfo()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Borrowed books: "<<endl;
    displayBorrowed();
}
bool displayBorrowed()
{
    if(n!=0)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cout<<i+1<<" "<<borrowed->getTitle()<<" ISBN: "<<borrowed->getisbn()<<endl;
        }
        return true;
    }
    else
    {
        cout<<"\nNo books to display for Patron: "<<name<<", please issue some first!"<<endl;
        return false;
    }
}
string getName()
{
    return name;
}
};

class loan{
private:
string due;

public:
loan(const patron *p){

}
};

int main()
{
    patron m("Muzammmil");
    patron q("Qasim");

    book bookshelf[4]={book("Mathematics","Sindh Board","MT2001029FS","Academic"),book("Urdu","Faiz","SS1008297FS","Research",true),
    book("Calculus","Anton","MT8400229SS","Academic",false),book("Fundamentals of Physics","Pearlson","EE1002534SS","Academic",false)};

    int ch;
    do {
        cout<<"\nMenu:"<<endl;
        cout<<"1. Borrow a book"<<endl;
        cout<<"2. Return a book"<<endl;
        cout<<"3. Display loan"<<endl;
        cout<<"4. Display books"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Input choice: ";
        cin>>ch;

        switch (ch) {
            case 1:
            {
                int u;
                cout<<"Patrons:"<<endl;
                cout<<"1. "<<m.getName()<<"\n2. "<<q.getName()<<endl;
                cout<<"\nPlease select for which patron: ";
                cin>>u;

                if(u==1)
                {
                    cout<<"Which book "<<m.getName()<<" wants to borrow?"<<endl;
                    displayBooks(bookshelf,4);
                    int s;
                    cin>>s;
                    m.borrowBook(bookshelf[s-1]);
                }
                else if(u==2)
                {
                    cout<<"Which book "<<q.getName()<<" wants to borrow?"<<endl;
                    displayBooks(bookshelf,4);
                    int s;
                    cin>>s;
                    q.borrowBook(bookshelf[s-1]);
                }
                else
                cout<<"Invalid input."<<endl;

                break;

            }
            case 2:
            {
                int u;
                cout<<"Patrons:"<<endl;
                cout<<"1. "<<m.getName()<<"\n2. "<<q.getName()<<endl;
                cout<<"\nPlease select for which patron: ";
                cin>>u;

                if(u==1)
                {
                    
                    m.returnBook();
                }
                else if(u==2)
                {
                    
                    q.returnBook();
                }
                else
                cout<<"Invalid input."<<endl;
                break;
            }
            case 3:
            {
                break;

            }
            case 4:{
                displayBooks(bookshelf,4);
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