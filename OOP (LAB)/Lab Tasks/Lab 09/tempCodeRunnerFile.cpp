//23K2001 Q1
#include<iostream>
using namespace std;


class location{
protected:
int latit,longit;
public:
location(int latit, int longit): latit(latit),longit(longit){}
virtual void display() const{
    cout<<"\nLatitude: "<<latit<<endl;
    cout<<"Longitude: "<<longit<<endl;
}
void setLatit(int latit){this->latit=latit;}
int getLatit(){return latit;}
void setLongit(int longit){this->longit=longit;}
int getLongit(){return longit;}
void operator ++(){
    ++latit;
    ++longit;
}
void operator ++(int x){
    latit++;
    longit++;
}
void operator +(int x){
    latit+=x;
    longit+=x;
}
friend location operator +(int x,location &obj){
    obj.latit+=x;
    obj.longit+=x;
    return obj;
}
location& operator =(location &obj){
    longit = obj.longit;
    latit = obj.latit;
    return *this;
}
};


class details : public location{
protected:
string address;
public:
void display() const{
    location::display();
    cout<<"Address: "<<address<<endl;
}
details(int latit, int longit,string address): location(latit,longit),address(address){}
};
int main()
{
    details d1(66,37,"Gulshan Karachi");
    location obj1(10,20), obj2(5,30), obj3(90,90);
    cout<<"Details object:"<<endl;
    d1.display();
    cout<<"\nLocation objects:"<<endl;
    obj1.display();
    obj2.display();
    obj3.display();


    cout<<"\nPreincrement on Obj1:";
    ++obj1;
    obj1.display();
 
    cout<<"Post increment on Obj1 & assigned to Obj2:";
    obj1++;
    obj2=obj1;
    obj2.display();


    cout<<"\nAdding 10 right to obj1 & assigned to obj2";
    obj1+10;
    obj2=obj1;
    obj2.display();


    cout<<"\nAdding 10 left to obj1 & assigned to obj2";
    10+obj1;
    obj2=obj1;
    obj2.display();


    cout<<"\nAssigning Obj3 to Obj1 & Obj2:";
    obj1=obj2=obj3;
    obj1.display();
    obj2.display();
    obj3.display();
   
    cout<<"\nPointer object:"<<endl;
    location *ins = &d1;
    ins->display();
    return 0;
}
