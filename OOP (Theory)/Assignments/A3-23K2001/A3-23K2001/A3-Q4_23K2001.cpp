//23K2001 Muzammil Q4
#include<iostream>
#include <unistd.h>
#include<cmath>
using namespace std;
class Flyable{
    public:
    virtual void takeoff()=0;
    virtual void land()=0;
    virtual void navigate(float latitude,float longitude,float altitude)=0;
};
class Scannable{
    public:
    virtual void scanArea(float radius)=0;
};
class Drone : public Flyable, public Scannable{
    protected:
    float longit,latit,speed,alt;

    public:
    Drone(float la,float lo,float a,float s): longit(lo),latit(la),alt(a),speed(s){}
    void adjustAlt(float m){ alt = m; }
    float getAlt(){ return alt; }
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
    Recondrone(float la,float lo,float a,float s,int c,int m):Drone(la,lo,a,s),cameraResolution(c),maxTime(m){}
    void takeoff(){ cout<<"\nDrone is taking off now!"<<endl; }
    void land(){ cout<<"\nDrone is landing now!"<<endl; }
    void scanArea(float radius){ 
        try{
            if(radius<0)
            throw 533;

            cout<<"\nScanning for objects within "<<radius<<"m"<<endl;
            int objs = rand()%6;
            cout<<objs<<" objects found!"<<endl;
            cout<<"\t      LAT-LON-ALT"<<endl;
            for(int i=1;i<=objs;i++){
                cout<<"Detection "<<i<<" at ";
                cout<<(float)(rand()%90)<<" "<<(float)(rand()%180)<<" "<<(float)(rand()%(int)(getAlt()))<<endl;
            }
        }
        catch(int e){ cout<<"Error: "<<e<<" -Couldn't forward your request (COMMUNICATION FAILURE)!-"<<endl; }
    }
 
    void navigate(float latitude,float longitude,float altitude){
        try{
            if(latitude>90 || longitude>180 || altitude<0)
            throw 404;

            cout<<"\nDistance to target: ";
            float d = sqrt(pow((latitude-latit),2)+pow((longitude-longit),2)+pow((altitude-alt),2));
            cout<<d<<"m"<<endl;
            cout<<"\nTime required to reach target at "<<speed<<" m/s ";
            cout<<"& Altitude: "<<alt<<endl;
            cout<<d/speed<<" sec"<<endl;
            setPos(latitude,longitude);
            adjustAlt(altitude);
        }
        catch(int e){ cout<<"Error: "<<e<<" -Invalid coordinates, please enter in a valid range!-"<<endl; }
    } 
};

int main(){
    cout<<"23K2001 - Muzammil"<<endl;
    Recondrone fighterX(70,65,80,5,720,60);
    fighterX.takeoff();
    fighterX.navigate(90,115,39);
    fighterX.scanArea(20);
    fighterX.land();
    return 0;
}