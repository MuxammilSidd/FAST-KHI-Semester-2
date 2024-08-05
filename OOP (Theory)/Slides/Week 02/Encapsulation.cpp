#include <iostream>
#include <string>
using namespace std;


class Student {
	
private:
    int studentId;
    int studentAge;
    string studentName;
public:
	void setStudentId(int idd){
		studentId=idd;
	}
	void setStudentAge(int a){
		studentAge=a;
	}
	void setStudentName(string n){
		studentName=n;
	}
	string getStudentName(){
		return studentName;
	}	
	int getStudentAge(){
		return studentAge;
	}
	int getStudentId(){
		return studentId;
	}
double reduceAge(double per){
	double red=studentAge*per;
	studentAge=studentAge-red;
	return studentAge;
}
};

int main() {
    Student student1;
    Student student2;
    cout <<"Enter age of student";
    int a;
    cin>>a;
	student1.setStudentAge(a);
  	cout << "Student Information";
  	cout<<endl;
    student1.setStudentId(101);
    student1.setStudentName("Ali");
    cout<< student1.getStudentName();
    cout<<endl;
    cout<< student1.getStudentId();
  	cout<<endl;
    cout << student1.getStudentAge();
	student1.reduceAge(0.1);
    cout<<endl;
    cout << student1.getStudentAge();
	student2.setStudentAge(15);
  	cout << "Student Information";
  	cout<<endl;
    student2.setStudentId(102);
    student2.setStudentName("Ahmed");
    cout<< student2.getStudentName();
    cout<<endl;
    cout<< student2.getStudentId();
    cout<<endl;
    cout << student2.getStudentAge();    

    return 0;
}

