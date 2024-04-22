//23k2001 Q3
#include<iostream>
using namespace std;
class furniture{
protected:
string name;
float price;
int qty;
public:
furniture(string name,float price,int qty):name(name),price(price),qty(qty){}
furniture operator +(furniture obj){
    furniture temp("",0.0,0);
    temp.name = name+obj.name;
    temp.price = price+obj.price;
    temp.qty = (qty<obj.qty? qty : obj.qty);
    return temp;
}
void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Price: $"<<price<<endl;
    cout<<"Quantity: "<<qty<<endl;
}

};
int main()
{
    furniture chair("Wooden Chair",50.0,10);
    furniture table("Glass Table",100.0,5);
    furniture combined = chair+table;
    cout<<"Combined object:"<<endl;
    combined.display();
    cout<<"\nOld objects:"<<endl;
    chair.display();
    table.display();
    return 0;
}