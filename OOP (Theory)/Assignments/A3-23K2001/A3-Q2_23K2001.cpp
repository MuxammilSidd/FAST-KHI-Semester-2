//23K2001 Muzammil Q2
#include<iostream>
using namespace std;
template <class T> class Pet{
    protected:
    string name;
    int age;

    public:
    Pet(string name,int age):name(name),age(age){}
    virtual void makeSound()=0;
    void display(){
        cout<<"\nName: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
template <class T> class Cat : public Pet<T>{
    public:
    Cat(string n,int a):Pet<T>(n,a){}
    void makeSound(){ cout<<"\nmeowww"<<endl; }
};
template <class T> class Dog : public Pet<T>{
    public:
    Dog(string n,int a):Pet<T>(n,a){}
    void makeSound(){ cout<<"\nwoooof"<<endl; }
};
template <class T> class Bird : public Pet<T>{
    public:
    Bird(string n,int a):Pet<T>(n,a){}
    void makeSound(){ cout<<"\nchiiirppp"<<endl; }
};
int main(){
    cout<<"23K2001 - Muzammil"<<endl;
    
    Cat<int> c1("Whiskers", 3);
    Dog<int> d1("Betsy", 4);
    Bird<int> b1("Hans", 1);

    Pet<int>* pets[3] = {&c1, &d1,&b1};

    for (int i = 0; i<3; i++){
        pets[i]->display();
        pets[i]->makeSound();
    }

    return 0;
}