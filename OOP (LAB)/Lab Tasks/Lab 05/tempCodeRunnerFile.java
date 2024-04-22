#include<iostream>
using namespace std;

class room
{
public:
    int num;
    int cap;
    bool occupied;

public:
    room(int n, int c, bool o)//:num(n),cap(c),occupied(o)
     {
        num(n);
        cap(c);
        occupied(o);
     }

    bool checkavailability() const
    {
        if(occupied==0)
            cout << "Available" << endl;
        else
            cout << "Not Available" << endl;
    }
};

class hotel
{
private:
    static const int totalrooms=10;
    room rooms[totalrooms];

public:
    hotel()
    {
        int i;
        for(i=0; i<totalrooms; i++)
        {
            rooms[i].num=i;
            rooms[i].cap=2;
            rooms[i].occupied=0;
        }
    }

    void displayavailable()
    {
        int i;
        for(i=0; i<totalrooms; i++)
        {
            if(rooms[i].occupied==0)
            {
                cout << "Room no:" <<rooms[i].num<< endl;
            }
        }
    }
};

int main()
{
    return 0;
}