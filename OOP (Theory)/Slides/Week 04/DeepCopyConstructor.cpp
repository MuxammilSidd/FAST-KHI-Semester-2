#include <iostream> 
using namespace std;  
class box { 
	public:
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
		cout << " Length = " << length  << "\n Breadth = " << *breadth  << "\n Height = " << height ;
			
			
			 } 
/*box(box& sample) 
	{ 
		length = sample.length; 
		breadth = new int; 
		*breadth = *(sample.breadth); 
		height = sample.height; 
	} 
*/

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
	// Display the dimensions 
	first.show_data();
	box second ;
	second= first; 
	cout<<"\n";
	// Display the dimensions of object second
	second.show_data(); 
	cout<<"\n";
	first.set_dimension(20,30,40);
	cout<<"Display dimension of object first after update value of bredth";
	first.show_data();
	cout<<"Display dimension of object seond after update value of bredth";
	second.show_data();		

	return 0; 
}

