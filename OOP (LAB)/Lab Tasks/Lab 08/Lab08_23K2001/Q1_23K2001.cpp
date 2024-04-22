//23K2001 Q1
#include<iostream>
using namespace std;

class employee{
	protected:
		string name;
		int num;
		int age;
		
	public:
		employee(string n,int no,int a) : name(n),num(no),age(a){}
		
		void display()
		{
			cout<<"Name: "<<getName()<<endl;
			cout<<"Phone#"<<getNum()<<endl;
			cout<<"Age: "<<getAge()<<endl;
		}
		
		void setName(string n)
		{
			name = n;
		}
		void setNum(int n)
		{
			num = n;
		}
		void setAge(int n)
		{
			age = n;
		}
		string getName()
		{
			return name;
		}
		int getNum()
		{
			return num;
		}
		int getAge()
		{
			return age;
		}
};
class manager : public employee{
	protected:
		string title;
		float due;
	public:
		manager(string n,int no,int a,string t,float due) : employee(n,no,a), title(t),due(due){
		}
		void display()
		{
			employee::display();
			cout<<"Title: "<<getTitle()<<endl;
			cout<<"Dues: "<<getDue()<<"\n"<<endl;
		}
		void setTitle(string n)
		{
			title = n;
		}
		void setDue(float n)
		{
			due = n;
		}
		string getTitle()
		{
			return title;
		}
		float getDue()
		{
			return due;
		}
};
class scientist : public employee{
	protected:
		string title,publication;
	public:
		scientist(string n,int no,int a,string t,string p) : employee(n,no,a), title(t),publication(p){
		}
		void display()
		{
			employee::display();
			cout<<"Title: "<<getTitle()<<endl;
			cout<<"Publication: "<<getPub()<<"\n"<<endl;
		}
		void setTitle(string n)
		{
			title = n;
		}
		void setPub(string n)
		{
			publication = n;
		}
		string getTitle()
		{
			return title;
		}
		string getPub()
		{
			return publication;
		}

};
class laborer : public employee{
	protected:
		string title;
	public:
		laborer(string n,int no,int a,string t) : employee(n,no,a), title(t){
		}
		void display()
		{
			employee::display();
			cout<<"Title: "<<getTitle()<<endl;
		}
		void setTitle(string n)
		{
			title = n;
		}
		string getTitle()
		{
			return title;
		}
};
int main()
{
	manager muz("Muzammil Siddiqui",92306223,18,"Production Manager",56000.754);
	scientist hathi("Dr. Hathi Raja",97445621,44,"Lead Scientist","Atomic Model");
	laborer taha("M. Taha",92300561,19,"Lab Instructor");
	
	muz.display();
	hathi.display();
	taha.display();
	return 0;
}
