#include<iostream>
#include<string>̥
#include<Windows.h>
#include<fstream>
#include<cmath>
#include<ctime>
#include<conio.h>

using namespace std;

void HomePage();

class Admin
{
  string userID;
  string password;

  public:
  void AdminLogin();

  bool verifyAdmin(string UID,string PASSWORD)
  {
     ifstream fin;
     fin.open("Admin_liba.txt",ios::in);
     fin.read((char*)this,sizeof(*this));
     int x=this->userID.compare(UID);
     int y=this->password.compare(PASSWORD);
     if( !x && !y )
     return true;
     else
     return false;
  }

 void StoreAdminData()
  {
    ofstream fout;
    fout.open("Admin_liba.txt",ios::out);
    if(fout)
    {
        fout.write((char*)this,sizeof(*this));
        fout.close();
        cout<<"Admin registered successfully..."<<endl;
        Sleep(2000);
        system("CLS");
    }
    else
    {
        cout<<"File error"<<endl;
        Sleep(2000);
        system("CLS");
    }
  }

  void setID_Pswd()
  {
    cout<<"Enter Admin ID\n";
    cin>>userID;
    cout<<"Enter Admin Password\n";
    fflush(stdin);
    cin>>password;
    StoreAdminData();
  }
  
};

void Admin::AdminLogin()
{
     system("CLS");
     //Title("A D M I N   L O G I N");
      string userID;
      string password;

      cout<<"Enter Admin ID\n";
      cin>>userID;
      cout<<"Enter Admin Password\n";
      cin>>password;
    
     if(verifyAdmin(userID,password))
      {
          cout<<"Login successfull..."<<endl;
          Sleep(2000);
          system("CLS");
      }

      else
      {
          cout<<"Invalid UserId or password"<<endl;
          Sleep(2000);
          system("CLS");
      }
}


void AdminPortal()
{
    ifstream fin;
    Admin A;
    system("CLS");
    //Title("A D M I N   P O R T A L"); 
    fin.open("Admin_liba.txt");

    if(fin)
    {
      A.AdminLogin();
      
      HomePage();
    }
    
    else
       {
        A.setID_Pswd();
        
        AdminPortal();
       }
}


void HomePage()
{
    int choice;
    system("CLS");
    //Title("WELCOME TO MINI LIBRARY MANAGEMENT");
    cout<<"1) Admin Portal\n\n2) Student Portal\n\n3) Exit\n\n";

    cout<<"Enter your choice\n";
    cin>>choice;

    switch(choice)
    {
    case 1: system("CLS");
            AdminPortal();
            break;

    // case 2: system("CLS");
    //         StudentPortal();
    //         break;

    // default: cout<<"Invalid Choice\n";
    //         break;
    
    // case 3:system("CLS");
    //         Sleep(2000);
    //         cout<<"W E L C O M E   A G A I N\n";
    //         exit(0);

   
    }
}

int main()
{
    HomePage();
    return 0;
}