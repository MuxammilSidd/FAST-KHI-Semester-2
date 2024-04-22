//23K2001 Muzammil Q4
#include<iostream>
#include<cstring>
using namespace std;

class post{
protected:
string postID;
int likes,comments,views;

public:
post(string id, int l,int c,int v) : postID(id),likes(l),comments(c),views(v) {}
post(){}
void displayPost()
{
    cout<<"----------------------------------------------"<<endl;
    cout<<"|                                             |"<<endl;
    cout<<"|    .-. . . .-. .-. .-. .-. .-. .-. .  .     |"<<endl;
    cout<<"|     |  |\\| `-.  |  |-| |.. |(  |-| |\\/|     |"<<endl;
    cout<<"|    `-' ' ` `-'  '  ` ' `-' ' ' ` ' '  `     |"<<endl;
    cout<<"|                                             |"<<endl;
    cout<<"     Likes: "<<likes;
    cout<<"   Comments: "<<comments;
    cout<<"   Views: "<<views<<endl;
    cout<<"|                                             |"<<endl;
    cout<<"----------------------------------------------"<<endl;
}
void setLikes(int x) { likes = x; }
void setViews(int x) { views = x; }

int getLikes() { return likes; }
int getViews() { return views; }
int getComments() { return comments; }
string getID() { return postID; }

void addComment(){
    string c;
    cout<<"Type: ";
    cin>>c;
    comments++;
    displayPost();
    cout<<"\nComment added!"<<endl;
}
void likePost(){
    likes++;
    displayPost();
    cout<<"\nLiked!"<<endl;
}
void addView() { views++; }
};

class user{
protected:
string name, email, pass;
bool isEncrypted = false;
int key=0;

public:
void encryptUserpass() {
    if(isEncrypted==false){
        int n = strlen(pass.c_str());
        key = (int)pass[0];
        for(int i=0;pass[i]!='\0';i++)
        {
            for(int j=i+1;pass[j]!='\0';j++) {
                if(pass[j]>key)
                key = pass[j];
            }
        }
        for(int i=0;i<n-1;i++)
            pass[i] = pass[i] + (key/(i+1));
        isEncrypted = true;
    }
    /*My encryption logic is that key holds the greatest Ascii value from a password string, then I add the current Ascii value of a character
    with the key divided by (i+1), where i is the loop counter that iterates equal to length of the password string.*/
    else
    cout<<"\nPassword for this user is already encrypted!"<<endl;
}
string decryptUserpass(){
    if(isEncrypted==true){
        int n = strlen(pass.c_str());
        for(int i=0;i<n-1;i++)
            pass[i] = pass[i] - (key/(i+1));
        isEncrypted = false;
    }
    /*Decryption is simply reversing the statement, I now subtract the key divided by (i+1) from Ascii value 
    of the character, by which I get the original Ascii value of the current character.*/
    else
    cout<<"\nPassword for this user is not encrypted yet!"<<endl;
    return pass;
}

user(string name, string email, string passw) : name(name),email(email),pass(passw) { encryptUserpass(); }

void displayAcc(){
    cout<<"\nName: "<<name<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Password: "<<pass<<endl;
    cout<<"(type 'show' to reveal/type 1 to continue)"<<endl;
    string x;
    cin>>x;
    if(x=="show" ||x=="Show" ||x=="SHOW") {
        cout<<decryptUserpass()<<endl;
        encryptUserpass();
    }
    else if(x!="1")
        cout<<"Invalid!"<<endl;
}
void likePost(post *p) { p->likePost(); }
void addComment(post *p) { p->addComment(); }

string getName() { return name; }
};

class regular : public user{
private: 
static const int MAX_Feed = 10;
static int n;
post *forRegular[5];

public:
regular(string name, string email, string pass) : user(name,email,pass) {
    for(int i =0;i<5;i++)
    forRegular[i] = nullptr;
}
void addtoFeed(post *p) {
    if(n<MAX_Feed){
        int f=0;
        for(int i=0;i<5;i++)
        {
            if(forRegular[i]==nullptr)
            {
                f=1;
                forRegular[i] = p;
                n++;
                cout<<"\nPosted!"<<endl;
                break;
            }
        }
        if(f==0)
        cout<<"\nSorry! Regular users can only post 5 posts."<<endl;
    }
    else
    cout<<"\nMax (10) posts have been added to feed. Cannot add more"<<endl;
}
void viewFeed(){
    int f=0;
    cout<<"Name: "<<name<<"\tEmail: "<<email<<endl;
    for(int i=0;i<5;i++)
    {
        if(forRegular[i]!=nullptr)
        {
            f=1;
            forRegular[i]->addView();
            forRegular[i]->displayPost();
        }
    }
    if(f==0)
    cout<<"\nNo posts to display, please add some first!"<<endl;
}
};
int regular :: n =0;

class business : public user{
private: 
int n=0;

public:
business(string name, string email, string pass) : user(name,email,pass){}
void promotePost(post *p){
    if(n<10)
    {
        p->setLikes(p->getLikes()*2);
        p->setViews(p->getViews()*3);
        cout<<"\nPost promotion successful!"<<endl;
        p->displayPost();
        n++;
    }
    else
    cout<<"\nExceeded promotion limit for Business User. (Max 10)"<<endl;
}
};

