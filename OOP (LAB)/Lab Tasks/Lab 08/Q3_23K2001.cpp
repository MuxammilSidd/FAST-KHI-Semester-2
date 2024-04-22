//23K2001 Q3
#include<iostream>
using namespace std;
class employee{
	protected:
		string name,id;
		float salary;
		int age;
		
	public:
		employee(string n,string d,float sal,int a) : name(n),id(d),salary(sal),age(a){}
		
		void display()
		{
			cout<<"Name: "<<getName()<<endl;
			cout<<"Age: "<<getAge()<<endl;
			cout<<"Salary: "<<getSalr()<<endl;
			cout<<"EmpID: "<<getID()<<endl;
		}
		
		void setName(string n)
		{
			name = n;
		}
		void setSalr(float n)
		{
			salary = n;
		}
		void setAge(int n)
		{
			age = n;
		}
		void setID(string id)
		{
			this->id = id;
		}
		string getName()
		{
			return name;
		}
		float getSalr()
		{
			return salary;
		}
		int getAge()
		{
			return age;
		}
		string getID()
		{
			return id;
		}
};

class faculty : public employee{
	private:
		string department,subjects;
	public:
		faculty(string n, string id, float sal,int age, string d,string subs) : employee(n,id,sal,age), department(d),subjects(subs){
		}
		
		void setD(string d)
		{
			department = d;
		}
		void setSub(string sub)
		{
			subjects = sub;
		}
		string getD()
		{
			return department;
		}
		string getSub()
		{
			return subjects;
		}
		void display()
		{
			employee::display();
			cout<<"Department: "<<getD()<<endl;
			cout<<"Teaching subjects: "<<getSub()<<"\n"<<endl;
		}
};
class admin : public employee{
	private:
		string pos,location;
	public:
		admin(string name, string id, float sal,int age, string p,string l) : employee(name,id,sal,age), pos(p),location(l){
		}
		
		void setPos(string p)
		{
			pos = p;
		}
		void setLoc(string l)
		{
			location = l;
		}
		string getPos()
		{
			return pos;
		}
		string getLoc()
		{
			return location;
		}
		void display()
		{
			employee::display();
			cout<<"Position: "<<getPos()<<endl;
			cout<<"Office location: "<<getLoc()<<"\n"<<endl;
		}
};

class teachingAssistant : public faculty, public admin{
	public:
		teachingAssistant(string na,string ide,float sal,int age,string d,string subs,string pos,string loc): faculty(na,ide,sal,age,d,subs),admin(na,ide,sal,age,pos,loc)
		{}
		void display()
		{
			faculty::display();
			admin::display();
		}
};
int main()
{
	faculty cs("Sir Asif","CS-119245",120000,36,"CS","OOP, PF");
	admin a("Dr. Fazal Hassan","AA-56721",200000,45,"HOD","CS Ground Floor Offices");
	teachingAssistant muz("Muzammil Siddiqui","23K-2001",15000,18,"BSCS","Programming Fundamentals","Teaching-Assistant","EE 3rd Floor");
	
	cs.display();
	a.display();
	muz.display();
	return 0;
}
