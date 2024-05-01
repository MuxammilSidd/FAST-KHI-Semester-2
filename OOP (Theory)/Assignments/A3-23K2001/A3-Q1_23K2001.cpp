//23K2001 Muzammil Q1
#include<iostream>
using namespace std;
class medicine{
    protected:
    string name,formula;
    float price;
    int mfDate,expDate;
    
    public:
    medicine(){}
    medicine(string name,string formula,float price,int mfDate,int expDate){
        this->name=name;
        this->formula=formula;
        this->price=price;
        this->mfDate=mfDate;
        this->expDate=expDate;
    }
    void setName(string name){ this->name = name; }
    void setFormula(string formula){ this->formula = formula; }
    void setPrice(float price){ this->price = price; }
    void setMdate(int mfDate){ this->mfDate = mfDate; }
    void setEDate(int expDate){ this->expDate = expDate; }

    string getName(){ return name; }
    string getFormula(){ return formula; }
    float getPrice(){ return price; }
    int getMdate(){ return mfDate; }
    int getEdate(){ return expDate; }

    virtual void display(){
        cout<<"\nName: "<<name<<endl;
        cout<<"Formula: "<<formula<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Manufacture: "<<mfDate<<endl;
        cout<<"Expiry: "<<expDate<<endl;
    }

    bool operator ==(medicine &m1){
        if(this->expDate/10000==m1.expDate/10000){
            return 1;
        }
        else
        return 0;
    }
};
class Tablet : public medicine{
    protected:
    bool sucroseLevel;

    public:
    Tablet(string n,string f,float p,int mDate,int eDate,bool s_level):medicine(n,f,p,mDate,eDate),sucroseLevel(s_level){}
    void display() override{
        cout<<"\n\tTABLET";
        medicine::display();
        cout<<"Sucrose Level: "<<sucroseLevel<<endl;
    }
};
class Capsule : public medicine{
    protected:
    int absPerc;

    public:
    Capsule(string n,string f,float p,int mDate,int eDate,int per):medicine(n,f,p,mDate,eDate),absPerc(per){}
    void display() override{
        cout<<"\n\tCAPSULE";
        medicine::display();
        cout<<"Absorption: "<<absPerc<<"%"<<endl;
    }
};
class Syrup : public medicine{
    protected:
    int teaspoons;

    public:
    Syrup(string n,string f,float p,int mDate,int eDate,int teaspoon):medicine(n,f,p,mDate,eDate),teaspoons(teaspoon){}
    void display() override{
        cout<<"\n\tSYRUP";
        medicine::display();
        cout<<"Teaspoons: "<<teaspoons<<endl;
    }
};
class pharmacist{
    public:
    void searchMedicine();
};
class counter{
    public:
    void searchMedicine();
    void updateRevenue();
};
int main(){
    cout<<"23K2001 - Muzammil\n\n"<<endl;

    Tablet panadol("Panadol Fever Tablet","XXYA4210",50.75,20240101,20240530,1);
    Capsule insulin("Insulin","XZMB3120",30.40,20240220,20240530,80);

    if(panadol==insulin){
        cout<<"Expiring in the same year!"<<endl;
    }
    else
    cout<<"Expiry year different!"<<endl;
    return 0;
}