#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;
class Employee{
	public:
	int eid;
	float salary;
	string dept;
	Employee(){
	eid=0;
	salary=0.0;
	dept="No Department";
	
	}
	Employee(int id,float s,string d){
	eid=id;
	salary=s;
	dept=d;
	}
	public:
	void getEmpData(){
		cout<<"Employee id";
		cin>>eid;
		cout<<"Employee salary";
		cin>>salary;
		cout<<"Employee department";
		cin>>dept;
	}
	
	void showEmpData(){
		cout<<"\n"<<"Employee id is " << eid <<"Employee salary is" << salary << "Department " << dept;
	}
	int storeEmpl();
	void viewEmployeeRec();
	void SearchEmpData(int id);
	
};
Employee::storeEmpl(){
	ofstream f;
	if(eid==0 && salary==0.0){
	cout<<"Data not Initialized";
	return(0);	
	}
	
	else {
	f.open("File1.dat",ios::app);
	f.write((char*)this,sizeof(*this));	
	f.close();
	return(1);
	}
	
}
void Employee::viewEmployeeRec(){
	ifstream fin;
	fin.open("File1.dat",ios::in|ios::binary);
	if(!fin)
	cout<<"Data not Found";
	else{
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof()){
		showEmpData();
		fin.read((char*)this,sizeof(*this));
	
	}
	fin.close();
	}
	}
void Employee::SearchEmpData(int id){
	ifstream fin;
	fin.open("File1.dat",ios::in);
	if(!fin)
	cout<<"Data not Found";
	
	else{
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof()){
		if(eid==id){
				cout<<"Data found";
				showEmpData();
				
		}
		
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	}
}
int main(){
Employee e1;
e1.getEmpData();
//e1.showEmpData();
e1.storeEmpl();
e1.viewEmployeeRec();
//e1.SearchEmpData(2);
}
