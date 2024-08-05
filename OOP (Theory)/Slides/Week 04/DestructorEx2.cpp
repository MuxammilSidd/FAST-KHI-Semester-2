#include <iostream>
using namespace std;
class MyClass
{
 int objectID;
   MyClass(int objectID)
     { this.objectID = objectID;
	  }~MyClass() {
	  	cout << objectID << "deleted";
		   }
};
int main()
{
     MyClass obj(101); //constructor is called
     MyClass obj2(102); //constructor is called
 
     /*....object obj goes out of scope ,now destructor is being called...*/
     
     return 0;
}  //end of program
