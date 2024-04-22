//23K2001 Q4
#include<iostream>
using namespace std;

class rollerCoaster{
    private:
    string name;
    float height, len,speed;
    int capacity,currentRiders;
    bool rideProgress;

    public:
    rollerCoaster()
    {
        name = "roller coaster";
        height = 500.0;
        len = 2000.0;
        speed = 0.0;
        capacity = 20;
        currentRiders = 0;
        rideProgress = false;
    }
    rollerCoaster(string name, float height, float len,float speed,int capacity,int currentRiders)
    {
        this->name = name;
        this->height = height;
        this->len = len;
        this->currentRiders = currentRiders;
        this->speed = speed;

        if((capacity%2==0 || capacity%3==0) && capacity>3)
        {
            this->capacity = capacity;
        }
        else
        {
            int i;
            for(i=0;;i++)
            {
                if(capacity%2==0 && capacity>3)
                {
                this->capacity = capacity;
                break;
                }
                else
                capacity++;   
            }
        }
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setHeight(float height)
    {
        this->height = height;
    }
    void setLen(float len)
    {
        this->len = len;
    }
    void setSpeed(float speed)
    {
        this->speed = speed;
    }
    void setCapacity(int capacity)
    {
        if((capacity%2==0 || capacity%3==0) && capacity>3)
        {
            this->capacity = capacity;
        }
        else
        {
            int i;
            for(i=0;;i++)
            {
                if(capacity%2==0 && capacity>3)
                {
                this->capacity = capacity;
                break;
                }
                else
                capacity++;   
            }
        }
    }
    void setCurrRiders(int currentRiders)
    {
        this->currentRiders = currentRiders;
    }
    void setProgress(bool rideProgress)
    {
        this->rideProgress = rideProgress;
    }
    string getName()
    {
        return name;
    }
    float getHeight()
    {
        return height;
    }
    float getLen()
    {
        return len;
    }
    float getSpeed()
    {
        return speed;
    }
    int getCapacity()
    {
        return capacity;
    }
    int getCurrRiders()
    {
        return currentRiders;
    }
    bool getProgress()
    {
        return rideProgress;
    }

    int loadRiders(int riders)
    {
        if((capacity-currentRiders)>=riders && rideProgress==false)
        {
            currentRiders+=riders;
            return 0;
        }
        else if((capacity-currentRiders)<riders && rideProgress==false)
        {
            int left = riders-(capacity-currentRiders);
            currentRiders = capacity;
            return left;
        }
        else if(rideProgress==true)
        {
            cout<<"Ride is active, cannot load!"<<endl;
        return riders;       
        }
    }
    int startCoaster()
    {
        if(rideProgress==false)
        {
            if(currentRiders==capacity)
            {
                cout<<"\nAll seats are occupied. Proceeded to start!"<<endl;
                rideProgress=true;
                return 0;
            }
            else
            {
                return capacity-currentRiders;
            }

        }
        else
        return -1;
    }
    void stopCoaster()
    {
        if(rideProgress==true)
        {
            cout<<"\nRide has stopped!"<<endl;
            setProgress(false);
            setSpeed(0);
        }
        else
        cout<<"\nRide had not started, please start first!"<<endl;
    }
    void unloadRider()
    {
        if(rideProgress==false)
        {
            cout<<"\nUnloaded passengers!"<<endl;
            setCurrRiders(0);
        }
        else
        cout<<"\nPlease stop the ride before unloading passengers!"<<endl;
    }
    void speedUp(int rnum)
    {
        int i;
        for(i=0;;i++)
        {
            if(rnum%10!=0)
            {
            speed+=(rnum%10);
            cout<<"\nSpeed increased by: "<<rnum%10<<endl;
            cout<<"Current speed: "<<getSpeed()<<endl;
            break;
            }

            else
            rnum/=10;
        }
    }
    void brake(int rnum[4])
    {
        int d,i;
        for(i=0;i<4;i++)
        {
            if(rnum[i]!=0)
            {
                d = rnum[i];
                break;
            }
        }

        speed-=d;
        cout<<"\nSpeed decreased by: "<<d<<endl;
        cout<<"Current speed: "<<getSpeed()<<endl;
    }

};
int main()
{
    cout<<"23K2001 - Muzammil\n"<<endl;
    rollerCoaster askari;
    cout<<"First coaster:"<<endl;
    cout<<"\nName: "<<askari.getName()<<endl;
    cout<<"Height: "<<askari.getHeight()<<endl;
    cout<<"Length: "<<askari.getLen()<<endl;
    cout<<"Speed: "<<askari.getSpeed()<<endl;
    cout<<"Capacity: "<<askari.getCapacity()<<endl;
    cout<<"Current riders: "<<askari.getCurrRiders()<<endl;
    cout<<"Progress: ";
    if(askari.getProgress())
    cout<<"Ride active"<<endl;
    else
    cout<<"Ride in-active"<<endl;

    rollerCoaster dollmen("Dollmen RollerCoaster",250.0,430.0,15.0,13,4);
    cout<<"\nSet progress for second object (1-Active/0-Inactive): ";
    bool p;
    cin>>p;
    dollmen.setProgress(p);
    cout<<"\nSecond coaster:"<<endl;
    cout<<"\nName: "<<dollmen.getName()<<endl;
    cout<<"Height: "<<dollmen.getHeight()<<endl;
    cout<<"Length: "<<dollmen.getLen()<<endl;
    cout<<"Speed: "<<dollmen.getSpeed()<<endl;
    cout<<"Capacity: "<<dollmen.getCapacity()<<endl;
    cout<<"Current riders: "<<dollmen.getCurrRiders()<<endl;
    cout<<"Progress: ";
    if(dollmen.getProgress())
    cout<<"Ride active"<<endl;
    else
    cout<<"Ride in-active"<<endl;

    cout<<"\nChange capacity for "<<dollmen.getName()<<": ";
    int c;
    cin>>c;
    dollmen.setCapacity(c);
    cout<<"Capacity now: "<<dollmen.getCapacity()<<endl;

    cout<<"\nLoading 5 riders.."<<endl;
    int f1 = dollmen.loadRiders(5);
    if(f1==0)
    cout<<"Loaded successfully."<<endl;
    else if(f1>0)
    cout<<"No space for "<<f1<<" riders."<<endl;

    cout<<"\nFunction to start the coaster: "<<endl;
    int f2 = dollmen.startCoaster();
    if(f2==-1)
    cout<<"Ride is already active."<<endl;
    else
    cout<<"Empty seats available : "<<f2<<endl;

    cout<<"\nFunction to stop the coaster: "<<endl;
    dollmen.stopCoaster();

    cout<<"\nUnloading current "<<dollmen.getCurrRiders()<<" riders.."<<endl;
    dollmen.unloadRider();

    cout<<"\nFunction to speed up:"<<endl;
    dollmen.speedUp(2001);

    cout<<"\nFunction to apply brakes:"<<endl;
    int roll[4] = {0,2,0,1};
    dollmen.brake(roll);

    return 0;
}