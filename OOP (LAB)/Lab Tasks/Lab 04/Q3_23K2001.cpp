//23K2001 Muzammil
#include<iostream>
using namespace std;
class sale{
	private:
	int saleID,qty;
	string item_name;
	
	public:
	sale()
	{
		saleID = 123456;
		qty = 5;
		item_name = "sample";
	}
	sale(int id, int q, string item)
	{
		cout<<"***Constructor implementing user input..***"<<endl;
		saleID = id;
		qty = q;
		item_name = item;
	}
	sale(string item,int id, int q)
	{
		cout<<"\n***Parameterized constructor initializing variables..***"<<endl;
		saleID = id;
		qty = q;
		item_name = item;
	}
	sale(const sale &sample)
	{
		saleID = sample.saleID;
		qty = sample.qty;
		item_name = sample.item_name;
	}
	~sale()
	{
		cout<<"\nDestructor called, memory released."<<endl;
	}
	int getID()
	{
		return saleID;
	}
	int getQuantity()
	{
		return qty;
	}
	string getItem()
	{
		return item_name;
	}
};
int main()
{
    sale shop1;
    cout<<"Shop1 sales values (Set by default constructor): "<<endl;
    cout<<"ID: "<<shop1.getID()<<endl;
    cout<<"Quantity: "<<shop1.getQuantity()<<endl;
    cout<<"Item name: "<<shop1.getItem()<<endl;
    
	int id, q;
    string item;
    cout<<"\nInput values for your shop sales: "<<endl;
    cout<<"Input id: ";
	cin>>id;
	cout<<"Input quantity: ";
	cin>>q;
	cout<<"Input name: ";
	cin>>item;
    sale shop2(id,q,item);
    cout<<"\nShop2 sales values (Set by user input): "<<endl;
    cout<<"ID: "<<shop2.getID()<<endl;
    cout<<"Quantity: "<<shop2.getQuantity()<<endl;
    cout<<"Item name: "<<shop2.getItem()<<endl;
    
	sale shop3("T-shirts",55493,10);
    cout<<"\nShop3 sales values (Passed by parameterized constructor): "<<endl;
	cout<<"ID: "<<shop3.getID()<<endl;
    cout<<"Quantity: "<<shop3.getQuantity()<<endl;
    cout<<"Item name: "<<shop3.getItem()<<endl;

    sale shop4 = shop2;
    cout<<"\nShop4 sales values (Copied from shop2): "<<endl;
    cout<<"ID: "<<shop4.getID()<<endl;
    cout<<"Quantity: "<<shop4.getQuantity()<<endl;
    cout<<"Item name: "<<shop4.getItem()<<endl;
    return 0;
}