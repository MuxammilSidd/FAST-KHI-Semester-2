//23K2001 Muzammil
#include<iostream>
using namespace std;
typedef struct student_info{
    int id,s1,s2,s3;
    string name;
}student;

void input(student *a)
{
    cout<<"Input student id: ";
    cin>>a->id;
    cout<<"Input student name: ";
    cin>>a->name;
    cout<<"Input marks of 3-subjects: ";
    cin>>a->s1>>a->s2>>a->s3;
}
void calc_avg(student *a)
{
    float avg = (a->s1+a->s2+a->s3)/3;
    cout<<"Average marks of "<<a->name<<" is "<<avg;
}
void display(student *a)
{
    cout<<"\nStudent ID: ";
    cout<<a->id;
    cout<<"\nStudent Name: ";
    cout<<a->name;
    cout<<"\nMarks: "<<endl;
    cout<<"Subject-1: "<<a->s1<<"\tSubject-2: "<<a->s2<<"\tSubject-3: "<<a->s3<<endl;
}
int main()
{
    student st;
    int ch;
    do{
        cout<<"\n\n1. Display\n2. Input info\n3. Calculate average marks\n4. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:{
            display(&st);
            break;}

            case 2: 
            {
                input(&st);
                break;
            }
            case 3: 
            {
                calc_avg(&st);
                break;
            }

            case 4:
            return 0;
            
            default:
            cout<<"Invalid choice, enter again."<<endl;
        }
    }
    while(ch!=4);
    
    return 0;
}