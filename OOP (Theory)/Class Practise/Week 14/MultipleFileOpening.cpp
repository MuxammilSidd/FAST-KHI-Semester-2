#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream f;
	f.open("file1");
	f << "hello";
	f.close();//without close compiler implicitly close the file	
//	 second file through the same file stream	
	f.open("file2")	;
	f<<"i am a student";
	f.close();		
}

