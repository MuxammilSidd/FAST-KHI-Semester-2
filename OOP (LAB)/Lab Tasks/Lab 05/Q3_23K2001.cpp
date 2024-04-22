//23K2001 Muzammil Q3
#include<iostream>
using namespace std;
class circle{
	private:
		float radius;
		const double PI= 3.141529654;

	public:
		circle()
		{
			radius = 0;
		}
		float calcCircumference()
		{
			return 2*PI*radius;
		}
		float calcArea()
		{
			return PI*radius*radius;
		}
		void setR(float radius)
		{
			this->radius = radius;
		}
		float getR()
		{
			return radius;
		}
		void show()
		{
			cout<<"\nRadius : "<<radius<<" units."<<endl;
			cout<<"Area : "<<calcArea()<<" sq-units."<<endl;
			cout<<"Circumference: "<<calcCircumference()<<" units."<<endl;
		}
		
};
int main()
{
	circle one;
	cout<<"Circle one (by default constructor): "<<endl;
	one.show();
	circle two;
	two.setR(7.5);
	cout<<"\nCircle two (by parameter constructor): "<<endl;
	two.show();
	return 0;
}
