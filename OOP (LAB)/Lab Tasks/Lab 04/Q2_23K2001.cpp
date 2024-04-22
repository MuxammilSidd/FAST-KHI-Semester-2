//232001 Muzammil
#include<iostream>
#include<math.h>
using namespace std;
class point{
	private:
	int x,y,z;
	
	public:
	void setX(int m)
	{
		x = m;
	}
	void setY(int n)
	{
		y = n;
	}
	void setZ(int p)
	{
		z = p;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getZ()
	{
		return z;
	}
	point(int m,int n,int p)
	{
		x=m;
		y=n;
		z=p;
	}
	float org_distance()
	{
		return sqrt(x*x+y*y+z*z);
	}
	point()
	{
		x=0;
		y=0;
		z=0;
	}
	~point()
	{
		cout<<"\nDestructor called, memory released."<<endl;
	}
};
int main()
{
    point img(5,8,11);
    point img2;
    cout<<"Values passed by default constructor: \n"<<endl;
    cout<<"X: "<<img2.getX()<<endl;
    cout<<"Y: "<<img2.getY()<<endl;
    cout<<"Z: "<<img2.getZ()<<endl;
    
    cout<<"Values passed through parameterized constructor: \n"<<endl;
    cout<<"X: "<<img.getX()<<endl;
    cout<<"Y: "<<img.getY()<<endl;
    cout<<"Z: "<<img.getZ()<<endl;
    cout<<"Distance from origin of passed point: "<<endl;
    cout<<img.org_distance()<<" units."<<endl;
    
    cout<<"\nInput your own points: "<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    img2.setX(a);
    img2.setY(b);
    img2.setZ(c);
    cout<<"\nValues passed by user using setters: \n"<<endl;
    cout<<"X: "<<img2.getX()<<endl;
    cout<<"Y: "<<img2.getY()<<endl;
    cout<<"Z: "<<img2.getZ()<<endl;
    cout<<"Distance from origin of your point: "<<endl;
    cout<<img2.org_distance()<<" units."<<endl;
    
    return 0;
}