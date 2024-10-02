#include<iostream>
#include<string>
using namespace std;

typedef struct 
{
   char name[20];
   int  Roll;
   char address[100];

   void getData()
{
  cout<<"Enter name"<<endl;
  fflush(stdin);
  cin.getline(name,20);

  cout<<"Enter Roll"<<endl;
  fflush(stdin);
  cin>>Roll;

  cout<<"Enter Address"<<endl;
  fflush(stdin);
  cin.getline(address,100);
  cout<<endl;
}

void showData()
{
    cout<<"Name     : "<<name<<endl;
    cout<<"Roll     : "<<Roll<<endl;
    cout<<"address  : "<<address<<endl<<endl<<endl;
}
} Student;


int main()
{
   Student S[5];
    
    for(int i=0;i<2;i++)
    S[i].getData();

    for(int i=0;i<2;i++)
     S[i].showData();

    
    return 0;
}