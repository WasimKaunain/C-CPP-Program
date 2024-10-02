#include<iostream>
#include<ctime>
#include<fstream>
#include<stdio.h>
#include<unistd.h>
using namespace std;

struct tm* Time()
{
   time_t t;
   time(&t);
   return(localtime(&t));
}

class Student 
{
    char name[25];
    char add[10];
    char email[25];
    struct tm* profileDate;

    public:
    void setData();
    void showData();
    void storeData();
    void showAllData();
    Student()
    {
       time_t t;
       time(&t);
       profileDate=localtime(&t);
    }

};

void Student::showData()
{
  cout<<"Name             : "<<name<<endl;
  cout<<"Address          : "<<add<<endl;
  cout<<"Email            : "<<email<<endl;
  
  cout<<"Joining Date     : "<<asctime(profileDate)<<endl<<endl<<endl;
}

void Student::showAllData()
{
   ifstream fin;
   fin.open("Nayafile.txt",ios::in);
   
   cout<<"Data is ready to be  read"<<endl;
   fin.read((char*)this,sizeof(*this));
   while(!fin.eof())
   {
    // cout<<"in while loop"<<endl;
     showData();
     sleep(4);
     fin.read((char*)this,sizeof(*this));
   }
   fin.close();
   //cout<<"Out of while loop"<<endl;
}

void Student::storeData()
{
  ofstream fout;
  fout.open("Nayafile.txt",ios::app|ios::binary);
  fout.write((char*)this,sizeof(*this));
  fout.close();

  cout<<endl<<"Data is uploaded..."<<endl;

}

void Student::setData()
{
   cout<<"Enter your name"<<endl;
   fflush(stdin);
   gets(name);
   fflush(stdin);
   cout<<"Enter State"<<endl;
   gets(add);
   fflush(stdin);
   cout<<"Enter Email Id"<<endl;
   cin>>email;
   storeData();
}


int main()
{
    Student s1,s2;
    s1.setData();
    s2.setData();
    s2.showAllData();
    return 0;
}