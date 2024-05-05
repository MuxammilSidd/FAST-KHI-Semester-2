//23k2001  Q5
#include<iostream>
using namespace std;

template<class T> class arrayForsum{	
	public:
	T sum(T arr[],int n){
		T ans=0;
		for(int i=0;i<n;i++)
		ans+=arr[i];
		
		return ans;
	}
};

int main()
{
	arrayForsum<int> intTest;
	arrayForsum<double> doubleTest;
	
	int a[]={1,2,3,4,5};
	double b[]={1.5,2.5,3.5};
	
	int ans1 = intTest.sum(a,5);
	cout<<"Sum A (integer array): "<<ans1<<endl;
	double ans2 = doubleTest.sum(b,3);
	cout<<"Sum B (double array): "<<ans2<<endl;
	return 0;
}