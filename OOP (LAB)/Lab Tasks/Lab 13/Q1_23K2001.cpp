//23k2001  Q1
#include<iostream>
using namespace std;
void throwException(){
    try{
        cout<<"Checking for errors.."<<endl;
        if(1)
        throw 2001;

        cout<<"Proceeded successfully"<<endl;
    }
    catch(int e){ cout<<"Error "<<e<<": Could not proceed!"<<endl; }
}
void funcC(){ 
    throwException();
    cout<<"Inside function C"<<endl; 
    }

void funcB(){
    funcC(); 
    cout<<"Inside function B"<<endl; 
    }
void funcA(){ 
    funcB();
    cout<<"Inside function A"<<endl; 
    }
int main()
{
	funcA();
	return 0;
}