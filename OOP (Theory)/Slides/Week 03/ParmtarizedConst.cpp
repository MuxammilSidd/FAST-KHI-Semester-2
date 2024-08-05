#include <iostream>
using namespace std;
class Employee
{
	public:
	string name;

	public:
	Employee(string eName){
		name = eName;
		}
		
};
int main(){
      Employee  e1("Ali");
      cout<<e1.name;
	  Employee  e2("Shuja");
	  cout<<"\n";
	  cout<<e2.name;
	  }

