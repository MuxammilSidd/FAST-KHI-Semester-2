#include <iostream>
#include <string>
using namespace std;


class Student {
public:
    int studentId;
    int studentAge;
    string studentName;
    
    Student(){
    	cout << "Constructor Calling";
	}

public:
    // Method to input student information
    void inputStudentInfo() {
        cout << "Enter Student ID: ";
        cin >> studentId;
        
		cout << "Enter Student Age: ";
        cin >> studentAge;
        
        cin.ignore();  // Clear newline left in the buffer
        
        cout << "Enter Student Name: ";
        getline(cin, studentName);
    }

    // Method to print student information
    void printStudentInfo() {
        cout << "Student Information:\n";
        cout << "ID: " << studentId << "\n";
        cout << "Age: " << studentAge << "\n";
        cout << "Name: " << studentName << "\n";
    }
};

int main() {
    Student student1;
    Student student2;

    // Input student information
    student1.inputStudentInfo();

    // Print student information
    student1.printStudentInfo();
    
    
  	cout << "Enter Second Student Information";
    student2.inputStudentInfo();
    student2.printStudentInfo();

    return 0;
}

