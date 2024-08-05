#include <iostream>
using namespace std;
class Birthday{
	public:
		int day;
		int month;
		int year;
		public:
		Birthday(){
			day=0;
			month=0;
			year=0;
			cout<<"Birthday Constructor Calling";
		}
	
		~Birthday(){
			cout<<"Birthday Destructor Calling";
		}
		public :
	void setBirthday(int d,int m,int y){
			day=d;
			month=m;
			year=y;
		}
		void PrintDate(){
			//cout<< day << "/" << month << "/ " << year ; 
				cout << day << "/" << month <<"/" << year;
		}
};
class People{
	public:
	string name;
	Birthday obj;
	public:
	 	void setPeople(string n,int d,int m,int y){
			name=n;
		//	obj.
		obj.setBirthday(d,m,y);
		
		}
		People(){
			cout<<"People Constructor Calling";
		}
		~	People(){
			cout<<"People Destructor Calling";
		}
		void PrintDetails(){
		cout << "Name is " << name;
		cout << "Birthday is ";
		 //obj.PrintDate();
		 cout<<"Day : "<< obj.day;
		 cout<<"Month"<< obj.month;
		 cout<<"Year"<< obj.year;

		}
};
int main(){
	People p;
	cout<<'\n';
	p.setPeople("Ahmed",1,3,2001);
	p.PrintDetails();
	{
	cout<<"Second object Creation";
	cout<<'\n';
	People ahmed;
	cout<<'\n';
	ahmed.obj.setBirthday(12,4,2002);
	}	
	cout<<'\n';
	//obj.PrintDetails();
}

