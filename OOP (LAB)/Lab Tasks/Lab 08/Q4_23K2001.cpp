//23K2001 Q4
#include<iostream>
using namespace std;
class person{
private:
int age;

protected:
string name;

public:
person(int age,string name) : age(age), name(name){}

int getAge() const
{
    return age;
}

string getName() const
{
    return name;
}

};

class employee{
private:
string empid;

protected:
float salary;

public:
employee(string empid,float salary):empid(empid),salary(salary){}

string getID() const
{
    return empid;
}

float getSalary() const
{
    return salary;
}

};

class manager : public person, public employee{
private:
string type;

public:
manager(int a,string n,string id,float s,string t):person(a,n),employee(id,s),type(t){}

string getType() const
{
    return type;
}

};

class ITmanager : public manager{
private:
int num;

public:
ITmanager(int a,string n,string id,float s,string t,int no) : manager(a,n,id,s,t),num(no){}

void display() const 
{
    cout<<"Name: "<<getName()<<endl;
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Emp-ID#: "<<getID()<<endl;
    cout<<"Type: "<<getType()<<endl;
    cout<<"Salary: "<<getSalary()<<endl;
    cout<<"No# of persons: "<<num<<endl;
}

};

int main()
{
    ITmanager Bashir(29,"Bashir Pasha","NU239081-KHI",57000.650,"Permanent",4);
    Bashir.display();
    return 0;
}