#include<iostream>
using namespace std;
class studentres{
    private:
        string name;
        int rollno;
        float gpa;
    
    public:
        studentres(string name,int rollno, float gpa)
        {
            this->name = name;
            this->rollno = rollno;
            this->gpa = gpa;
        }
        void display()
        {
            cout<<"Name: "<<name;
            cout<<"\nRollno: "<<rollno;
            cout<<"\nGPA: "<<gpa;
        }
};
int main()
{
    studentres me("Muzammil",232001,3.75);
    
    me.display();
    return 0;
}