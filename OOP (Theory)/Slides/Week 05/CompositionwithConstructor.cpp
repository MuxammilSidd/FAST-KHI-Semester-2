#include <iostream>
using namespace std;
class Birthday{
	public:
		int day;
		int month;
		int year;
		Birthday(){
			day=0;
			month=0;
			year=0;
			cout << "Birthday Constructor";
		}
		Birthday(int d ,int m,int y){
			day=d;
			month=m;
			year=y;
			cout << " Paramterized Birthday Constructor";
		}
		~Birthday(){
			cout << "Birthday Destructor"; 
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
	 	 People(string n,int d,int m,int y):obj(d,m,y){
			name=n;
		//	obj.setBirthday(d,m,y);
			cout <<"People Constructor";
			
		}
		~People(){
			cout<<"People Destructor";
		}
		void PrintDetails(){
			cout << "Name is " << name;
			cout << "Birthday is ";
		 	obj.PrintDate();
		 	

		}
};
int main(){
	
			People p("Ahmed",1,3,2001);
			cout<<"\n";
			p.PrintDetails();
		
	

//	obj.PrintDate();

}

