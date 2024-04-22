//23K2001 Muzammil
#include<iostream>
using namespace std;

class car{
    private:
    string model;
    int year, price;

    public:
    void setModel(string name)
    {
        model = name;
    }
    void setYear(int yr)
    {
        year = yr;
    }
    void setPrice(int p)
    {
        price = p;
    }
    string getModel()
    {
        return model;
    }
    int getYear()
    {
        return year;
    }
    int getPrice()
    {
        return price;
    }
};

int main()
{
    car dreamcar;
    cout<<"..Setting values.."<<endl;
    dreamcar.setModel("Lamborghini Aventador LP 780-4 Ultimae");
    dreamcar.setYear(2022);
    dreamcar.setPrice(500000);
    cout<<"Values:\n"<<endl;
    cout<<"Model: "<<dreamcar.getModel()<<endl;
    cout<<"Year: "<<dreamcar.getYear()<<endl;
    cout<<"Price: $"<<dreamcar.getPrice()<<endl;
    return 0;
}