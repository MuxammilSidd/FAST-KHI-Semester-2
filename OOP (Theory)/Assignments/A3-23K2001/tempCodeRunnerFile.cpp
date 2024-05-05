//23K2001 Muzammil Q1
#include<iostream>
#include<windows.h>
using namespace std;
static float revenue = 0;
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
        cout<<"Manufacture (yy/mm/dd): "<<mfDate<<endl;
        cout<<"Expiry (yy/mm/dd): "<<expDate<<endl;
    }

    bool operator ==(medicine &m1){
        if(this->expDate/10000==m1.expDate/10000) //20243001 (yymmdd)
            return 1;
        else
            return 0;
    }

    friend void updateRevenue(medicine &m);
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
    void searchMedicine(medicine *meds[],int n,string f){
        cout<<endl<<"..pharmacist is searching for medicine with formula: '"<<f<<"'"<<endl;
        Sleep(3500);
        int x=1;
        for(int i=0;i<n;i++){
            if(meds[i]->getFormula()==f){
            cout<<endl<<"Medicine found!"<<endl<<"Details: "<<endl;
            meds[i]->display();
            x=0;
            break;
            }
        }
        if(x)
        cout<<"No medicine found with the formula provided!"<<endl;
    }
};
class counter{
    public:
    void searchMedicine(medicine *meds[],int n,string name){
        cout<<endl<<"..counter staff is searching for medicine with name: '"<<name<<"'"<<endl;
        Sleep(3500);
        int x=1;
        for(int i=0;i<n;i++){
            if(meds[i]->getName()==name){
            cout<<endl<<"Medicine found!"<<endl<<"Details: "<<endl;
            meds[i]->display();
            x=0;
            break;
            }
        }
        if(x)
        cout<<"No medicine found with the name provided!"<<endl;
    }
    void updateRevenue(medicine &m){
        revenue+=m.getPrice();
        cout<<endl<<"Payment Authorized!"<<endl;
        cout<<"Total Revenue: "<<revenue<<endl;
    }
};
int main(){
    cout<<"23K2001 - Muzammil"<<endl;
    Tablet brufen("Brufen Tablets","XXYA4210",50.75,20240101,20240530,1);
    Capsule sevenseas("7 Seas Cod","XZMB3120",30.40,20240220,20240519,80);

    brufen.display();
    sevenseas.display();
    if(brufen==sevenseas)
        cout<<"\nExpiring in the same year!"<<endl;
    else
        cout<<"\nExpiry year different!"<<endl;


    pharmacist p;
    counter c;
    medicine *supplies[] = {&brufen,&sevenseas};
    p.searchMedicine(supplies,2,"XZMB3120");
    c.searchMedicine(supplies,2,"Brufen Tablets");
    c.updateRevenue(brufen);
    return 0;
}