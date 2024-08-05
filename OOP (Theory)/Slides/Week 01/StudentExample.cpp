#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    int studentId;
    int studentAge;
    string studentName;
public:
   
    // Method to input student information
    void inputStudentInfo() {
        cout << "Enter Student Name: ";
       // cin >> studentName;
        getline(cin, studentName);
	    cout << "Enter Student ID: ";
        cin >> studentId;        
		cout << "Enter Student Age: ";
        cin >> studentAge;
        //cin >> studentName;
       // cin.ignore();  // Clear newline left in the buffer
       
    }

    // Method to print student information
  void printStudentInfo() {
        cout << "Student Information:";
        cout << "ID: " << studentId << "\n";
        cout << "Age: " << studentAge << "\n";
        cout << "Name: " << studentName << "\n";
        cout << endl;
    }

};

int main() {
    Student ali;
    
    Student john;
    // Input student information
    ali.inputStudentInfo();
	//student1.inputStudentInfo();
    // Print student information
    ali.printStudentInfo();
    
    
  	//cout << "Enter Second Student Information";
  	//john.inputStudentInfo();
  	//john.printStudentInfo();
    //student2.inputStudentInfo();
    //student2.printStudentInfo();

    return 0;
}

