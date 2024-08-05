#include <iostream>
using namespace std;
class GeometricShape {
    public:
        double length;
        double breadth;
        double height;   

        double calculateArea(){   
            return length * breadth;
        }

        double calculateVolume(){   
            return length * breadth * height;
        }

};
int main(){
    // create objects 
    GeometricShape shape1 ;
    GeometricShape shape2 ;
    shape1.length=4;
    shape1.breadth=5;
    shape1.height=6;
    double area=shape1.calculateArea();
    double volume=shape1.calculateVolume();
    cout << "The area of Geometric Shape \t"  << area;
    cout << endl;
    cout << volume;
    
}
