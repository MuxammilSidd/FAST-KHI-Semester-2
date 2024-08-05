#include <iostream>
#include <string>
using namespace std;
class A{
	public:
	int a;
	int b;
	int c;
public:
	A(int i=10,int j=20,int k=30){
		a = i;
		b=j;
		c=k;
	}
	void assign(int i){
		a = i;
	}
	int return_value(){
		return a;
	}
};
int main()
{
	A obj;
	cout<< obj.a <<obj.b<< obj.c<<endl;
	cout<<'\n';
	A obj1(45);
	cout<< obj1.a <<obj1.b<< obj1.c<<endl;
	A obj3(5,20);
cout<< obj3.a << obj3.b<< obj3.c<<endl;
	A obj4(5,20,60);
cout<< obj4.a << obj4.b<< obj4.c;
}

