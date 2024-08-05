#include <iostream>
using namespace std;
class A
{
public:
int var;
string str;

public:
A(int v){
	 	var = v;
		cout << "Constructor v1: " << var << endl;
	}
A(string v){
	 	str = v;
		cout << "Constructor v1: " << var << endl;
	}
	A(){
		var = 0;
		cout << "Default constructor: " << var << endl;
	}
};
int main(){
	A dOb;
	A iOb(50);
	A sOb("Hello");
}

