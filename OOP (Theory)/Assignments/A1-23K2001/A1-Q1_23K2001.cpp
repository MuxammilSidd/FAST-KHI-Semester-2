//23K2001 Q1
#include<iostream>
using namespace std;

class pet{
    private:
    string healthstatus;
    int hungrylevel;
    int happylevel;
    char skills[5][20];
    string species;
    int n;

    public:
    void displayPetDetails()
    {
        cout<<"\nDetails: "<<endl;
        cout<<"Species: "<<species<<endl;
        cout<<"Happiness level: "<<happylevel<<endl;
        cout<<"Hunger level: "<<hungrylevel<<endl;
        cout<<"Health status: "<<healthstatus<<endl;
        cout<<"Special skills: "<<endl;
        int i;
        for ( i = 0; i < n; ++i)
        {
            cout << skills[i]<<endl;
        }
    }
    void updateHappiness(int c=1)
    {
        if(happylevel<10)
        {
            happylevel+=c;
            cout<<"\nHappiness level updated!"<<endl;
        }
        else if(happylevel>10)
        happylevel = 10;
    }
    void updateHunger(int c)
    {
        if(c==1)
        {
            hungrylevel--;
            if(hungrylevel<0)
            hungrylevel = 0;

            cout<<"\nHungry level decreased!"<<endl;
            updateHappiness();
        }
        else if(c==0)
        {
            hungrylevel++;
            cout<<"\nHungry level increased!"<<endl;

            if(hungrylevel>0)
            updateHappiness(-1);
        
        }
    }
    void updateHealth(int c)
    {
        if(c==0)
        healthstatus = "Sick";
        else if(c==1)
        healthstatus = "Healthy";

        cout<<"\nHealth status updated!"<<endl;
    }
    pet()
    {
        string health,type;
        int hungry;
        int happy;
        
        cout<<"\nInitilaize values for the pet: \n"<<endl;
        cout<<"Input species name: ";
        cin>>species;
        cout<<"Input health status (Healthy/Sick): ";
        cin>>health;
        healthstatus = health;
        cout<<"Input hungry level: ";
        cin>>hungry;
        hungrylevel = hungry;
        cout<<"Input happiness level: ";
        cin>>happy;
        happylevel = happy;
        cout<<"How many skills (max 5): ";
        cin>>n;
        cout<<"Input pet's "<<n<<" skills: "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>skills[i];
        }
    }
};

class adopter{
    private: 
    string adopterName;
    int mobileNum;
    int n=0;
    pet** adoptedRecords;

