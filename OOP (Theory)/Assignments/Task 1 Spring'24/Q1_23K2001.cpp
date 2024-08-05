//23K2001 Muzammil
#include<iostream>
using namespace std;

class CompanyWorker{
    private:
    int salary,hours;

    public:
    void infoRetrieval(int salary,int hours)
    {
        this->salary = salary;
        this->hours = hours;
    }
    void salIncrease()
    {
        if(salary<25000)
        {
            salary+=5000;
            cout<<"Congratulations! Your salary got increased."<<endl;
        }
        else
        cout<<"Sorry, no salary increase for you!"<<endl;
    }
    void workBenefit()
    {
        if(hours>7)
        {
            salary+=6000;
            cout<<"Congratulations! You got work benefit."<<endl;
            cout<<"Your final salary now: "<<salary<<endl;

        }
        else{
        cout<<"Sorry, no work benefit for you!"<<endl;
        cout<<"Your final salary now: "<<salary<<endl;
        }    

    }

};
int main()
{
    CompanyWorker muzammil;
    int salary,hour;
    cout<<"Input salary of worker: ";
    cin>>salary;
    cout<<"Input hours per day: ";
    cin>>hour;
    muzammil.infoRetrieval(salary,hour);
    muzammil.salIncrease();
    muzammil.workBenefit();
    return 0;
}