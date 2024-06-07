//23K2001 Q3
#include<iostream>
using namespace std;

class restaurantmeal{
protected:
string name;
float price;

public:
restaurantmeal(string name,float price):name(name),price(price){}
void display(){
    cout<<"\nName: "<<name<<endl;
    cout<<"Price: "<<price<<endl;
}
float getPrice(){return price;}
};
class hotelservice{
protected:
string service;
float fee;
int room;

public:
hotelservice(string service,float fee,int room):service(service),fee(fee),room(room){}
void display(){
    cout<<"Service: "<<service<<endl;
    cout<<"Service fee: "<<fee<<endl;
    cout<<"Room#- "<<room<<endl;
}
float getFee(){return fee;}
};
class roomServiceMeal: public restaurantmeal, public hotelservice{
public:
roomServiceMeal(string meal,float p,int r):hotelservice("room service",400.0,r),restaurantmeal(meal,p){}
void display(){
    restaurantmeal::display();
    hotelservice::display();
    cout<<"Total: "<<getPrice()+getFee()<<endl;
}
};
int main()
{
    roomServiceMeal steak("steak dinner",2000,1202);
    steak.display();
    return 0;
}  