    public:
    adopter(string name,int num)
    {
        adopterName = name;
        mobileNum = num;
        adoptedRecords = new pet*[5];
    }
    void adoptPet(pet* p)
    {
        if(n < 5)
        {
            adoptedRecords[n] = p; 
            n++;
            cout<<"\nPet adopted successfully!"<<endl;
        }
        else
            cout << "Sorry! This adopter cannot adopt more than 5 pets." << endl;
    }
    void returnPet()
    {
        int r,i;
        cout<<"\nInput which pet to return (0-"<<n-1<<")"<<endl;
        cin>>r;
        if (r>=0 && r<n) 
        {
            delete adoptedRecords[r];
            for(i =r;i<n-1;i++) 
            {
                adoptedRecords[i] = adoptedRecords[i+1];
            }
            n--;
            cout<<"\n\t***Returned pet***"<<endl;
        } 
        else 
        {
            cout<<"Failed to return pet. Please enter correct #" <<endl;
        }
    }
    void displayAdopted()
    {
        int i;
        cout<<"\n"<<n<<" pets adopted by: "<<adopterName<<endl;
        for (i=0;i<n;i++)
        {
            cout<<"\nPet#"<<i+1<<": "<<endl;
            adoptedRecords[i]->displayPetDetails();
        }
    }
    ~adopter() 
    {
        int i;
        for (i= 0;i<n;i++) 
        {
            delete adoptedRecords[i];
        }
        delete[] adoptedRecords;
    }
    string getName()
    {
        return adopterName;
    }
};
int main()
{
    cout<<"23K2001 - Muzammil\n"<<endl;
    cout<<"\t\t***Welcome to Gulshan Virtual Pet Adoption System***"<<endl;
    pet betsy;
    pet cheems;
    pet tom;
    pet linda;

    adopter muzammil("Muzammil Siddiqui",9230012);
    adopter jazib("Jazib Jamal",9230064);

    int ch;
    do{
        cout<<"\n1. Display adopted pets"<<endl;
        cout<<"2. Adopt a pet"<<endl;
        cout<<"3. Return a pet"<<endl;
        cout<<"4. Update Hunger"<<endl;
        cout<<"5. Update Happiness"<<endl;
        cout<<"6. Update Health"<<endl;
        cout<<"7. Display pet details"<<endl;
        cout<<"8. Exit"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                cout<<"\nOur users:"<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<jazib.getName()<<endl;
                cout<<"Display pets of ? ";
                int u;
                cin>>u;
                if(u==1)
                muzammil.displayAdopted();
                else if(u==2)
                jazib.displayAdopted();

                break;
            }
            case 2:
            {
                cout<<"\nOur users:"<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<jazib.getName()<<endl;
                cout<<"Which user wants to adopt pet ? ";
                int u;
                cin>>u;
                cout<<"Pets:\n1. Betsy\n2. Cheems\n3. Tom\n4. Linda"<<endl;
                cout<<"Which pet ? ";
                int p;
                cin>>p;

                if(u==1)
                {
                    if(p==1)
                    muzammil.adoptPet(&betsy);
                    else if(p==2)
                    muzammil.adoptPet(&cheems);
                    else if(p==3)
                    muzammil.adoptPet(&tom);
                    else if(p==4)
                    muzammil.adoptPet(&linda);
                }
                else if(u==2)
                {
                    if(p==1)
                    jazib.adoptPet(&betsy);
                    else if(p==2)
                    jazib.adoptPet(&cheems);
                    else if(p==3)
                    jazib.adoptPet(&tom);
                    else if(p==4)
                    jazib.adoptPet(&linda);
                }

                break;
            }
            case 3:
            {
                cout<<"\nOur users:"<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<jazib.getName()<<endl;
                cout<<"Return pet of ? ";
                int u;
                cin>>u;
                if(u==1)
                {
                    muzammil.returnPet();
                }
                else if(u==2)
                {
                    jazib.returnPet();
                }
                break;
            }
            case 4:
            {
                cout<<"Pets:\n1. Betsy\n2. Cheems\n3. Tom\n4. Linda"<<endl;
                cout<<"Update hunger of which pet ? ";
                int p,a;
                cin>>p;
                cout<<"Did you exhaust(0) the pet or feed(1) it ? ";
                cin>>a;
                if(p==1)
                {
                    if(a==1)
                    betsy.updateHunger(1);
                    else
                    betsy.updateHunger(0);
                }
                else if(p==2)
                {
                    if(a==1)
                    cheems.updateHunger(1);
                    else
                    cheems.updateHunger(0);
                }
                else if(p==3)
                {
                    if(a==1)
                    tom.updateHunger(1);
                    else
                    tom.updateHunger(0);
                }
                else if(p==4)
                {
                    if(a==1)
                    linda.updateHunger(1);
                    else
                    linda.updateHunger(0);
                }
                break;
            }
            case 5:
            {
                cout<<"Pets:\n1. Betsy\n2. Cheems\n3. Tom\n4. Linda"<<endl;
                cout<<"Update happiness of which pet ? ";
                int p;
                cin>>p;
                if(p==1)
                betsy.updateHappiness();
                else if(p==2)
                cheems.updateHappiness();
                else if(p==3)
                tom.updateHappiness();
                else if(p==4)
                linda.updateHappiness();
                break;
            }
            case 6:
            {
                cout<<"Pets:\n1. Betsy\n2. Cheems\n3. Tom\n4. Linda"<<endl;
                cout<<"Update health of which pet ? ";
                int p,h;
                cin>>p;
                cout<<"Sick(0) / Healthy(1) ? ";
                cin>>h;
                if(p==1)
                {
                    if(h==1)
                    betsy.updateHealth(1);
                    else
                    betsy.updateHealth(0);
                }
                else if(p==2)
                {
                    if(h==1)
                    cheems.updateHealth(1);
                    else
                    cheems.updateHealth(0);
                }
                else if(p==3)
                {
                    if(h==1)
                    tom.updateHealth(1);
                    else
                    tom.updateHealth(0);
                }
                else if(p==4)
                {
                    if(h==1)
                    linda.updateHealth(1);
                    else
                    linda.updateHealth(0);
                }
                break;
            }
            case 7:
            {
                cout<<"Pets:\n1. Betsy\n2. Cheems\n3. Tom\n4. Linda"<<endl;
                cout<<"Display details of which pet ? ";
                int p;
                cin>>p;
                if(p==1)
                betsy.displayPetDetails();
                else if(p==2)
                cheems.displayPetDetails();
                else if(p==3)
                tom.displayPetDetails();
                else if(p==4)
                linda.displayPetDetails();
                break;
            }
            case 8:
            {
                return 0;
            }
            default:
            cout<<"Invalid choice!"<<endl;
        }
    } while(ch!=8);

    return 0;
}