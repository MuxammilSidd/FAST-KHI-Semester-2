//23K2001 Q2
#include<iostream>
#include<windows.h>
using namespace std;
class menuItem{
    public:
    virtual void prepare()=0;
    virtual void serve()=0;
};
class appetizer : public menuItem{
    public:
    void prepare(){
        cout<<"..preparing Hors d'Oeuvres with our delicate speciality!"<<endl;
    }
    void serve(){
        cout<<"..serving the starters!"<<endl;
        Sleep(2000);
        cout<<"..please taste our special dish while we prepare for the main course..\n"<<endl;
    }
};
class maincourse : public menuItem{
    public:
    void prepare(){
        Sleep(1500);
        cout<<"..preparing main course.."<<endl;
        Sleep(2500);
        cout<<"..applying complex cooking techniques."<<endl;
    }
    void serve(){
        Sleep(1500);
        cout<<"..serving the main course!"<<endl;
        Sleep(2000);
        cout<<"..we hope that you will be delighted by our chef's culinary expertise.\n"<<endl;
    }  
};
class dessert : public menuItem{
    public:
    void prepare(){
        Sleep(1500);
        cout<<"..preparing desserts.."<<endl;
        Sleep(2500);
        cout<<"..decorating the dish with our intricate skills."<<endl;
    }
    void serve(){
        Sleep(1500);
        cout<<"..serving the desserts!"<<endl;
        Sleep(2000);
        cout<<"..we are glad to have you at our restaurant today, please let us know if you need anything else!\n"<<endl;
    } 
};
int main()
{
    appetizer a1;
    maincourse m1;
    dessert d1;
    a1.prepare();
    a1.serve();
    m1.prepare();
    m1.serve();
    d1.prepare();
    d1.serve();
    return 0;
}