#include<iostream>
using namespace std;
int main(){
  int a=7;
  int b=8;
  int* const p;
  cout<< *p;
  *p=*p+1;
  cout<<'\n';
  cout<<*p;
  //p=&b;


	return 0;
}
