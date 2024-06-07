//23k2001 Q2
#include<iostream>
using namespace std;

class user;
class message{
protected:
string m;
public:
friend void sendMessage(user &rcvr);
void type(){
    cin>>m;
}
string getmsg(){return m;
}
};

class user{
    protected:
    string name;
    message *userlist; //the messages that are received by a user
    int n;

    public:
    user(string name):name(name){
        userlist = nullptr;
	    n=0;}
    void display(){
        cout<<"\n"<<name<<"'s messages log: "<<endl;
    	for(int i=0;i<n;i++)
    		cout<<i+1<<". "<<userlist[i].getmsg()<<endl;
	}
    void sendMessage(user &rcvr){
        message text;
        cout<<"Input messsage to send: "<<endl;
        text.type();
        if(n==0 && userlist==nullptr){
            n++;
            rcvr.userlist = new message[n];
            rcvr.userlist[n-1]=text;
            rcvr.n=1;
        }
        else{
            message *temp = new message[rcvr.n+1];
            for(int i=0;i<rcvr.n;i++)
            temp[i] = rcvr.userlist[i];

            temp[rcvr.n] = text;
            delete[] rcvr.userlist;
            rcvr.userlist = temp;
            rcvr.n++;
        }
            cout<<name<<" messaged "<<rcvr.name<<"!"<<endl;
    }
    ~user(){delete[] userlist;}
};
int main(){
    user sender("Muzammil"),receiver("Qasim");

    sender.sendMessage(receiver);
    receiver.display();
    
    sender.sendMessage(receiver);
    receiver.display();

    sender.sendMessage(receiver);
    receiver.display();
    return 0;
}
