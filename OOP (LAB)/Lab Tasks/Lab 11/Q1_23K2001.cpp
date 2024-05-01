//23K2001 Q1
#include<iostream>
using namespace std;
class person{
    protected:
    string name;

    public:
    virtual void getData()=0;
    virtual bool isOutstanding()=0;

    void putName(string name){ this->name=name; }
    string getName(){ return name; }
};
class student : public person{
    protected:
    float gpa;
    public:
    void getData(){
        cout<<"Input GPA: ";
        cin>>gpa; }
    bool isOutstanding(){
        if(gpa>3.5)
        return true;
        else
        return false;
    }
};
class professor : public person{
    protected:
    int p;
    public:
    void getData(){
        cout<<"Input n# of publications: ";
        cin>>p;
    }
    bool isOutstanding(){
        if(p>100)
        return true;
        else
        return false;
    }
};
int main()
{
    student muz;
    professor hashim;
    muz.putName("Muzammil Siddiqui");
    hashim.putName("Mr. Hashim");
    int ch;

    while(1){
        cout<<"\nAdd data in Professor obj - 1"<<endl;
        cout<<"Add data in Student obj - 2"<<endl;
        cout<<"Stop - 0"<<endl;

        cin>>ch;
        switch(ch){
            case 0:
            return 0;
            case 1: {
            hashim.getData();
            if(hashim.isOutstanding())
            cout<<hashim.getName()<<" is outsstanding professor!"<<endl;
            else
            cout<<hashim.getName()<<" is average.."<<endl;
            break;
            }
            case 2: {
            muz.getData();
            if(muz.isOutstanding())
            cout<<muz.getName()<<" is outstanding student!"<<endl;
            else
            cout<<muz.getName()<<" is average.."<<endl;
            break;
            }
            default:
            cout<<"Invalid choice!"<<endl;
        }
    }
    return 0;
}