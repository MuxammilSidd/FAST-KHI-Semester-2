//23k2001  Q1
#include<iostream>
using namespace std;
void throwException(){
        cout<<"Checking for errors.."<<endl;
        throw 2001;
}
void funcC(){ 
    try{ throwException(); }
    catch(int er){ cout<<"Error code: "<<er<<" - Inside function C"<<endl; }
    }

void funcB(){
    try{ funcC(); }
    catch(int er){ cout<<"Error code: "<<er<<" - Inside function B"<<endl; }
    }
void funcA(){ 
    try{ funcB(); }
    catch(int er){ cout<<"Error code: "<<er<<" - Inside function A"<<endl; }
    }
int main()
{
    cout<<"23K2001 - Muzammil\n"<<endl;
	funcA();
	return 0;
}