#include <iostream>
 
using namespace std;
 
class Line {

private:
double length;  

public:
Line(){
	length=6;
     cout<< "Constructor Calling";
    }  // This is the constructor
   double getLength(){
   	return length;
   }
};

int main() {
   Line line;
   cout << "Length of line : " << line.getLength() <<endl;
   Line line2;
   cout << "Length of line : " << line2.getLength() <<endl;
 Line line3;
   cout << "Length of line : " << line3.getLength() <<endl;
 
   return 0;
}

