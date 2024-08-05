#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ofstream out("Test.txt");
if(!out){ 	
cout << "File creation failed";	
return 1;
}
out << "Ali " << 100 << endl;
out << "Abid " << 200 << endl;
out.close();return 0;
}

