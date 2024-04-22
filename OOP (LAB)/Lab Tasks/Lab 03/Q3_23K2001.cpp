//23K2001 Muzammil
#include<iostream>
using namespace std;

class Employee{
    private:
    string fname, lname;
    int salary;

    public:
    void setfname(string name)
    {
        fname = name;
    }
    void setlname(string name)
    {
        lname = name;
    }
    void setsalary(int monthly)
    {
        if(monthly<0)
        salary = 0;

        else
        salary = monthly;
    }
    string getfname()
    {
        return fname;
    }
    string getlname()
    {
        return lname;
    }
    int getsalary()
    {
        return salary;
    }

};

int main()
{
    Employee worker;
    Employee assistant;
    cout<<"..Initiliazing data for Employee: Worker"<<endl;
    worker.setfname("Arshad");
    worker.setlname("Nadeem");
    worker.setsalary(45000);
    cout<<"..Initiliazing data for Employee: Assistant"<<endl;
    assistant.setfname("Mubeen");
    assistant.setlname("Kazmi");
    assistant.setsalary(25000);

    cout<<"Worker '"<<worker.getfname()<<" "<<worker.getlname()<<"' Yearly salary: "<<worker.getsalary()*12<<endl;
    cout<<"Assistant '"<<assistant.getfname()<<" "<<assistant.getlname()<<"' Yearly salary: "<<assistant.getsalary()*12<<endl;

    cout<<"..assigning 10% raise to both employee"<<endl;
    worker.setsalary(worker.getsalary()*1.10);
    assistant.setsalary(assistant.getsalary()*1.10);
    cout<<"..salaries raised!"<<endl;

    cout<<"New salaries: "<<endl;
    cout<<"Worker '"<<worker.getfname()<<" "<<worker.getlname()<<"' Yearly salary: "<<worker.getsalary()*12<<endl;
    cout<<"Assistant '"<<assistant.getfname()<<" "<<assistant.getlname()<<"' Yearly salary: "<<assistant.getsalary()*12<<endl;
    return 0;
}