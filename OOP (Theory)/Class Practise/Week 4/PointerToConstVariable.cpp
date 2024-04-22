#include<iostream>
using namespace std;
int main(){
 const int a=7;
  int b=8;
  const int* p;   //const before * -> Cannot change value but can change address
  p=&a;
  cout<< *p;
  //*p=*p+1;
  cout<<'\n';
  cout<<*p;
  p=&b;
  cout<<'\n';
  cout<<*p;

	return 0;
}
