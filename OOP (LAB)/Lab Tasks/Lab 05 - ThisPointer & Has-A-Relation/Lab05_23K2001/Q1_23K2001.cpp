//23K2001 Muzammil Q1
#include<iostream>
using namespace std;
class realtorCommission{
	private:
		double price,rate,commission;
		
	public:
		realtorCommission(double price,double rate)
		{
			this->price = price;
			this->rate = rate;
			commission = price * rate;
		}
		realtorCommission(int price,int rate)
		{
			this->price = price;
			this->rate = rate;
			commission = (price * rate)/100;
		}
		void display()
		{
			cout<<"\nPrice: "<<price<<endl;
			cout<<"Rate: "<<rate<<endl;
			cout<<"Commission Earned: "<<commission<<endl;
		}
	
};
int main()
{
	realtorCommission shandaar(4500.354,0.75);
	cout<<"\nDisplaying Shaandaar Object: (Decimal values)"<<endl;
	shandaar.display();
	
	realtorCommission nobel(40000,3);
	cout<<"\nDisplaying Nobel Object: (WholeNumber Values & Commission through %)"<<endl;
	nobel.display();
	return 0;
}
