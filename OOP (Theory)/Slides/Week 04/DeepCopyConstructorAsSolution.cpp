#include <iostream> 
using namespace std;  
class box { 
	int length; 
	int* breadth; 
	int height; 
public: 
	box() { 
		breadth = new int;
		 }  
	void set_dimension(int len, int brea, int heig) { 
		length = len; 
		*breadth = brea; 
		height = heig;	} 
	void show_data() { 
		cout << " Length = " << length 
			<< "\n Breadth = " << *breadth 
			<< "\n Height = " << height 
			<< endl; } 
			void setBreadth(int bred){
				*breadth=bred;
			}
			
box(const box& sample) 
	{ 
		length = sample.length; 
		breadth = new int; 
		*breadth = *(sample.breadth); 
		height = sample.height; 
	} 

	// Destructors 
	~box() 
	{ 
		delete breadth; 
	} 
}; 
int main() 
{ 
	// Object of class first 
	box first; 

	// Set the dimensions 
	first.set_dimension(12, 14, 16); 
	cout <<"First Object Data";
	first.show_data();
	box second = first; 
	first.setBreadth(34);
	// Display the dimensions
	cout << "First Updated  Object Data"; 
	first.show_data(); 	
    // Display the dimensions
	cout << "Second Object Data" ;
	second.show_data(); 

	return 0; 
}

