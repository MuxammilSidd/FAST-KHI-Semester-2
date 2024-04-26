//23k2001 Q4
#include<iostream>
#include<cstring>
using namespace std;
class String{
protected:
char *text;
public:
String(){text=nullptr;}
void set(char *inp){
    text = new char[strlen(inp)+1];
    strcpy(text,inp);    
}
void display(){
    cout<<endl;
    cout<<text;
}
void operator =(const String &c){
    text = new char[strlen(c.text)+1];
    strcpy(text,c.text);
}
~String(){delete[] text;}
};
int main()
{
    String mystring;
    char c1[]="My name is Muzammil";
    mystring.set(c1);
    mystring.display();
    String newString;
    char c2[]="Rollnumber is 23K2001";
    newString.set(c2);
    newString.display();

    mystring = newString;
    cout<<"\n\tAssigned to new string: "<<endl;
    cout<<"String1: ";
    mystring.display();
    cout<<"\nString2: ";
    newString.display();
    return 0;
}