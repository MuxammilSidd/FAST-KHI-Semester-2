#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
       class Student{
       	 public:
              int roll;
              char name[25];
              float marks;		
            void getdata()
              {
                      cout<<"\n\nEnter Roll : ";
                      cin>>roll;
                      cout<<"\nEnter Name : ";
                      cin>>name;
                      cout<<"\nEnter Marks : ";
                      cin>>marks;
              } 	 
		   	void fetchdata(){
			            cout<<"\n\t"<<roll<<"\t"<<name<<"\t"<<marks;
			  }
             
			void AddRecord()
              {
                      fstream f;
                      Student Stu;
                      f.open("Student.txt",ios::app|ios::binary);
                      Stu.getdata();
                      f.write( (char *) &Stu, sizeof(Stu) );
                      f.close();
              }
              void Display()
              {
                      fstream f;
                      Student Stu;
                      f.open("Student.txt",ios::in|ios::binary);
                      cout<<"\n\tRoll\tName\tMarks\n";
                      while(!f.eof()) {
                      	f.read((char*)&Stu,sizeof(Stu));
                      		Stu.fetchdata();
					  }
                      f.close();
              }
			  void Search(int id)
              {
                      fstream f;
                      Student Stu;
                      int count=0;
                      f.open("Student.txt",ios::in|ios::binary);
                      cout<<"\n\tRoll\tName\tMarks\n";
                      while( (f.read((char*)&Stu,sizeof(Stu))) != NULL ){
                      		if(Stu.roll==id){
                      			cout<<"Data Found";
                      			Stu.fetchdata();
                      			count++;
							  }
							  if(count==0)
							  cout<<"Data not Found";
					  }
                      	
                      		
                      f.close();
              }
			  };
              
              
              int  main()
       {
              Student S;
              char ch='n';
              do
              {
                      S.AddRecord();
                      cout<<"\n\nDo you want to add another data (y/n) : ";
                      ch = getche();

              } while(ch=='y' || ch=='Y');

              cout<<"\nData written successfully...";
              
              S.Display();
              S.Search(103);
       }

