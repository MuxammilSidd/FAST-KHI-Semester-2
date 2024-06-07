//23k2001 Q4
#include<iostream>
#include<cstring>
using namespace std;
class String{
protected:
char *text;
public:
String(){text=nullptr;}
void set(){
    string sINP;
    cout<<"Input your string: ";
    cin>>sINP;
    if(text==nullptr){
        text = new char[sINP.length()+1];
        strcpy(text,sINP.c_str());
    }
    else{
        char *temp = new char[strlen(text)+sINP.length()+2];
        strcpy(temp,text);

        temp[strlen(text)]=' ';

        strcpy(temp+strlen(text)+1,sINP.c_str());
        delete[] text;
        
        text=temp;
    }
}

void display(){
    cout<<endl;
    for(int i=0;i<strlen(text);i++)
    cout<<text[i];

    cout<<endl;
}
void operator =(const String c){
    text = new char[strlen(c.text)+1];
    strcpy(text,c.text);
}
~String(){delete[] text;}
};
int main()
{
    String mystring;
    mystring.set();
    mystring.display();
    mystring.set();
    mystring.display();
    mystring.set();
    mystring.display();
    mystring.set();
    mystring.display();

    String newString;
    newString.set();
    newString.display();

    mystring = newString;
    cout<<" Assigned to new string: "<<endl;
    mystring.display();
    return 0;
}