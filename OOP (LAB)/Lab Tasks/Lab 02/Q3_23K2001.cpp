//23K2001 Muzammil
#include<iostream>
using namespace std;


typedef struct libraryBooks{
    int ac_no;
    string author;
    string title;
    int flag;
} book;

int main()
{
    int n=2,i;
    int ch;
    book *b = new book[n]; 
    cout<<"Please Feed atleast 2 books info:\n"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Book#"<<i+1<<endl;
		cout<<"Enter accession number: ";
		cin>>b[i].ac_no;
		cout<<"Enter book title: ";
		cin>>b[i].title;
		cout<<"Enter author name: ";
		cin>>b[i].author;
		cout<<"Enter status (1=Issued\t0=Available): ";
		cin>>b[i].flag;
	}
    cout<<"\t\t*****WELCOME TO JINNAH LIBRARY*****\n"<<endl;
    do{
        cout<<"\n1. Display book info..\n2. Add book..\n3. Display all books of an author.."<<endl;
        cout<<"4. Number of book of a title..\n5. Total no. of books..\n6. Issue book..\n0. Exit."<<endl;
        cin>>ch;
        switch(ch)
        {
            case 0:
            return 0;
            
            case 1:{
                int a=0,i;
                string bookname;
                cout<<"Enter book name: ";
                cin>>bookname;
                cout<<"\nInfo:\n";
                for(i=0;i<n;i++)
                {
                    if((b[i].title==bookname))
                    {
                        a++;
                    }
                }
                cout<<a<<" matches found!\n\n";
                for(i=0;i<n;i++)
                {
                    if((b[i].title==bookname))
                    {
                        cout<<"Title: "<<b[i].title<<endl;;
                        cout<<"Author: "<<b[i].author<<endl;
                        cout<<"Accession number: "<<b[i].ac_no<<endl;
                        if(b[i].flag==1)
                        cout<<"Status: Issued\n"<<endl;
                        else
                        cout<<"Status: Available\n"<<endl;
                    }
                }
                break;
            }

            case 2:{
                n++;
                book *temp = new book[n];
                for (i=0; i<n - 1;i++) {
                    temp[i] = b[i];
                }
                delete[] b;
                b = temp;
                cout<<"\nBook#"<<n<<endl;
                cout<<"Enter accession number: ";
                cin>>b[n-1].ac_no;
                cout<<"Enter book title: ";
                cin>>b[n-1].title;
                cout<<"Enter author name: ";
                cin>>b[n-1].author;
                cout<<"Enter status (1=Issued\t0=Available): ";
                cin>>b[n-1].flag;
                cout<<"*BOOK ADDED SUCCESSFULLY*"<<endl;
                break;
            }
            case 3:{
                int a=0;
                string authorname;
                cout<<"Enter author name: ";
                cin>>authorname;
                cout<<"\nBooks by "<<authorname<<endl;
                for(i=0;i<n;i++)
                {
                    if((authorname==b[i].author))
                    {
                        a++;
                        cout<<a<<". ";
                        cout<<b[i].title<<endl;
                    }
                }
                if(a==0)
                cout<<"(None)"<<endl;
                break;
            }

            case 4:{
                int a=0;
                string bookname;
                cout<<"Enter book name: ";
                cin>>bookname;
                for(i=0;i<n;i++)
                {
                    if((bookname==b[i].title))
                    a++;
                }
                cout<<"Total books with title '"<<bookname<<"' are "<<a<<endl;
                break;
            }
            case 5:{
                int total=n;
                cout<<"Total number of books in Jinnah Library: "<<n<<endl;
                break;
            }
            case 6:{
                int a=0;
                string bookname;
                cout<<"Enter book name: ";
                cin>>bookname;
                for(i=0;i<n;i++)
                {
                    if((bookname==b[i].title)==1 && b[i].flag==0)
                    {
                        a++;	
                        b[i].flag=1;
                    }
                }
                if(a>0)
                {
                    cout<<"\nAvailable: "<<a;
                    cout<<"\n*ISSUED*"<<endl;
                    n--;
                    cout<<"\n\nRemaining books in Library: "<<n<<endl;
                }
                else
                cout<<"\n*No books available. PLEASE SELECT ANOTHER*"<<endl;
                break;
            }
            default:
            cout<<"Invalid choice!"<<endl;
        }

    }   while(ch!=0);
    delete[] b;
    return 0;
}