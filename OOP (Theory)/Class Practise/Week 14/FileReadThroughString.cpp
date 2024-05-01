#include <iostream>
#include <fstream>
using namespace std;
int main(){
	string str;
	ifstream f;
	f.open("smple.txt");
	while(f){
	getline(f,str);
	cout<<str<<endl;	
}
	f.close();}

