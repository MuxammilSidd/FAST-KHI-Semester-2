#include <iostream>
using namespace std;
class Engine{
	public:
	
		Engine(){
		
			cout << "Engine Constructor";
		}
	
		~Engine(){
			cout << "Engine Destructor"; 
		}
		public :
};
class Car{
	public:

	Engine obj;
	public:
		//why i used as dynamic allocation because if company destroy then it should not destroy employee
	 	 Car(){
				cout<<'\n';
			cout <<"Car Constructor";
			
		}
		~Car(){
				cout<<'\n';
			cout<<"Car Destructor";
		}
	
};
int main(){
	Car cobj;
	cout<<'\n';




}

