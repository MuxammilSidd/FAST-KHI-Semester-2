#include <iostream>
#include <string>
using namespace std;
class A{
	int a;
public:
	A(int i=100){
		a = i;
	}
	void assign(int i){
		a = i;
	}
	int value(){
		return a;
	}
};
int main()
{
	A obj;
	A obj2(30);
	cout<<obj.value();
	cout<<'\n';
    cout<<obj2.value();
	obj.assign(5);
	cout<<obj.value();
}

