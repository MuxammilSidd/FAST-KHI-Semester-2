#include<iostream>
using namespace std;
class Samplecopyconstructor
{
    public:
    int x, y;   //data members
    
    public:
    Samplecopyconstructor(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    
    // Copy constructor 
    Samplecopyconstructor ( Samplecopyconstructor &sam)
    {
    	sam.x++;
        x = sam.x+1;
       sam.x+=1;
        y = sam.y;
    }
    
    
    void display()
    {
        cout<<x<<" "<<y<<endl;
    }
};
/* main function */
int main()
{
    Samplecopyconstructor obj1(10, 15);
    Samplecopyconstructor obj2 = obj1;      //Default Copy constructor
    cout<<"Normal constructor : ";
    obj1.display();
    cout<<"Copy constructor : ";
    obj2.display();
    Samplecopyconstructor obj3(obj1);
    obj1.x=20;
    cout<<"Copy Constructor 2 ";
    obj3.display();
    cout<<"Normal Copy Constructor  ";  
    obj1.display();
    return 0;
}
