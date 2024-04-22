#include<iostream>
using namespace std;
class student{
    private:
    int age;
    string name;

    public:
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
    string getName()
    {
        return name;
    }
    student(const student &s)
    {
        name = s.name;
        age = s.age;
        cout<<"copied"<<endl;
    }
    student()
    {

    }
};
int main()
{
    student s1;
    s1.setName("Muzammil");
    s1.setAge(18);
    student s2 = s1;
    // student s2;
    // s2 = s1;
    cout<<s2.getName()<<endl;
    cout<<"done";
    return 0;
}