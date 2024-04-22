//23K2001 Q2
#include<iostream>
using namespace std;
class table{
    private:
    const int seats;
    int occ_seats;
    int free_seats;
    bool clean;

    public:
    table() : seats(4)
    {
        occ_seats = 0;
        free_seats = 4;
        clean = 1;
    }
    table(int s) : seats( s<=6 ? 4 : 8)                  
    {
        clean =1;
        occ_seats = 0;
        free_seats = seats;   
    }
    int getOccSeats()
    {
        return occ_seats;
    }
    int getCapacity()
    {
        return seats;
    }
    bool isClean()
    {
        return clean;
    }
    void cleanTable()
    {
        clean = true;
        cout<<"\nCleaning table.."<<endl;
    }
    void setFree()
    {
        occ_seats = 0;
        free_seats = seats;
        cout<<"\nTable is empty now."<<endl;
    }
    void useTable(int st)
    {
        occ_seats = st;
        cout<<"\nTable is in use!"<<endl;
    }
    void haveLunch()
    {
        clean = false;
        cout<<"\nSomeone is having lunch, will need to clean table afterwards!"<<endl;
    }
};
void occupyTable(table *t,int sz)
{
    int i;
    int f=0;
    for(i=0;i<5;i++)
    {
        if(t[i].getOccSeats()==0 && t[i].isClean()==true)
        {
            if(sz<=4 && t[i].getCapacity()==4)
            {
                cout<<"\nTable#"<<i+1<<" is available, with capacity for "<<t[i].getCapacity()<<endl;
                cout<<"Assigned to group of "<<sz<<" people."<<endl;
                f=1;
                break;
            }
            else if(sz>4 && t[i].getCapacity()==8)
            {
                cout<<"\nTable#"<<i+1<<" is available, with capacity for "<<t[i].getCapacity()<<endl;
                cout<<"Assigned to group of "<<sz<<" people."<<endl;
                f=1;
                break;
            }
        }
    }
    if(f==0)
    cout<<"\nNo tables to accommodate!"<<endl;
}
void emptyTable(table *t,int u)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(i==u)
        {
            if(t[i].isClean()==0)
            t[i].cleanTable();

            t[i].setFree();
            break;
        }
    }
}
int main()
{
    cout<<"23K2001 - Muzammil\n"<<endl;
    cout<<"\t*****Welcome to FAST Dhaba 2.0*****"<<endl;
    table t[5] = {table(),table(8), table(8),table(),table()};
    occupyTable(t,4);
    occupyTable(t,6);
    cout<<"\nTable 1: "<<endl;
    t[0].useTable(4);
    t[0].haveLunch();
    t[0].setFree();
    t[0].cleanTable();
    cout<<"\nTable 2: "<<endl;
    emptyTable(t,1);
    return 0;
}