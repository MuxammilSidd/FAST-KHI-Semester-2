#include <iostream>
#include <fstream>
using namespace std;
int main(){
	char chW[20] = {'T', 'h', 'i', 's', 'i', 's', 'a', 't','e','s','t'};
	ofstream f("XYZ");
//	f << "hello";
	f.write(chW, 20);
	f.close();
	ifstream i("XYZ");
	// Reading block (array) of characters
	char chR[20];
	i.read(chR, 20);
	for(int i = 0; i < 20; i++)
	{
		cout << chR[i];
	}

	f.close();	
}

