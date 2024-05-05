//23K2001 Muzammil Q2
#include<iostream>
using namespace std;
template <class TN> class Pet{
    protected:
    TN name;
    int age;

    public:
    Pet(TN name,int age):name(name),age(age){}
    virtual void makeSound()=0;
    void display(){
        cout<<"\nName: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class Cat : public Pet<string>{
    public:
    Cat(string n,int a):Pet(n,a){}
    void makeSound(){ cout<<"\nmeowww"<<endl; }
};
class Dog : public Pet<string>{
    public:
    Dog(string n,int a):Pet(n,a){}
    void makeSound(){ cout<<"\nwoooof"<<endl; }
};
class Bird : public Pet<string>{
    public:
    Bird(string n,int a):Pet(n,a){}
    void makeSound(){ cout<<"\nchiiirppp"<<endl; }
};
int main(){
    cout<<"23K2001 - Muzammil"<<endl;
    
    Cat c1("Suki", 3);
    Dog d1("Betsy", 4);
    Bird b1("Hans", 1);

    Pet<string> *pets[3] = {&c1, &d1,&b1};
    for (int i = 0; i<3; i++){
        pets[i]->display();
        pets[i]->makeSound();
    }
    return 0;
}