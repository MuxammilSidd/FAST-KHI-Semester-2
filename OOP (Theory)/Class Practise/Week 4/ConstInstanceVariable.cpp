#include<iostream>
using namespace std;
class Test
{
	public :
    const int i;
    const int j;
    public:
    Test(int x ,int y):i(x),j(y){}
  //   {
	// i=x;
	// j=y;
        	
  //       cout << "\ni value set: " << i << j;
  //   }
    void display(){
    	cout<<i<<endl;
    	cout<<j;
	}
};

int main()
{
    Test t(2,5);
  //  t.i=500;
    t.display();
  //  Test s(20);
}
