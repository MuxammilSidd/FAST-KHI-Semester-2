//23K2001 Muzammil Q4
#include<iostream>
#include<cmath>
using namespace std;
class Flyable{
    public:
    virtual void takeoff()=0;
    virtual void land()=0;
    virtual float navigate(float latitude,float longitude,float altitude)=0;
};
class Scannable{
    public:
    virtual void scanArea(float radius)=0;
};
class Drone : public Flyable, public Scannable{
    protected:
    float longit,latit,speed,alt;

    public:
    void adjustAlt(float m){ alt = m; }
    void setSpeed(float s=0){ speed = s; }
    void setPos(float latitude,float longitude){
        latit = latitude;
        longit = longitude;
    }
};
class Recondrone: public Drone{
    protected:
    int cameraResolution, maxTime;

    public:
    void takeoff(){ cout<<"\nDrone is taking off now!"<<endl; }
    void land(){ cout<<"\nDrone is landing now!"<<endl; }
    void scanArea(float radius){ cout<<"\nScanning for objects within "<<radius<<"m"<<endl; }
    
    float navigate(float latitude,float longitude,float altitude){
        cout<<"\nDistance to target: ";
        float d = sqrt(pow((latitude-latit),2)+pow((longitude-longit),2)+pow((altitude-alt),2));
        cout<<d<<"m"<<endl;
        
        return d;
    }
    void timeRequired(float latitude,float longitude,float altitude){
        float d = navigate(latitude,longitude,altitude);
        cout<<"\nTime required to reach target at "<<speed<<" m/s"<<endl;
        cout<<"& Altitude: "<<alt<<endl;
        cout<<d/speed<<" sec"<<endl;
    }   
};

int main(){
    cout<<"23K2001 - Muzammil"<<endl;
    Recondrone fighterX;
    fighterX.setPos(70,65);
    fighterX.adjustAlt(80);
    fighterX.setSpeed(5);
    fighterX.navigate(90,115,97);
    fighterX.timeRequired(90,115,97);
    fighterX.scanArea(20);

    return 0;
}