#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    int eid;
    float salary;
    string dept;

    Employee() {
        eid = 0;
        salary = 0.0f;
        dept = "No Department";
    }

    Employee(int id, float s, string d) {
        eid = id;
        salary = s;
        dept = d;
    }

    void getEmpData() {
        cout << "Enter Employee ID: ";
        cin >> eid;
        cout << "Enter Employee Salary: ";
        cin >> salary;
        cout << "Enter Employee Department: ";
        cin.ignore();  // Clear the newline left in the buffer
        getline(cin, dept);
    }

    void showEmpData() {
        cout << "Employee ID: " << eid 
             << ", Salary: " << salary 
             << ", Department: " << dept 
             << endl;
    }

    void storeEmployee() {
        ofstream f("employees.csv", ios::app);
        if (!f) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        f << eid << "," << salary << "," << dept << endl;
        f.close();
    }

    static void viewEmployeeRecords() {
        ifstream f("employees.csv");
        if (!f) {
            cerr << "File not found!" << endl;
            return;
        }

        string line;
        while (getline(f, line)) {
            stringstream ss(line);
            int id;
            float salary;
            string dept;

            ss >> id;
            ss.ignore(1, ',');  // Ignore comma
            ss >> salary;
            ss.ignore(1, ',');  // Ignore comma
            getline(ss, dept);

            cout << "Employee ID: " << id 
                 << ", Salary: " << salary 
                 << ", Department: " << dept 
                 << endl;
        }

        f.close();
    }

    static void searchEmployeeById(int id) {
        ifstream f("employees.csv");
        if (!f) {
            cerr << "File not found!" << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(f, line)) {
            stringstream ss(line);
            int eid;
            float salary;
            string dept;

            ss >> eid;
            ss.ignore(1, ',');  // Ignore comma
            ss >> salary;
            ss.ignore(1, ',');  // Ignore comma
            getline(ss, dept);

            if (eid == id) {
                cout << "Employee found!" << endl;
                cout << "Employee ID: " << eid 
                     << ", Salary: " << salary 
                     << ", Department: " << dept 
                     << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Employee with ID " << id << " not found." << endl;
        }

        f.close();
    }
};

int main() {
    Employee e1;
    e1.getEmpData();
    e1.showEmpData();
    e1.storeEmployee();

    Employee::viewEmployeeRecords();

    int searchId = 2;  // Example ID to search for
    Employee::searchEmployeeById(searchId);

    return 0;
}
