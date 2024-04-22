//23K2001 Muzammil
#include<iostream>
using namespace std;
class Distance{
	private:
	float feet, inch;
	
	public:
	Distance()
	{
		feet = 100;
		inch = 100;
	}
	void userinput()
	{
		float d;
		cout<<"Input distance in meters: ";
		cin>>d;
		feet = d*3.281;
		inch = d*39.37;
	}
	float displayMeter(float x)
	{
		return feet*0.3048;
	}
	float displayFeet(float x)
	{
		return feet;
	}
	float getFeet()
	{
		return feet;
	}
	float getInch()
	{
		return inch;
	}
	~Distance()
	{
		cout<<"\nObject was killed, memory released.."<<endl;
	}
};
int main()
{
    Distance route;
	cout<<"Default values set by constructor: "<<endl;
	cout<<"Feet: "<<route.getFeet()<<endl;
	cout<<"Inch: "<<route.getInch()<<endl;

	cout<<"\nSet your values: "<<endl;
	route.userinput();
	cout<<"\nValues now are: "<<endl;
	cout<<"Feet: "<<route.getFeet()<<endl;
	cout<<"Inch: "<<route.getInch()<<endl;
    return 0;
}