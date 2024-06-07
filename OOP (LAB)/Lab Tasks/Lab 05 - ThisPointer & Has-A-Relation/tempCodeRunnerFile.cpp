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

class loan{
private:
int due;

public:
loan(int d=20240101){due = d;}

void setDuedate(int d)
{
    due = d;
}
int getDuedate()
{
    return due;
}
};

class fine{
    private:
    float finemoney=0;
    public:
    void checkforfine(loan l,int d)
    {
        if(d>l.getDuedate())
        {
        finemoney+=500;
        cout<<"Patron has to pay fine of Rs:"<<finemoney<<" for late return!"<<endl;
        }
    }
};

class patron{
private:
string name;
int n;
book** borrowed;
loan* loans;
fine f;

public:
patron(){borrowed = nullptr;
loans = nullptr;
n=0;}
patron(string name):name(name){
    borrowed = nullptr;
    loans = nullptr;
    n=0;
}
~patron(){delete[] borrowed;
delete[] loans;}

void borrowBook(book& b)
{
    int i;

    if ((borrowed == nullptr && loans == nullptr) && b.getStatus()==true) {
        n++;
        borrowed = new book*[n];
        loans = new loan[n];
        cout<<"\nSet due date for returning this book (YYYY/MM/DD): ";
        int d;
        cin>>d;
        loans[0].setDuedate(d);
        b.setStatus(false);
        borrowed[0] = &b;
        cout<<"\nBook borrowed successfully by "<<name<<"!"<<endl;
    }

    else if(b.getStatus()==true)
    {
        n++;
        book** updated = new book*[n];
        loan* l = new loan[n];
        for(i=0;i<n-1;i++)
        {
            updated[i] = borrowed[i];
            l[i]=loans[i];
        }
        delete[] borrowed;
        delete[] loans;
        cout<<"\nSet due date for returning this book (YY/MM/DD): ";
        int d;
        cin>>d;
        b.setStatus(false);
        updated[n-1] = &b;
        borrowed = updated;
        loans = l;
        loans[n-1].setDuedate(d);
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
        int today;
        cout<<"Input today's date (YYYY/MM/DD): ";
        cin>>today;
        f.checkforfine(loans[x-1],today);
        borrowed[x-1]->setStatus(true);
        for(i=x-1;i<n-1;i++)
        {
            borrowed[i]=borrowed[i+1];
            loans[i]=loans[i+1];
        }

        n--;
        book** updatedbooks = new book*[n];
        loan* updatedloans = new loan[n];
        for(i=0;i<n;i++)
        {
            updatedbooks[i] = borrowed[i];
            updatedloans[i] = loans[i];
        }

        delete[] borrowed;
        delete[] loans;
        borrowed = updatedbooks;
        loans = updatedloans;

        cout<<"\nBook returned successfully by "<<name<<"!"<<endl;
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
    if(n>0)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cout<<i+1<<" "<<borrowed[i]->getTitle()<<"-----\tDue Date (YY/MM/DD): "<<loans[i].getDuedate()<<endl;
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

void trackLoans(patron **p, int patrons)
{
    int i;
    for(i=0;i<patrons;i++)
    {
        cout<<"\nPatron#"<<i+1<<":"<<endl;
        p[i]->displayPatroninfo();
    }
}

int main()
{
    patron m("Muzammmil");
    patron q("Qasim");
    patron *patrons[]={&m,&q};
    book bookshelf[6]={book("Mathematics","Sindh Board","MT2001029FS","Academic"),book("Urdu","Faiz","SS1008297FS","Research",true),
    book("Calculus","Anton","MT8400229SS","Academic",false),book("Fundamentals of Physics","Pearlson","EE1002534SS","Academic",true),book("LearningC++","Oxford","CS22131029SS","Academic"),book("DeepWater","Cambridge","SS4301029GN","Literature")};
    
    int ch;
    do {
        cout<<"\nMenu:"<<endl;
        cout<<"1. Borrow a book"<<endl;
        cout<<"2. Return a book"<<endl;
        cout<<"3. Display loans"<<endl;
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
                    displayBooks(bookshelf,6);
                    int s;
                    cin>>s;
                    if(s>6 || s<1)
                        cout<<"\nInvalid # , please try again!"<<endl;
                    else
                    m.borrowBook(bookshelf[s-1]);
                }
                else if(u==2)
                {
                    cout<<"Which book "<<q.getName()<<" wants to borrow?"<<endl;
                    displayBooks(bookshelf,6);
                    int s;
                    cin>>s;
                    if(s>6 || s<1)
                        cout<<"\nInvalid # , please try again!"<<endl;
                    else
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
                trackLoans(patrons,2);
                break;
            }
            case 4: {
                displayBooks(bookshelf,6);
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