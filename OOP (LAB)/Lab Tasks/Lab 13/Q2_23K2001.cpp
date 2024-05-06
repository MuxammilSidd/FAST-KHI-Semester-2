//23k2001  Q2
#include<iostream>
using namespace std;
void parseData(string name){
    if(name==""){string error = "Name cannot be empty!";
    throw error;
    }
    else
    cout<<"Name: "<<name<<" sent to processing!"<<endl;

}
void processData(string name){
    try{
        parseData(name);
        cout<<"processing successful!"<<endl;
    }
    catch(string e){ 
        cout<<"Parsing error 101: "<<e<<endl;
        string error2 = "processing failed!";
        throw error2;
         }
}
int main()
{
	try{ processData(""); }
    catch(string e){ 
        cout<<e<<endl;
        cout<<"Please enter name correctly!"<<endl; }

    cout<<endl<<endl;
    
    try{ processData("Muzammil"); }
    catch(string e){ 
        cout<<e<<endl;
        cout<<"Please enter name correctly!"<<endl; }

	return 0;
}