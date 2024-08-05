#include <iostream>  
using namespace std;  
class Address {  
    public:  
   string addressLine, city, state;    
     Address(string addressLine, string city, string state)    
    {    
        this->addressLine = addressLine;    
        this->city = city;    
        this->state = state;    
    }   
		 Address(){
				cout<<'\n';
			cout <<"Address Constructor";
			
		}
		~Address(){
				cout<<'\n';
			cout<<"Address Destructor";
		}
	 
}; 
class Employee    
    {    
        private:  
        Address* address;  //Employee HAS-A Address   
        public:  
        int id;    
        string name;    
        Employee(int id, string name, Address* address)    
       {    
           this->id = id;    
           this->name = name;    
           this->address = address;    
       }    
     void display()    
       {    
           cout<<id <<" "<<name<< " "<<     
             address->addressLine<< " "<< address->city<< " "<<address->state<<endl;    
       }  
	  
		~Employee(){
				cout<<'\n';
			cout<<"Employee Destructor";
		}  
   }; 
int main(){
//	Adress a1("C-146, Sec-15","Noida","UP");
//	Address a1= Address("C-146, Sec-15","Noida","UP");
	Employee e1(101,"Alii",&a1);    
    e1.display();   
return 0;
 }
