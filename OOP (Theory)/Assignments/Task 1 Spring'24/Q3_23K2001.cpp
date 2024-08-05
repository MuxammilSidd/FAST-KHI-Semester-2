//23K2001 Muzammil
#include<iostream>
using namespace std;

class carspec{
    private:
    int door, wheels, car_speed;

    public:

    carspec()
    {
        door = 2;
        wheels = 4;
        car_speed =0;
    }
    void civic()
    {
        cout<<"Civic function invoked."<<endl;
        cout<<"Wheels: "<<wheels<<" Door: "<<door<<endl;
    }
    void rubicon()
    {
        wheels +=2;
        door +=2;
        cout<<"Rubicon function invoked."<<endl;
        cout<<"Wheels: "<<wheels<<" Door: "<<door<<endl;

    }
    void speed()
    {
        car_speed += 7;
        cout<<"Speed function invoked."<<endl;
    }
    void brake()
    {
        car_speed -= 7;
        cout<<"Brake function invoked."<<endl;
    }
    int meter()
    {
        return car_speed;
    }
};
int main()
{
    carspec tuning;
    tuning.civic();
    tuning.rubicon();
    cout<<"Current speed: "<<tuning.meter()<<endl;
    tuning.speed();
    cout<<"Current speed: "<<tuning.meter()<<endl;
    tuning.brake();
    cout<<"Current speed: "<<tuning.meter()<<endl;

    return 0;
}