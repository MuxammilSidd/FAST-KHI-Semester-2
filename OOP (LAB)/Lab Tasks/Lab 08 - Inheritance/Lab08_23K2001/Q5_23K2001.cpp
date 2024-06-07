//23K2001 Q5
#include<iostream>
using namespace std;

class animal{
protected:
int age;
string size;
public:
animal(){
    age = 0;
    size = "";
}
animal(int age,string size):age(age),size(size){}

void setAge(int a)
{
    age = a;
}
void setSize(string s)
{
    size = s;
}
int getAge()
{
    return age;
}
string getSize()
{
    return size;
}
};

class dog : public animal{
private:
string breed;

public:
dog(){
    breed = "";
}
dog(int a,string s,string b):animal(a,s),breed(b){}

void setBreed(string b)
{
    breed = b;
}
string getBreed()
{
    return breed;
}
};

class cat : public animal{
private:
int lives;
public:
cat(){
    lives = 0;
}
cat(int a,string s,int l):animal(a,s),lives(l){}

void setLives(int l)
{
    lives = l;
}
int getLives()
{
    return lives;
}
};

int main()
{
    dog skye;
    dog betsy(2,"XL","Labrador");
    cat timo;
    cat gwen(3,"S",7);

    cout<<"Dog (by default constructor):"<<endl;
    cout<<"Age: "<<skye.getAge()<<endl;
    cout<<"Size: "<<skye.getSize()<<endl;
    cout<<"Breed: "<<skye.getBreed()<<endl;

     cout<<"\nDog (by parameter constructor):"<<endl;
    cout<<"Age: "<<betsy.getAge()<<endl;
    cout<<"Size: "<<betsy.getSize()<<endl;
    cout<<"Breed: "<<betsy.getBreed()<<endl;
    
    cout<<"\nCat (by default constructor):"<<endl;
    cout<<"Age: "<<timo.getAge()<<endl;
    cout<<"Size: "<<timo.getSize()<<endl;
    cout<<"Lives: "<<timo.getLives()<<endl;
    
    cout<<"\nCat (by parameter constructor):"<<endl;
    cout<<"Age: "<<gwen.getAge()<<endl;
    cout<<"Size: "<<gwen.getSize()<<endl;
    cout<<"Lives: "<<gwen.getLives()<<endl;
    return 0;
}