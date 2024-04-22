//23K2001 Muzammil
#include<iostream>
using namespace std;

class RectShape{
    private:
    int lenght, breadth;

    public:
    RectShape()
    {
        lenght = 0;
        breadth = 0;
        cout<<"..default constructor invoked"<<endl;
    }
    RectShape(int lenght, int breadth)
    {
        this->lenght = lenght;
        this->breadth = breadth;
        cout<<"..2 parameter constructor invoked"<<endl;

    }
    RectShape(int val)
    {
        lenght = val;
        breadth = val;
        cout<<"..1 parameter constructor invoked"<<endl;

    }

    int area()
    {
        return lenght*breadth;
    }
};

int main()
{
    RectShape recA;
    cout<<"Area = "<<recA.area()<<endl;
    RectShape recB(7,19);
    cout<<"Area = "<<recB.area()<<endl;
    RectShape recC(17);
    cout<<"Area = "<<recC.area()<<endl;
 
    return 0;
}