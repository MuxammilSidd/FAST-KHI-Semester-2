#include <iostream>
using namespace std;

class Distance {
private:
int meter;
// friend function
public:
friend int addFive(Distance);
Distance() : meter(0) {}
};

// friend function definition
int addFive(Distance d) {
//accessing private members from
d.meter += 5;
return d.meter;
}

int main() {
Distance D;
cout << "Distance: " <<
addFive(D);
return 0;
}