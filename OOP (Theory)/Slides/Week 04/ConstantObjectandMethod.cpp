#include<iostream>
using namespace std;
class StarWars
{
    public:
    int i;
    StarWars(int x )   // constructor
    { 
        i = x; 
    }
 StarWars( )   // constructor
    { 
        cout<<"Constructor Calling";
    }
    int falcon(int j) const  // constant function
    { 
        /* 
            can do anything but will not
            modify any data members
        */
        
        //i=j;
        cout << "Falcon has left the Base";
    }

    int gamma()
    { 
        i++; 
    }
    void setI(int num){
    	i=num;
	}
};

int main()
{
	
    StarWars objOne;        // non const object
    const StarWars objTwo(2);      // const object
    objOne.i=100;
    //objTwo.setI(5);
    objOne.falcon(5);     // No error
    objTwo.falcon(6);     // No error
    cout << objOne.i << objTwo.i;
    
    

    objOne.gamma();     // No error
    //objTwo.gamma();     // Compile time error
}
