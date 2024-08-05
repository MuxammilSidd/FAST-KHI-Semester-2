#include <iostream>
 
using namespace std;
 
class Line {
public:
      void setLength( double len );
      double getLength(  );
Line(){
     cout<< "Constructor Calling";
    }  // This is the constructor
   private:
    double length;
};

void Line::setLength( double len ) {
   length = len;
}
double Line::getLength( void ) {
   return length;
}
int main() {
   Line line;
   // set line length
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
   Line line2;
   // set line length
   line2.setLength(7.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   return 0;
}

