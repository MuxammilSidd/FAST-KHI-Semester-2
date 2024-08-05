#include <iostream>
using namespace std;
class Employee{
	public:
	
		Employee(){
		
			cout << "Employee Constructor";
		}
	
		~Employee(){
			cout << "Employee Destructor"; 
		} 
		public :
};
class Company{
	public:

	Employee *obj;
	public:
		//why i used as dynamic allocation because if company destroy then it should not destroy employee
	 	 Company(Employee *obj){
			this->obj = obj;
			cout <<"Company Constructor";
			
		}
		~Company(){
			cout<<"Company Destructor";
		}
	
};
int main(){
	Employee *eobj= new Employee();
	cout<<'\n';

		Company cobj(eobj);


	cout<<'\n';	

delete eobj;

}