int main()
{
    cout<<"23K2001 - Muzammil\n\n"<<endl;
    cout<<"\t****WELCOME TO INSTAGRAM LITE ULTRA****\n"<<endl;
    regular muzammil("Muzammil Siddiqui","k232001@nu.edu.pk","abcdef");
    regular qasim("Qasim Zaidi","qzaidi@gmail.com","mypassword");
    regular azam("Azam Khan","azamkh2@gmail.com","1234");
    post p[] = {post("20240328",20,5,85),post("20240106",100,18,400),post("20240220",150,20,215),post("20240305",38,2,190),
    post("20240321",95,12,390),post("20240330",19,1,80),post("20240215",149,12,490),post("20240224",122,10,590)};

    business subhan("Subhan Ali","alisubhan@yahoo.com","qwerty");
    business kaleem("Kaleem Ahmed","kaleem@hotmail.com","fastuni");

    int ch;
    do{
        cout<<"\n 1. View account details\n 2. View feed\n 3. Add to feed";
        cout<<"\n 4. Promote post (business users only)\n 5. Like post\n 6. Add comment\n 7. Exit"<<endl;
        cin>>ch;
        switch(ch) {
            case 1:{
                cout<<"\nGet Account Details for: "<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<qasim.getName()<<endl;
                cout<<"3. "<<azam.getName()<<endl;
                cout<<"4. "<<subhan.getName()<<endl;
                cout<<"5. "<<kaleem.getName()<<endl;
                int x;
                cin>>x;
                x == 1 ? muzammil.displayAcc() : x==2 ? qasim.displayAcc() : x==3 ? azam.displayAcc() : x==4? subhan.displayAcc() : kaleem.displayAcc();
                break;
            }
            case 2:{
                cout<<"\nView feed for: "<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<qasim.getName()<<endl;
                cout<<"3. "<<azam.getName()<<endl;
                int x;
                cin>>x;
                if(x==1)
                muzammil.viewFeed();
                else if(x==2)
                qasim.viewFeed();
                else if(x==3)
                azam.viewFeed();
                else
                cout<<"Invalid!"<<endl;
                break;
            }
            case 3:{
                cout<<"\nAdd to feed for: "<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<qasim.getName()<<endl;
                cout<<"3. "<<azam.getName()<<endl;
                int x,s;
                cin>>x;
                cout<<"Select a post: "<<endl;
                for(int i=0;i<8;i++)
                    cout<<i+1<<". "<<p[i].getID()<<endl;
                cin>>s;
                if(s<=0 || s>8)
                cout<<"Invalid choice!"<<endl;
                else if(x==1)
                muzammil.addtoFeed(&p[s-1]);
                else if(x==2)
                qasim.addtoFeed(&p[s-1]);
                else if(x==3)
                azam.addtoFeed(&p[s-1]);
                else
                cout<<"Invalid!"<<endl;
                break;
            }
            case 4:{
                cout<<"\nPromote post for: "<<endl;
                cout<<"1. "<<subhan.getName()<<endl;
                cout<<"2. "<<kaleem.getName()<<endl;
                int x,s;
                cin>>x;
                cout<<"Select a post: "<<endl;
                for(int i=0;i<8;i++)
                    cout<<i+1<<". "<<p[i].getID()<<endl;
                cin>>s;
                if(s<=0 || s>8)
                cout<<"Invalid choice!"<<endl;
                else if(x==1)
                subhan.promotePost(&p[s-1]);
                else if(x==2)
                kaleem.promotePost(&p[s-1]);
                else
                cout<<"Invalid!"<<endl;
                break;
                /*Since objects Muzammil, Qasim & Azam are regular users so not mentioned here 
                as muzammil.promotePost(&p[s-1]) & qasim.promotePost(&p[s-1]) etc will not work.*/
            }
            case 5:{
                cout<<"\nSelect user to like post: "<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<qasim.getName()<<endl;
                cout<<"3. "<<azam.getName()<<endl;
                cout<<"4. "<<subhan.getName()<<endl;
                cout<<"5. "<<kaleem.getName()<<endl;
                int x,s;
                cin>>x;
                cout<<"Select a post: "<<endl;
                for(int i=0;i<8;i++)
                    cout<<i+1<<". "<<p[i].getID()<<endl;
                cin>>s;
                if(s<=0 || s>8)
                cout<<"Invalid choice!"<<endl;
                else
                x == 1 ? muzammil.likePost(&p[s-1]) : x==2 ? qasim.likePost(&p[s-1]) : x==3 ? azam.likePost(&p[s-1]) : x==4? subhan.likePost(&p[s-1]) : kaleem.likePost(&p[s-1]);
                break;
            }
            case 6:{
                cout<<"\nSelect user to comment on post: "<<endl;
                cout<<"1. "<<muzammil.getName()<<endl;
                cout<<"2. "<<qasim.getName()<<endl;
                cout<<"3. "<<azam.getName()<<endl;
                cout<<"4. "<<subhan.getName()<<endl;
                cout<<"5. "<<kaleem.getName()<<endl;
                int x,s;
                cin>>x;
                cout<<"Select a post: "<<endl;
                for(int i=0;i<8;i++)
                    cout<<i+1<<". "<<p[i].getID()<<endl;
                cin>>s;
                if(s<=0 || s>8)
                cout<<"Invalid choice!"<<endl;
                else
                x == 1 ? muzammil.addComment(&p[s-1]) : x==2 ? qasim.addComment(&p[s-1]) : x==3 ? azam.addComment(&p[s-1]) : x==4? subhan.addComment(&p[s-1]) : kaleem.addComment(&p[s-1]);
                break;
            }
            case 7:
            return 0;
            default:
            cout<<"Invalid choice!"<<endl;
        }
    } while(ch!=7);
    return 0;
}