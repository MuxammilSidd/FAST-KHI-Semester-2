//23K2001 Muzammil
#include<iostream>
using namespace std;

class student{
    private:
    int st_id, s_age;
    string st_name;
    char grade;

    public:
    void setID(int id)
    {
        st_id = id;
    }
    void setAge(int age)
    {
        s_age = age;
    }
    void setName(string name)
    {
        st_name = name;
    }
    void setGrade(char g)
    {
        grade = g;
    }
    int getID()
    {
        return st_id;
    }
    int getAge()
    {
        return s_age;
    }
    string getName()
    {
        return st_name;
    }
    char getGrade()
    {
        return grade;
    }

    void displaySt_info()
    {
        cout<<"Info of student '"<<st_name<<"' :"<<endl;
        cout<<"Student ID: "<<st_id<<endl;
        cout<<"Student Age: "<<s_age<<endl;
        cout<<"Grade: "<<grade<<endl;
    }
};
class teacher{
    private:
    int t_id;
    string t_name, subject;

    public:
    void setID(int id)
    {
        t_id = id;
    }
    void setName(string name)
    {
        t_name = name;
    }
    void setSubj(string s_name)
    {
        subject = s_name;
    }
    int getID()
    {
        return t_id;
    }
    string getName()
    {
        return t_name;
    }
    string getSubj()
    {
        return subject;
    }

    void displayT_info()
    {
        cout<<"Info of teacher '"<<t_name<<"' :"<<endl;
        cout<<"Teacher ID: "<<t_id<<endl;
        cout<<"Subject Taught: "<<subject<<endl;
    }

};
class course{
    private:
    string code,name;
    teacher t;

    public:
    void setCode(string courseCode)
    {
        code = courseCode;
    }
    void setName(string courseName)
    {
        name = courseName;
    }
    string getName()
    {
        return name;
    }
    string getCode()
    {
        return code;
    }

    void displayCourseInfo()
    {
        cout<<"Info of course '"<<name<<"' :"<<endl;
        cout<<"Course Code: "<<code<<endl;

    }
};

class schoolManagement{
    public:
    void addStudent(student *&s, int &n)
    {
        n++;
        student *s_temp = new student[n];
        int i;
        for(i=0;i<n-1;i++)
        {
            s_temp[i] = s[i];
        }
        delete[] s;
        s = s_temp;
        int id,age;
        string name;
        char grade;
        cout<<"Input ID: ";
        cin>>id;
        cout<<"Input Name: ";
        cin>>name;
        cout<<"Input Age: ";
        cin>>age;
        cout<<"Input Grade: ";
        cin>>grade;
        s[n-1].setID(id);
        s[n-1].setName(name);
        s[n-1].setAge(age);
        s[n-1].setGrade(grade);
        cout<<"..new student added successful\n"<<endl;
    }
    void addTeacher(teacher *&t, int &n)
    {
        n++;
        teacher *t_temp = new teacher[n];
        int i;
        for(i=0;i<n-1;i++)
        {
            t_temp[i] = t[i];
        }
        delete[] t;
        t = t_temp;
        int id;
        string name, subj;
        cout<<"Input teacher ID: ";
        cin>>id;
        cout<<"Input Name: ";
        cin>>name;
        cout<<"Input Subject: ";
        cin>>subj;
        t[n-1].setID(id);
        t[n-1].setName(name);
        t[n-1].setSubj(subj);
        cout<<"..new teacher added successful\n"<<endl;
    }
    void addCourse(course *&c,int &n)
    {
        n++;
        course *c_temp = new course[n];
        int i;
        for(i=0;i<n-1;i++)
        {
            c_temp[i] = c[i];
        }
        delete[] c;
        c = c_temp;
        string codecourse, namecourse;
        cout<<"Input Course code: ";
        cin>>codecourse;
        cout<<"Input Course name: ";
        cin>>namecourse;
        c[n-1].setCode(codecourse);
        c[n-1].setName(namecourse);
        cout<<"..new course added successful\n"<<endl;

    }
    void displayAllStudents(student *s, int &n)
    {
        int i;
        cout<<"...DISPLAYING ALL STUDENTS STUDYING IN OUR SCHOOL...\n"<<endl;

        for(i=0;i<n;i++)
        {
            s[i].displaySt_info();
            cout<<"\n";
        }
    }
    void displayAllTeachers(teacher *t, int &n)
    {
        int j;
        cout<<"...DISPLAYING ALL TEACHERS TEACHING IN OUR SCHOOL...\n"<<endl;

        for(j=0;j<n;j++)
        {
            t[j].displayT_info();
            cout<<"\n";
        } 
    }
    void displayAllCourses(course *c,int &n)
    {
        int k;
        cout<<"...DISPLAYING ALL COURSES TAUGHT IN OUR SCHOOL...\n"<<endl;

        for(k=0;k<n;k++)
        {
            c[k].displayCourseInfo();
            cout<<"\n";
        }
    }
};

int main()
{
    int ch;
    int sts=1, ts=1,cs=1;
    schoolManagement delson;
    student *s = new student[sts];
    teacher *t = new teacher[ts];
    course *c = new course[cs];
    cout<<"\nPlease input data for 1 student!"<<endl;
    int id,age;
    string name, subj, codecourse, namecourse;
    char grade;
    cout<<"Input ID: ";
    cin>>id;
    cout<<"Input Name: ";
    cin>>name;
    cout<<"Input Age: ";
    cin>>age;
    cout<<"Input Grade: ";
    cin>>grade;
    s[0].setID(id);
    s[0].setName(name);
    s[0].setAge(age);
    s[0].setGrade(grade);

    cout<<"\nPlease input data for 1 teacher!"<<endl;
    cout<<"Input ID: ";
    cin>>id;
    cout<<"Input Name: ";
    cin>>name;
    cout<<"Input Subject: ";
    cin>>subj;
    t[0].setID(id);
    t[0].setName(name);
    t[0].setSubj(subj);

    cout<<"\nPlease input data for 1 course!"<<endl;
    cout<<"Input Course code: ";
    cin>>codecourse;
    cout<<"Input Course name: ";
    cin>>namecourse;
    c[0].setCode(codecourse);
    c[0].setName(namecourse);

    cout<<"\n\n***WELCOME TO DELSON SCHOOL"<<endl;
    do{
        cout<<"\n1. Add a student\n2. Add a teacher\n3. Add a course"<<endl;
        cout<<"4. Display all students\n5. Display all teachers\n6. Display all courses"<<endl;
        cout<<"Press '0' to Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                delson.addStudent(s,sts);
                break;
            }
            case 2:
            {
                delson.addTeacher(t,ts);
                break;
            }
            case 3:
            {
                delson.addCourse(c,cs);
                break;
            }
            case 4:
            {
                delson.displayAllStudents(s,sts);
                break;
            }
            case 5:
            {
                delson.displayAllTeachers(t,ts);
                break;
            }
            case 6:
            {
                delson.displayAllCourses(c,cs);
                break;
            }
            case 0:
            {
                return 0;
            }
            default:
            cout<<"Invalid input, try again!"<<endl;
        }
    } while(ch!=0);

    delete[] s;
    delete[] t;
    delete[] c;
    return 0;
}