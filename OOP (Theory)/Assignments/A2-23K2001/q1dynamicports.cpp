//23K2001 Muzammil Q1
#include<iostream>
using namespace std;

class securitytool{
protected:
int devices;
string level;
float cost;

public:
securitytool(string level,int devices,float cost) : level(level),devices(devices),cost(cost){
    int c1=0,c2=0;
    do{
        if(level=="High" || level=="high" || level=="medium" || level=="Medium" || level=="Low" || level=="low")
        c1=1;
        else{
            cout<<"Please enter correct security level (High/Medium/Low): ";
            cin>>level;
            continue;
        }
        if(cost>0)
        c2=1;
        else{
            cout<<"Cost can not be <= 0 , please enter valid amount: ";
            cin>>cost;
            continue;
        }
    }while(c1==0 || c2==0);

}


void performScan(){
cout<<"\nPerforming general security scan.."<<endl;
cout<<"...devices connected: "<<devices<<endl;
cout<<"...security level: "<<level<<endl;
}
string getLevel()
{
    return level;
}
};

class firewallTool : public securitytool{
protected:
int n;
int *ports;
string protocols[6]={"HTTPS","FTP","UDP","ICMP","SSH","SNMP"};

public:
firewallTool(string level,int devices,float cost) : securitytool(level,devices,cost){
int c=0;
do{
    if(devices<=10)
    {
        int p;
        cout<<"Please input how many ports: ";
        cin>>p;
        n=p;
        ports = new int[n];
        // cout<<"Please input the Port-# of "<<n<<" ports:";
        // for(int i=0;i<n;i++)
        // {
        //     cin>>ports[i];
        // }
        c=1;
    }
    else{
        cout<<"Firewall can operate on only 10 devices at max, kindly input again: ";
        cin>>devices;
    }
}while(c==0);

}

void generateList()
{
    cout<<"Enter your student id (XXXX): ";
    string id;
    cin>>id;
    int x,f=0;
    cout<<"Please specify which digit to select from your id: ";
    do{
        cin>>x;
        if(x!=0)
        {
            for(int i=0;i<4;i++)
            {
                if((char)(x+'0')==id[i])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                cout<<"Invalid digit, please enter again! ";
                continue;
            }
        }
        else
        {
            cout<<"Please select any digit except 0! ";
            continue;
        }
    } while(f==0); 

    for(int i=0;i<n;i++)
    {
        x++;
        ports[i] = x;
    }   
}

void performScan()
{
    securitytool::performScan();
    if(getLevel()=="High" || getLevel()=="high")
    {
        cout<<"...traffic flow from ports:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<ports[i]<<" ";
        }
        cout<<endl;
    }
    else if(getLevel()=="Medium" || getLevel()=="medium")
    {
        cout<<"...traffic flow from ports:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<ports[i]<<" ";
        }
        cout<<"\n + 2 more ports: ";
        cout<<ports[n-1]+1<<" "<<ports[n-1]+2<<endl;
    }
    else if(getLevel()=="Low" || getLevel()=="low")
    {
        cout<<"...traffic flow from ports:"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<ports[i]<<" ";
        }
        cout<<"\n + 5 more ports: ";
        for(int i=1;i<=5;i++)
        {
        cout<<ports[n-1]+i<<" ";
        }
        cout<<endl;
    }
}
~firewallTool()
{
    delete[] ports;
}
};
int main()
{
    cout<<"23K2001 - Muzammil\n\n"<<endl;
    firewallTool f("low",5,25000);
    f.generateList();
    f.performScan();
    return 0;
}