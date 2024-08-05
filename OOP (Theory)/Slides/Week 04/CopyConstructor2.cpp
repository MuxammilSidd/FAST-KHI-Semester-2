#include <iostream> 
using namespace std; 
  class box { 
	public:
	int length; 
    int breadth; 
	int height; 
  public: 
    void set_dimensions(int length1, int breadth1, int height1) 
    { 
        length = length1; 
        breadth = breadth1; 
        height = height1; 
    } 
	void show_data() 
    { 
        cout << " Length = " << length 
        << "\n Breadth = " << breadth 
             << "\n Height = " << height 
             << endl; 
    } 
}; 

int main() 
{ 
    box B1, B3; 
  
    // Set dimensions of Box B1 
    B1.set_dimensions(14, 12, 16); 
    B1.show_data(); 
    box B2 = B1;
	B1.height=10; 
    cout <<"Object 2 Data";
    cout <<"The Height of Object 1 has been Changed" << B1.height << endl; 
    B2.show_data(); 
    //B3.show_data();
  
    return 0; 
}

