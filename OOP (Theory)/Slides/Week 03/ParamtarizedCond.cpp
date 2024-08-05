#include <iostream>
using namespace std;
class Addition
{
	public:
	int a;
	int b;

	public:
	Addition(int a,int b){
		this->a=a;
		this->b=b;
		}
		void sum(){
			cout<<a+b;
		}
		
};
int main(){
      Addition  add1(2,3);
      Addition  add2(3,4);
      add1.sum();
      cout<<"\n";
      add2.sum();
      
	  }

