#include<iostream>
using namespace std;
class Test
{
	public:
	int i;
	public:
      void display(const int a){
    	i=a;
		i++;
		//a++;	
	}
};

int main()
{
    Test t;
    t.display(6);
    cout <<t.i;
    return 0;
}
