#include <iostream>
#include <fstream>
using namespace std;
int main(){
	string str;
	ifstream f;
	f.open("Test.txt");
	while(getline(f, str)) //reading through file object
    {
	cout<<str<< endl;
		}	
	f.close();}

