//23K2001 Q2
#include<iostream>
using namespace std;
class product{
protected:
string barcode, name;
public:
product(string b="123456", string n="porduct-xyz"):barcode(b),name(n){}
void setName(string name){
    this->name = name;
}
void setCode(string code){
    barcode = code;
}
string getCode(){
    return barcode;
}
string getName(){
    return name;
}
void scanner(){
    string name, code;
    cout<<"\nInput name: ";
    cin>>name;
    cout<<"Input barcode: ";
    cin>>code;
    setName(name);
    setCode(code);
}
void printer(){
    cout<<"\nPrinting info: "<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Barcode: "<<getCode()<<endl;
}
};
class prepacked: public product{
protected:
float price;

public:
prepacked(string name="product-xyz",string barcode="123456",float price=0.0):product(barcode,name),price(price){}
void setPrice(float price){
    this->price = price;
}
float getPrice(){
    return price;
}
void scanner(){
    string name, code;
    float price;
    cout<<"\nInput name: ";
    cin>>name;
    cout<<"Input barcode: ";
    cin>>code;
    cout<<"Input price per unit: ";
    cin>>price;
    setName(name);
    setCode(code);
    setPrice(price);
}
void printer(){
    cout<<"\nPrinting info: "<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Barcode: "<<getCode()<<endl;
    cout<<"Price per unit: "<<getPrice()<<endl;
}
};
class fresh : public product{
protected:
float weight, pricekg;

public:
fresh(string name="product-xyz",string barcode="123456",float price=0.0,float weight=0.0):product(barcode,name),pricekg(price),weight(weight){}
void setPricekg(float p){
    this->pricekg = p;
}
void setWeight(float w){
    this->weight = w;
}
float getPricekg(){
    return pricekg;
}
float getWeight(){
    return weight;
}
void scanner(){
    string name, code;
    float price,weight;
    cout<<"\nInput name: ";
    cin>>name;
    cout<<"Input barcode: ";
    cin>>code;
    cout<<"Input price per kg: ";
    cin>>price;
    cout<<"Input weight: ";
    cin>>weight;
    setName(name);
    setCode(code);
    setPricekg(price);
    setWeight(weight);
}
void printer(){
    cout<<"\nPrinting info: "<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Barcode: "<<getCode()<<endl;
    cout<<"Price per kg: "<<getPricekg()<<endl;
    cout<<"Weight: "<<getWeight()<<endl;
}
};

int main()
{
    product def1;
    fresh def2;
    prepacked def3;

    cout<<"\nProduct object default: "<<endl;
    def1.scanner();
    def1.printer();
    cout<<"\nFresh object default: "<<endl;
    def2.scanner();
    def2.printer();
    cout<<"\nPrepacked object default: "<<endl;
    def3.scanner();
    def3.printer();

    product par1("112905","Salmon");
    prepacked par2("115025","Nugget",3000.35);
    fresh par3("1195306","Mango",320.35,5.7);

    cout<<"\nProduct object parameterized: "<<endl;
    cout<<"Name: "<<par1.getName()<<endl;
    cout<<"Barcode: "<<par1.getCode()<<endl;

    cout<<"\nPrepacked object parameterized: "<<endl;
    cout<<"Name: "<<par2.getName()<<endl;
    cout<<"Barcode: "<<par2.getCode()<<endl;
    cout<<"Price per unit: "<<par2.getPrice()<<endl;

    cout<<"\nFresh object parameterized: "<<endl;
    cout<<"Name: "<<par3.getName()<<endl;
    cout<<"Barcode: "<<par3.getCode()<<endl;
    cout<<"Price per kg: "<<par3.getPricekg()<<endl;
    cout<<"Weight: "<<par3.getWeight()<<endl;
    return 0;
}