//23K2001 Muzammil
#include<iostream>
using namespace std;
class temperature{
    private:
    float celsius;

    public:
    void setCelsius(float t)
    {
        celsius = t;
    }
    float getCelsius()
    {
        return celsius;
    }
    float in_fahrenheit()
    {
        return ((9.0/5.0)*(celsius))+32;
    }

};
int main()
{
    temperature lab;
    float temp;
    cout<<"Input lab temperature(in celsius): ";
    cin>>temp;
    lab.setCelsius(temp);
    cout<<"Lab temperature:\nCelsius: "<<lab.getCelsius()<<endl;
    cout<<"Fahrenheit: "<<lab.in_fahrenheit()<<endl;
    return 0;
}