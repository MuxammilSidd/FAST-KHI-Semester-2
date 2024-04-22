//23k2001 Q1
#include<iostream>
using namespace std;
class mediafile{
private:
string name;
float size;
public:
mediafile(string name,float size):name(name),size(size){}
string getName(){return name;}
float getSize(){return size;}
};

class img:public mediafile{
private:
string ext_name;
public:
friend class mediaconverter;
img(string n,float s,string e):mediafile(n,s),ext_name(e){}
void display(){
    cout<<"\nfilename: "<<getName()<<endl;
    cout<<"size: "<<getSize()<<endl;
    cout<<"ext: "<<ext_name<<endl;
}
};

class audio:public mediafile{
private:
string ext_name;
public:
audio(string n,float s,string e):mediafile(n,s),ext_name(e){}
friend class mediaconverter;
void display(){
    cout<<"\nfilename: "<<getName()<<endl;
    cout<<"size: "<<getSize()<<endl;
    cout<<"ext: "<<ext_name<<endl;
}
};

class vid:public mediafile{
private:
string ext_name;
public:
vid(string n,float s,string e):mediafile(n,s),ext_name(e){}
friend class mediaconverter;
void display(){
    cout<<"\nfilename: "<<getName()<<endl;
    cout<<"size: "<<getSize()<<endl;
    cout<<"ext: "<<ext_name<<endl;
}
};

class mediaconverter{
public:
void changeExt(img &i){
    string e;
    cout<<"Input a new extension for this image: ";
    cin>>e;
    i.ext_name = e;
}
void changeExt(audio &a){
    string e;
    cout<<"Input a new extension for this audio: ";
    cin>>e;
    a.ext_name = e;
}
void changeExt(vid &v){
    string e;
    cout<<"Input a new extension for this video: ";
    cin>>e;
    v.ext_name = e;
}
};
int main(){
    img one("timetable",450.75,"heic");
    audio two("draft",30.75,"mp3");
    vid three("tutorial",980.10,"mp4");
    
    one.display();
    two.display();
    three.display();

    mediaconverter convert;
    cout<<"\nImage:"<<endl;
    convert.changeExt(one);
    cout<<"\nAudio:"<<endl;
    convert.changeExt(two);
    cout<<"\nVideo:"<<endl;
    convert.changeExt(three);
    
    one.display();
    two.display();
    three.display();
    return 0;
}
