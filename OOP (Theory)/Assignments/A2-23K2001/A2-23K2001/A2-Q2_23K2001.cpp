//23K2001 Muzammil Q2
#include<iostream>
using namespace std;

class player{
protected:
int playerid, health;
string playername;

public:
player(int id, string name) : playerid(id), playername(name),health(100){}
void setHealth(int h){
    health += h;
}
int getHealth(){
    return health;
}
bool checkHealth()
{
    if(health<=0)
    {
    cout<<"This player has died."<<endl;
    return false;
    }
    else
    return true;
}
void display(){
    cout<<"\nPlayer Info:"<<endl;
    cout<<"PlayerID: "<<playerid<<endl;
    cout<<"Player Name: "<<playername<<endl;
}
};

class weapon{
protected:
string *weaponlist;
int n;
public:
weapon(string alloted[], int n) : n(n){
    if(n>=5){
        weaponlist = new string[n];
        for(int i=0;i<n;i++)
            weaponlist[i] = alloted[i];
    }
    else{
        cout<<"Weapons list should contain atleast 5 or more weapons!\n";
        cout<<"please allot "<<5-n<<" more weapons to complete 5 weapons: "<<endl;
        weaponlist = new string[5];
        for(int i=0;i<n;i++)
            weaponlist[i] = alloted[i];

        for(int i=n;i<5;i++)
            cin>>weaponlist[i];

        this->n=5;
    }
}
void displayweapons(){
    for(int i=0;i<n;i++)
    cout<<i+1<<". "<<weaponlist[i]<<endl;
}
void use(){
    cout<<"\nSelect a weapon: "<<endl;
    displayweapons();
    int x;
    cin>>x;
    while(x>n || x==0)
    {
        cout<<"Invalid weapon #, select again: ";
        cin>>x;
    }
    cout<<"\nSelected weapon#"<<x<<" - "<<weaponlist[x-1]<<endl;
}
~weapon(){
    delete[] weaponlist;
}
};
class enemy;
class character : public player, public weapon{
protected:
int level, points;
string experience;

public:
character(int id, string name, string char_weapons[], int n) : player(id,name),weapon(char_weapons,n),level(0),points(0),experience("Beginner"){}
void levelUp(){
    level++;
    if(experience=="Beginner")
    experience="Intermedite";
    else if(experience=="Intermedite")
    experience="Advanced";
    else if(experience=="Advanced")
    experience="Expert";
}

void playGame(enemy& e);
void displayStats()
{
    cout<<"\nCharacter stats: "<<endl;
    cout<<"Health: "<<getHealth()<<endl;
    cout<<"Level: "<<level<<endl;
    cout<<"Points: "<<points<<endl;
    cout<<"Experience: "<<experience<<endl;
}
void display(){
    player::display();
    displayStats();
}
};
class enemy : public player,public weapon{
protected:
int damage;

public:
enemy(int id, string name, int d, string en_weapons[], int n) : player(id,name),weapon(en_weapons,n){
    do{
        if(d>0 && d<11){
            damage = d;
            break;
        }
        else{
            cout<<"Enemy damage can be in range 1-10, please enter correctly: ";
            cin>>d;
        }
    }while(1);
}
void attack(character& c){
    if(checkHealth()==false)
    cout<<"Dead players cannot attack!"<<endl;
    else if(c.checkHealth())
    {
        use();
        c.setHealth(-damage);
        cout<<"\nDamage successful!"<<endl;
    }
    else
    cout<<"Cannot attack again!"<<endl;
}
void display(){
    player::display();
    cout<<"\nEnemy stats: "<<endl;
    cout<<"Health: "<<getHealth()<<endl;
    cout<<"Damage: "<<damage<<endl;
}
};

void character :: playGame(enemy& e){
    if(checkHealth()==false)
    cout<<"Dead players cannot attack!"<<endl;
    else if(e.checkHealth())
    {
        use();
        e.setHealth(-5);
        points+=10;
        cout<<"\nAttack successful!"<<endl;
        cout<<"Enemy health: "<<e.getHealth()<<endl;
        levelUp();
        displayStats();
    }
    else
    cout<<"Cannot attack again!"<<endl;
}
int main()
{
    cout<<"23K2001 - Muzammil\n\n"<<endl;
    string myweapons[] = {"m416","g63"};
    string enemyweapons[] = {"ak-47","kar98","rpg"};    

    character muz(232001,"Muzammil",myweapons,2);
    enemy nuer(666420,"Manuel Nuer",10,enemyweapons,3);

    int ch;
    do{
        cout<<"\n1. Attack enemy.\n2. Attack character.\n3. Show character info.\n4. Show enemy info.\n5. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:{
                muz.playGame(nuer);
                break;
            }
            case 2:{
                nuer.attack(muz);
                break;
            }
            case 3:{
                muz.display();
                break;
            }
            case 4:{
                nuer.display();
                break;
            }
            case 5:
                return 0;

            default:
            cout<<"Invalid input, try again!"<<endl;
        }
    } while(ch!=5);
    return 0;
}