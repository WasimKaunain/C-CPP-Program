#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <cmath>
#include <ctime>
#include <conio.h>

using namespace std;

char* Password();
void Line()
{
  for(int i=0;i<81;i++)
  cout<<"- ";
}

struct tm* Time()
{
   time_t t;
   time(&t);
   return(localtime(&t));
}



void Message(string MESSEGE)
{
  for(int i=0;i<MESSEGE.length();i++)
  {
    cout<<MESSEGE[i];
    Sleep(50);
  }
}

class Book
{
char BookName[25];
char BookAuthor[25];
char BookGenre[15];
char BookID[6];
int  BookPrice;



public:
string TIME;
void SetBookData();
bool StoreBookData();
void SearchBookData();
void ShowBookData();
void DeleteBookData();
void ListBookData();
void GenerateToken(int,int,int);

};

class Student
{
  char name[25];
  char DOB[10];
  char gender[6];
  char mobile[11];
  char EmailID[30];
  char Student_Pswd[20];
  Book BookRecord;
  bool BorrowedStatus;
  string PROFILE_TIME;
  struct tm* BorrowedTime;
  string BORROWED_TIME;


  public:
  
  Student()
  {
    BorrowedStatus=false;
    name[25]='\0';
    DOB[10]='\0';
    gender[6]='\0';
    EmailID[30]='\0';
    Student_Pswd[20]='\0';
   /* BorrowedTime->tm_year=0;
    BorrowedTime->tm_mday=0;
    BorrowedTime->tm_mon=0;
    BorrowedTime->tm_hour=0;
    BorrowedTime->tm_min=0;
    BorrowedTime->tm_sec=0;
    BorrowedTime->tm_wday=0;
    BorrowedTime->tm_yday=0;*/
  }

  void GetData();
  void ViewProfile();
  bool StoreStudentData();
  void ShowStudentData(Book);
  bool EmailVerifier(string);
  bool PasswordVerifier(string);
  bool GenderVerifier(string);
  bool MobileVerifier(string);
  bool DOBVerifier(string);
  void StudentMenu();
  void BorrowBook();
  void ReturnBook();
  void DeleteProfile();
  void EditProfile();
  void Login();
  void Signup();
  void DeleteStudentData();
  void SearchStudentData();
  void ListStudentData();
  void UpdateBookRecord(Book );
  void ResetBookRecord();
  
  string charToString(char* a,int size)
    {
       int i;
       string s="";
       for(i=0;i<size;i++)
       {
         s=s+a[i];
       }
       return s;
    }

};

class Admin
{
  char userID[20];
  char password[20];

  public:
  bool verifyAdmin(char UID[],char PASSWORD[])
  {
     ifstream fin;
     fin.open("Admin_lib.dat",ios::in);
     fin.read((char*)this,sizeof(*this));
     if(!strcmp(this->userID,UID) && !strcmp(this->password,PASSWORD))
     return true;
     else
     return false;
  }

 void StoreAdminData()
  {
    ofstream fout;
    fout.open("Admin_lib.dat",ios::out);
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
  void AdminMenu();
  void AdminLogin();
};

void HomePage();
void StudentPortal();

int x_coord(string s)
{

   return(81-(s.length())/2);
}

void gotoxy(short int x,short int y)
{
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void Title(string title)
{
    gotoxy(x_coord(title),2);
    cout<<title;
    gotoxy(138,2);
    cout<<asctime(Time());
    gotoxy(0,3);
for(int i=0;i<162;i++)
    cout<<"+";
gotoxy(0,5);
}

void Book::ShowBookData()
{

  cout<<"Book Name        : "<<BookName<<endl;
  cout<<"Book Genre       : "<<BookGenre<<endl;
  cout<<"Book Author      : "<<BookAuthor<<endl;          
  cout<<"Book ID          : "<<BookID<<endl;
  cout<<"Book Price       : "<<BookPrice<<endl;
  //cout<<"Added On         : "<<TIME<<endl;
  Line();
  cout<<endl<<endl;
}


void Book::ListBookData()
{
   ifstream fin;
   Student S;
   Admin A;


   system("CLS");
   Title("L I S T   O F   B  O O K S");
   fin.open("Bookdata.dat",ios::in);
   if(fin)
   {
     fin.read((char*)this,sizeof(*this));
     while(!fin.eof())
       {
         ShowBookData();
         fflush(stdout); 
         fin.read((char*)this,sizeof(*this));
       }
      fin.close(); 
   }

   
   else
   {
     cout<<"bookdata.dat file missing..."<<endl;
     Sleep(2000);
     system("CLS");
     
   }
}

void Book::DeleteBookData()
{
  int choice,flag=0;
  fstream fin;
  fstream fout;
  Admin A;
  char value[25];
  
  system("CLS");
  Title("D E L E T E   B O O K");
  
  cout<<"Delete Book by :"<<endl<<endl;
  cout<<"1) Book Name\t\t\t2) Book Author\t\t\t3) Book ID"<<endl;
  fflush(stdin);
  cin>>choice;

  switch(choice)
    {
      case 1: cout<<"Enter Book Name"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Bookdata.dat",ios::in);
              if(fin)
                {
                  fout.open("Tempfile.dat",ios::out|ios::app|ios::binary);
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                    {
                     if(strcmpi(value,BookName))
                      fout.write((char*)this,sizeof(*this));
                     else
                      flag++;
                     fin.read((char*)this,sizeof(*this));
                    }
                    fout.close();
                    fin.close();

                    if(flag==0)
                     {
                       cout<<"Record not found"<<endl;
                       Sleep(2000);
                       system("CLS");
                     }
                    else
                     {
                       cout<<flag<<" record(s) were deleted with the same Book name"<<endl;
                       Sleep(3000);
                       system("CLS");
                     }
                      remove("Bookdata.dat");
                      rename("Tempfile.dat","Bookdata.dat");
                }

              else
                {
                  cout<<"Bookdata.dat not opened..."<<endl;
                  Sleep(3000);
                  system("CLS");
                }
              break;

      case 2: cout<<"Enter Book's Author Name"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Bookdata.dat",ios::in);
              if(fin)
                {
                  fout.open("Tempfile.dat",ios::out|ios::app|ios::binary);
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                    {
                     if(strcmpi(value,BookAuthor))
                      fout.write((char*)this,sizeof(*this));
                     else
                      flag++;
                     fin.read((char*)this,sizeof(*this));
                    }
                    fout.close();
                    fin.close();

                    if(flag==0)
                     {
                       cout<<"Record not found"<<endl;
                       Sleep(2000);
                       system("CLS");
                     }
                    else
                     {
                       cout<<flag<<" record(s) were deleted with the same Book Author Name"<<endl;
                       Sleep(3000);
                       system("CLS");
                     }
                      remove("Bookdata.dat");
                      rename("Tempfile.dat","Bookdata.dat");
                }

              else
                {
                  cout<<"Bookdata.dat not opened..."<<endl;
                  Sleep(3000);
                  system("CLS");
                }
              break;

      case 3: cout<<"Enter Book ID"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Bookdata.dat",ios::in);
              if(fin)
                {
                  fout.open("Tempfile.dat",ios::out|ios::app|ios::binary);
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                    {
                     if(strcmpi(value,BookID))
                      fout.write((char*)this,sizeof(*this));
                     else
                      flag++;
                     fin.read((char*)this,sizeof(*this));
                    }
                    fout.close();
                    fin.close();

                    if(flag==0)
                     {
                       cout<<"Record not found"<<endl;
                       Sleep(2000);
                       system("CLS");
                     }
                    else
                     {
                       cout<<flag<<" record(s) were deleted with the same Book ID"<<endl;
                       Sleep(3000);
                       system("CLS");
                     }
                      remove("Bookdata.dat");
                      rename("Tempfile.dat","Bookdata.dat");
                }

              else
                {
                  cout<<"Bookdata.dat not opened..."<<endl;
                  Sleep(3000);
                  system("CLS");
                }
              break;
       
      Default : cout<<"Invalid Choice"<<endl;
                Sleep(2000);
                system("CLS");
    }
 
}

void Book::GenerateToken(int value,int day,int penalty)
{
  system("CLS");
  Title("B O O K    T O K E N");
  ShowBookData();

  cout<<"Token no. : "<<rand()<<endl;
  cout<<"Time      : "<<asctime(Time())<<endl<<endl;
  if(value==1)
  {
  cout<<"1) Print this Token for further use."<<endl;
  cout<<"2) Using this Token You can borrow this Book  Library."<<endl;
  cout<<"3) One should have to return the borrowed book within 30 days."<<endl;
  cout<<"4) After 30 days, Late fine will be charged for each book on account of 2 Rupee per day."<<endl;
  cout<<"5) Only the borrower will responsible in case of damage or stolen of Books and he will have to pay the amount equal to the price of book."<<endl;
  cout<<endl<<"\t\t\t\t\t\t  T H A N K   Y O U"<<endl;
  }

  if(value==2)
  {
  cout<<"You are "<<day<<" late in returning this book"<<endl;
  cout<<"Penalty of Rs."<<penalty<<" is charged on you"<<endl;
  cout<<"Kindly submit this Book ASAP along with the Penalty Charges"<<endl<<endl;
  cout<<"1) Print this Token for further use."<<endl;
  cout<<"2) Using this Token You can Return this Book to Library."<<endl;
  cout<<"3) One should have to return the borrowed book within 30 Days."<<endl;
  cout<<"4) After 30 Days, Late fine will be charged for each book on account of 2 Rupee per day."<<endl;
  cout<<"5) Only the borrower will responsible in case of damage or stolen of Books and he will have to pay the amount equal to the price of book."<<endl;
  cout<<endl<<"\t\t\t\t\t\t  T H A N K   Y O U"<<endl;
  }

  cout<<endl<<endl<<"Press 0 to go to Student Menu"<<endl;
  fflush(stdin);
  cin.get();
}


void Book::SearchBookData()
{
  int choice,flag=0;
  fstream fin;
  char value[25];



  system("CLS");
  Title("S E A R C H   B O O K");
  
  cout<<"Search Book by :"<<endl<<endl;
  cout<<"1) Book Name\t\t\t2) Book Author\t\t\t3) Book ID"<<endl;
  fflush(stdin);
  cin>>choice;

  switch(choice)
    {
      case 1: cout<<"Enter Book Name"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Bookdata.dat",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                      {
                         if(!strcmpi(value,BookName))
                         {
                          ShowBookData();
                          flag++;
                          break;
                         }
                         fin.read((char*)this,sizeof(*this));
                      }
                      fin.close();
                      if(flag==0)
                       {
                         fflush(stdin);
                         cout<<"Record not found"<<endl;
                         Sleep(2000);
                         system("CLS");
                       }
                  }

              else
                {
                  cout<<"Bookdata.dat not opened..."<<endl;
                  Sleep(3000);
                  system("CLS");
                }
              break;

      case 2: cout<<"Enter Book's Author Name"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Bookdata.dat",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                      {
                        if(!strcmpi(value,BookAuthor))
                        {
                         ShowBookData();
                         flag++;
                         break;
                        }
                        fin.read((char*)this,sizeof(*this));
                      }
                      fin.close();
                      if(flag==0)
                      {
                        cout<<"Record not found"<<endl;
                        Sleep(2000);
                        system("CLS");
                      }
                }

              else
                {
                  cout<<"Bookdata.dat not opened..."<<endl;
                  Sleep(3000);
                  system("CLS");
                }
              break;

      case 3: cout<<"Enter Book ID"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Bookdata.dat",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                    {
                        if(!strcmpi(value,BookID))
                        {
                         ShowBookData();
                         flag++;
                         break;
                        }
                        fin.read((char*)this,sizeof(*this));
                    }
                       fin.close();
                       if(flag==0)
                      {
                        cout<<"Record not found"<<endl;
                        Sleep(2000);
                        system("CLS");
                      }
                }

              else
                {
                  cout<<"Bookdata.dat not opened..."<<endl;
                  Sleep(3000);
                  system("CLS");
                }
              break;
       
      Default : cout<<"Invalid Choice"<<endl;
                Sleep(2000);
                system("CLS");
    }   
}

bool Book::StoreBookData()
{
    fstream fout;
        fout.open("Bookdata.dat",ios::app);
        if(fout)
        {
            fout.write((char*)this,sizeof(*this));
            fout.close();
            return true;
        }
        else
        {
            cout<<"Bookdata.dat not opened...\n";
            return false;
        }
    

}

void Book::SetBookData()
{
  Admin A; 
  system("CLS");
  Title("S E T   B O O K D A T A");

  cout<<"Enter Book name\n";
  fflush(stdin);
  gets(BookName);
  fflush(stdin);
  cout<<"\nEnter Book Genre\n";
  cin>>BookGenre;
  fflush(stdin);
  cout<<"\nEnter Book Author\n";
  gets(BookAuthor);
  fflush(stdin);
  cout<<"\nEnter BookId\n";
  cin>>BookID;
  fflush(stdin);
  cout<<"\nEnter Book Price\n";
  fflush(stdin);
  cin>>BookPrice;

  time_t t;
  time(&t);
  TIME=ctime(&t);
}



void Admin::AdminMenu()
{
    int choice;
    Student S;
    Book B;
  while(1)
  {
        system("CLS");
        Title("A D M I N   P O R T A L");
        cout<<"1) Display All Students Record\n2) Search a specific student\n3) Delete student Record\n4) Add Book\n5) Diplay All Books\n6) Search Book\n7) Delete Book\n8) Main Menu\n";
        
        cout<<endl<<"Enter your choice\n";
        cin>>choice;

        switch(choice)
         {
           case 1: system("CLS");
                   S.ListStudentData();
                   break;
       
           case 2: system("CLS");
                   S.SearchStudentData();
                   break;
       
           case 3: system("CLS");
                   S.DeleteStudentData();
                   break;
       
           case 4: system("CLS");
                   B.SetBookData();
                   if(B.StoreBookData())
                    {
                        Message("Book added successfully...\n");
                        cout<<"Added time : "<<B.TIME;
                        Sleep(3000);
                        system("CLS");
                    }
                   else
                   {
                       cout<<"Data updation error..."<<endl;
                       Sleep(2000);
                       system("CLS");
                   } 
                   break;
       
           case 5: system("CLS");
                   B.ListBookData();
                   break;
       
           case 6: system("CLS");
                   B.SearchBookData();
                   break;
       
           case 7: system("CLS");
                   B.DeleteBookData();
                   break;
       
           case 8: system("CLS");
                   HomePage();
                   break;
       
           default:system("CLS");
                   cout<<"Invalid Choice\n";
                   Sleep(2000);
                   system("CLS");
          } 
                   cout<<"Enter 0 to go back to Admin Menu"<<endl;
                   fflush(stdin);
                       if('0'!=getchar())
                       HomePage();
           
  }
                  
}

void Admin::AdminLogin()
{
     system("CLS");
     Title("A D M I N   L O G I N");
      char userID[20];
      char password[20];
      cout<<"Enter Admin ID\n";
      cin>>userID;
      cout<<"Enter Admin Password\n";
      cin>>password;
    
     if(verifyAdmin(userID,password))
      {
          cout<<"Login successfull..."<<endl;
          Sleep(2000);
          system("CLS");
          AdminMenu();
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
    Title("A D M I N   P O R T A L"); 
    fin.open("Admin_lib.dat");

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



void Student::EditProfile()
{
  ifstream fin;
  ofstream fout;
  Student S;
  
   fin.open("Student_lib.txt",ios::in);
      if(fin)
        {
          fout.open("Tempfile.dat",ios::out|ios::app);
          fin.read((char*)&S,sizeof(S));
          while(!fin.eof())
          {
              if(strcmp(S.name,name))
                  fout.write((char*)&S,sizeof(S));

              else
              {
                S.GetData();
                *this=S;
                fout.write((char*)&S,sizeof(S));
              }
              fin.read((char*)&S,sizeof(S));
          }
             fout.close();       
             fin.close();

             remove("Student_lib.txt");
             rename("Tempfile.txt","Student_lib.txt");
             cout<<"Profile Updated...";
             Sleep(2000);
             system("CLS");
          }

        else
        {
          cout<<"Student_lib.txt file error"<<endl;
          Sleep(2000);
          system("CLS");
        }
    StudentMenu();

}

void Student::DeleteProfile()
{
  ifstream fin;
  ofstream fout;
  Student S;
  
   fin.open("Student_lib.txt",ios::in);
      if(fin)
        {
          fout.open("Tempfile.txt",ios::out|ios::app);
          fin.read((char*)&S,sizeof(S));
          while(!fin.eof())
          {
              if(strcmp(S.name,name))
                  fout.write((char*)&S,sizeof(S));
              
              fin.read((char*)&S,sizeof(S));
          }
             fout.close();       
             fin.close();

             remove("Student_lib.txt");
             rename("Tempfile.dat","Student_lib.dat");
             cout<<"Profile Deleted...";
             Sleep(2000);
             system("CLS");
          }

        else
        {
          cout<<"Student_lib.txt file error"<<endl;
          Sleep(2000);
          system("CLS");
        }
  HomePage();
}


void Student::UpdateBookRecord(Book B)
{
  ifstream fin;
  ofstream fout;
  Student S;

  BookRecord=B;
  BorrowedStatus=true;
  BorrowedTime=Time();
  //cout<<endl<<asctime(BorrowedTime)<<endl;
  fin.open("Student_lib.txt",ios::in|ios::binary);
  fout.open("Tempfile.dat",ios::out|ios::app|ios::binary);
  
  if(fin)
    {
      fin.read((char*)&S,sizeof(S));
      while(!fin.eof())
        {
          if(strcmp(S.name,name))
              fout.write((char*)&S,sizeof(S));
          else
              fout.write((char*)this,sizeof(*this));

          fin.read((char*)&S,sizeof(S));
        }
        fout.close();
        fin.close();
        remove("Student_lib.txt");
        rename("Tempfile.dat","Student_lib.txt");
    }
    else
    {
      cout<<"Data updation failed..."<<endl;
      Sleep(2000);
      system("CLS");
    }

  }

void Student::ResetBookRecord()
{
   Book B;
   BookRecord=B;
   BorrowedStatus=false;
   BorrowedTime=NULL;
   BORROWED_TIME="00:00:00";
}

void Student::ReturnBook()
{
  time_t now;
  time(&now);
  double Seconds;
  int Penalty=0;
  Seconds=difftime(now,mktime(BorrowedTime));
  float day=0;
  if(Seconds>2592000)
    {
      Seconds-=2592000;
      day = Seconds/86400;
    }
    day=ceil(day);
    Penalty = 2*day;
    
  system("CLS");
  Title("R E T U R N    B O O K");
  cout<<"Book You had borrowed :"<<endl;
  this->BookRecord.ShowBookData();
  cout<<"DO you want to Return this Book"<<endl;
  cout<<"Enter Y/N"<<endl;
  fflush(stdin);
   if('Y'==getchar())
     {
         system("CLS");
         BookRecord.GenerateToken(2,day,Penalty);
         ResetBookRecord();
     }
    else
       StudentMenu();
}

void Student::BorrowBook()
{
  Book B;
  char ch;
  system("CLS");
  Title("B O R R O W    B O O K");
   cout<<"Search the Book you want to borrow"<<endl;
   B.SearchBookData();
   cout<<"Do you want to borrow this Book"<<endl;
   cout<<"Enter Y/N"<<endl;
   cin>>ch;
   fflush(stdin);
   if('Y' ==ch || 'y'== ch)
    {
      this->UpdateBookRecord(B);
      B.GenerateToken(1,0,0);
    }
   else
    {
      cout<<"Try Again..."<<endl;
      Sleep(2000);
      system("CLS");
      StudentMenu();
    }
}

void Student::SearchStudentData()
{
  int choice,flag=0;
  fstream fin;
  char value[25];
  Admin A;
  
  system("CLS");
  Title("S E A R C H   S T U D E N T");

  cout<<"Search student By :"<<endl<<endl;
  cout<<"1)Name\t\t\t2) Mobile No.\t\t\t3) Date Of Birth\t\t\t4) Email ID"<<endl;
  cout<<"Enter your choice"<<endl;
  fflush(stdin);
  cin>>choice;

  switch(choice)
    {
      case 1: cout<<"Enter Student Name"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                    fin.read((char*)this,sizeof(*this));
                    while(!fin.eof())
                     {
                       if(!strcmpi(value,name))
                        {
                          ShowStudentData(BookRecord);
                          flag++;
                        }
                        fin.read((char*)this,sizeof(*this));
                     }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<endl<<flag<<" data has been found with same name"<<endl;
                        }
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
              break;
              
      case 2: cout<<"Enter Student Mobile No."<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                   {
                      if(!strcmpi(value,mobile))
                        {
                          ShowStudentData(BookRecord);
                          flag++;
                        }
                       fin.read((char*)this,sizeof(*this));
                    }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<endl<<flag<<" data has been found with same mobile no."<<endl;
                        }
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
              break;        

      case 3: cout<<"Enter Student's Date Of Birth"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                   {
                      if(!strcmpi(value,DOB))
                        {
                          ShowStudentData(BookRecord);
                          flag++;
                        }
                       fin.read((char*)this,sizeof(*this));
                    }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<endl<<flag<<" data has been found with same Date Of Birth"<<endl;
                        }
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
                break;

      case 4: cout<<"Enter Student's Email ID"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                   {
                      if(!strcmpi(value,EmailID))
                        {
                          ShowStudentData(BookRecord);
                          flag++;
                        }
                       fin.read((char*)this,sizeof(*this));
                    }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<endl<<flag<<" data has been found with same Email ID"<<endl;
                        }
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
                   break;

      default :cout<<"Invalid Choice"<<endl;
               Sleep(2000);
               system("CLS");
   }
 }


void Student::ListStudentData()
{
  ifstream fin;
  Admin A;
  
   Title("S T U D E N T    R E C O R D");
   fin.open("Student_lib.txt",ios::in);
   if(fin)
     {
       fin.read((char*)this,sizeof(*this));
       while(!fin.eof())
         {
           ShowStudentData(BookRecord);
           fin.read((char*)this,sizeof(*this));
         }
         fin.close();
     }
    else
      {
        cout<<"Student_lib.txt file missing..."<<endl;
        Sleep(2000);
        system("CLS");
      }
}

void Student::DeleteStudentData()
{
  int choice,flag=0;
  fstream fin;
  fstream fout;
  char value[25];
  Admin A;

  system("CLS");
  Title("D E L E T E   S T U D E N T");

  cout<<"Delete Student By :"<<endl;
  cout<<"1)Name\t\t\t2) Mobile No.\t\t\t3) Date Of Birth\t\t\t4) Email ID"<<endl;
  cout<<"Enter your choice"<<endl;
  fflush(stdin);
  cin>>choice;
  
  switch(choice)
     {
       case 1: cout<<"Enter Student Name"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                   {
                      if(strcmpi(value,name))
                          fout.write((char*)this,sizeof(*this));
                      else
                      flag++;
                       fin.read((char*)this,sizeof(*this));
                    }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<flag<<" data has been found with same name"<<endl;
                          Message("Deletion successfull...");
                          Sleep(2000);
                          system("CLS");
                        }
                    remove("Student_lib.txt");
                    rename("Tempfile.txt","Student_lib.txt");
                    
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
              break;

       case 2: cout<<"Enter Student Mobile NO."<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                   {
                      if(strcmpi(value,mobile))
                          fout.write((char*)this,sizeof(*this));
                      else
                      flag++;
                       fin.read((char*)this,sizeof(*this));
                    }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<flag<<" data has been found with same mobile no."<<endl;
                          Message("Deletion successfull...");
                          Sleep(2000);
                          system("CLS");
                        }
                    remove("Student_lib.txt");
                    rename("Tempfile.txt","Student_lib.txt");
                    
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
              break;

        case 3: cout<<"Enter Student Date Of Birth"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                   {
                      if(strcmpi(value,DOB))
                          fout.write((char*)this,sizeof(*this));
                      else
                      flag++;
                       fin.read((char*)this,sizeof(*this));
                    }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<flag<<" data has been found with same date Of Birth"<<endl;
                          Message("Deletion successfull...");
                          Sleep(2000);
                          system("CLS");
                        }
                    remove("Student_lib.txt");
                    rename("Tempfile.txt","Student_lib.txt");
                    
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
                break;

        case 4: cout<<"Enter Student Email ID"<<endl;
              fflush(stdin);
              gets(value);

              fin.open("Student_lib.txt",ios::in);
              if(fin)
                {
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof())
                   {
                      if(strcmpi(value,EmailID))
                          fout.write((char*)this,sizeof(*this));
                      else
                      flag++;
                       fin.read((char*)this,sizeof(*this));
                    }

                    if(flag==0)
                        {
                          cout<<"No Data found"<<endl;
                          Sleep(2000);
                          system("CLS");
                        }
                    else
                        {
                          cout<<flag<<" data has been found with same Email ID"<<endl;
                          Message("Deletion successfull...");
                          Sleep(2000);
                          system("CLS");
                        }
                    remove("Student_lib.txt");
                    rename("Tempfile.txt","Student_lib.txt");
                }

                else
                   {
                     cout<<"Student_lib.txt file missing..."<<endl;
                     Sleep(2000);
                     system("CLS");
                   }
  
              break;
     
        Default : cout<<"Invalid Choice"<<endl;
                  Sleep(2000);
                  system("CLS");
     }
      
}


void Student::ShowStudentData(Book B)
{
   cout<<"Name                : "<<name<<endl;
   cout<<"Gender              : "<<gender<<endl;
   cout<<"Date Of Birth       : "<<DOB<<endl;
   cout<<"Mobile No.          : "<<mobile<<endl;
   cout<<"Email ID            : "<<EmailID<<endl;
   //cout<<"Profile created on  : "<<PROFILE_TIME<<endl;
   cout<<"Borrowed status     : "<<BorrowedStatus<<endl<<endl<<endl;
   if(BorrowedStatus==true)
   {
   cout<<"Borrowed Book -> "<<endl; 
   B.ShowBookData();
   cout<<"Borrowed Time       : "<<BORROWED_TIME<<endl;
   Line();
   }
}

void Student::ViewProfile()
{
  int choice;
  string NAME;
  for(int i=0;i<=strlen(name);i++)
  NAME=NAME + name[i] + " ";

  system("CLS");
  Title(NAME);
  
  ShowStudentData(BookRecord); 

   cout<<"1) Edit Profile\t\t\t2) Delete Profile\t\t\t3) Student Menu\t\t\t4) Home Page"<<endl<<endl;
   cout<<"Enter your choice"<<endl;
   cin>>choice;
     switch(choice)
     {
       case 1: EditProfile();
               break;

       case 2: DeleteProfile();
               break;

       case 3: StudentMenu();
               break;

       case 4: HomePage();
               break;

       default: cout<<"Invalid choice..."<<endl;
                Sleep(2000);
                system("CLS");
                StudentMenu(); 
     }
}

void Student::StudentMenu()
{
  int choice;
  Book B;
  while(1)
  {
          system("CLS");
          Title("S T U D E N T   P O R T A L");
          cout<<"1) View Profile\n2) List Of Books\n3) Borrow Book\n4) Return Book\n5) Search Book\n6) Main Menu\n";
          cout<<endl<<"Enter your choice\n";
          fflush(stdin);
          cin>>choice;
          
          switch(choice)
          {
            case 1: system("CLS");
                    ViewProfile();
                    break;
        
            case 2: system("CLS");
                    B.ListBookData();
                    break;
        
            case 3: system("CLS");
                    if(BorrowedStatus==false)
                    BorrowBook();
                    else
                    {
                      cout<<"Unable to Borrow Book since your previous Book is yet to be returned"<<endl;
                      Sleep(2000);
                      system("CLS"); 
                    }
                    break;
        
            case 4: system("CLS");
                    if(BorrowedStatus==true)
                    ReturnBook();
                    else
                      {
                        cout<<"Unable to Return Book since you have not borrowed any book"<<endl;
                        Sleep(2000);
                        system("CLS");
                      }
                    break;
        
            case 5: system("CLS");
                    B.SearchBookData();
                    break;
        
            case 6: system("CLS");
                    HomePage();
                    break;
        
            default:system("CLS");
                    cout<<"Invalid Choice\n";
                    Sleep(2000);
                    system("CLS");
            
          }
       cout<<"Press 0 to go back to Student Menu"<<endl;
       fflush(stdin);
       if(!'0'==getchar())
        HomePage();
                    
  }
}

bool Student::MobileVerifier(string MOBILE)
   {
       int count=0;
        if(MOBILE.length()==10)
        {
             if(MOBILE[0]=='6' || mobile[0]=='7' || MOBILE[0]=='8' || MOBILE[0]=='9')
            {
                for(int i=1;i<10;i++)
                {
                    if(MOBILE[i]<58 && MOBILE[i]>47)
                     count++;
                }
            }
        }

    if(count==9)
    return true;
    else
    return false;

   }

bool Student::GenderVerifier(string GENDER)
{
    if(GENDER=="MALE" || GENDER=="FEMALE" || GENDER=="Male" || GENDER=="Female")
       return true;
    else
       return false;
}

bool Student::DOBVerifier(string dob)
{   
   int flag=0;
   if(dob[2]=='/' && dob[5]=='/' && dob.length()==10)
 {
    int D,M,Y;
    D=(dob[0]-'0')*10 + (dob[1]-'0');
    M=(dob[3]-'0')*10 + (dob[4]-'0');
    Y=(dob[6]-'0')*1000 + (dob[7]-'0')*100 + (dob[8]-'0')*10 + (dob[9]-'0');
    
   if((D>=1 && D<=31) && (M>=1 && M<=12) && (Y>=1900 && Y<=2016))
    {
        if((M==1 || M==3 || M==5 || M==7 || M==8 || M==10 || M==12) && D>=1 && D<=31)
        flag=1;

        if(M==2)
        {
            if(Y%4==0 || Y%400==0)
            {
                if(D<=29 && D>=1)
                flag=1;
            }
            else if(D<=28 && D>=1)
            flag=1;
        }  
        

        if((M==4 || M==6 || M==9 || M==11) && (D>=1 && D<=30))
        flag=1;
    }
    else
    return false;
 }
 else
 return false;

    if(flag==1)
      return true;
    else
      return false; 
}

bool Student::PasswordVerifier(string Password)
{
   int i=0,count_lower=0,count_upper=0,count_special=0,count_number=0;
    if(Password.length()>7)
    {
        while(Password[i]!='\0')
        {
            if((Password[i]>96 && Password[i]<123))
            count_lower++;

            if((Password[i]>64 && Password[i]<91))
            count_upper++;

            if((Password[i]>47 && Password[i]<58))
            count_number++;

            if((Password[i]>32 && Password[i]<48) || (Password[i]>57 && Password[i]<65) || (Password[i]>90 && Password[i]<97) && (Password[i]>122 && Password[i]<127))
            count_special++;

            i++;
        }
    }
    else
    return false;

    if(count_lower!=0 && count_number!=0 && count_special!=0 && count_upper!=0)
    return true;
    else
    return false;
}

bool Student::EmailVerifier(string email)
{
int index1=0,index2=0,flag=0,count1=0,count2=0;
int i=0;
while(email[i]!='\0')
    {
      if((email[i]<123 && email[i]>96) || (email[i]<91 && email[i]>64) || (email[i]<58 && email[i]>47) || email[i]=='@' || email[i]=='.')
       {
          if((email[0]<123 && email[0]>96) || (email[0]<91 && email[0]>64))
          flag=1;

          if(email[i]=='@')
          {
              count1++;
          index1=email.find('@',0);
          }

          if(email[i]=='.')
          {
              count2++;
          index2=email.find('.',0);
          }
       }
       else
       {
           cout<<"This is an invalid email ID\n";
           return false;
       }
       i++;
    }

    if(flag==1 && index1!=0 && index2!=0 && index1<index2 && count1==1 && count2==1)
    return true;
    else
    return false;

}


bool Student::StoreStudentData()
{
  ofstream fout;
  fout.open("Student_lib.txt",ios::app);
  if(fout)
  {
    fout.write((char*)this,sizeof(*this));
    fout.close();
    return true;
  }
  else   
    return false;
}


void Student::GetData()
{
    system("CLS");
    Title("S I G N U P");
    int count=0;
    cout<<"Enter your full name\n";
    fflush(stdin);
    gets(name);


    D:
    cout<<"\nEnter your Date of Birth in dd/mm/yyyy format\n";
    fflush(stdin);
    cin>>DOB;


    string dob = charToString(DOB,strlen(DOB));

    if(!DOBVerifier(dob))
    {
        cout<<"Invalid Date of Birth\n";
        Sleep(2000);
        goto D;
    }
    
    cout<<"Gender : "<<gender<<endl;
    cout<<"DOB    : "<<DOB<<endl;
    
    G:
    cout<<"\nMale or Female\n";
    fflush(stdin);
    cin>>gender;
  
    string GENDER = charToString(gender,strlen(gender));

    if(!GenderVerifier(GENDER))
    {
        cout<<"Entered value is incorrect\n";
        cout<<"Please Enter in correct format \n";
        Sleep(2000);
        system("CLS");
        goto G;
    }

    cout<<"Gender : "<<gender<<endl;
    cout<<"DOB    : "<<DOB<<endl;

    mobile_no:
    cout<<"\nEnter your mobile no. without ISD code\n";
    fflush(stdin);
    gets(mobile);
    
    string MOBILE = charToString(mobile,strlen(mobile));

    if(!MobileVerifier(MOBILE))
    {
      cout<<"Enter a valid mobile number\n";
      Sleep(2000);
      goto mobile_no;
    }
    
    EMAIL:
    cout<<"\nEnter your email Id\n";
    fflush(stdin);
    gets(EmailID);
    
    string EMAILID = charToString(EmailID,strlen(EmailID));
    if(!EmailVerifier(EMAILID))
    {
        cout<<"Please enter a valid email ID\n";
        goto EMAIL;
    }
    
    password:
    cout<<"\nEnter your password\n";
    fflush(stdin);
    string passWORD;
    char ch;
    while((ch=getch())!=13)
        {
            if(ch>32)
            {
                cout<<"*";
                passWORD.push_back(ch);
            }

            if(ch==8 && passWORD.size()!=0)
            {
                passWORD.pop_back();
                cout<<"\b \b";
            }
        }

    char PASSword[20];
      strcpy(PASSword,passWORD.c_str());
      strcpy(Student_Pswd,PASSword);

      //string PASSWORD = charToString(Student_Pswd,strlen(Student_Pswd));
      if(!PasswordVerifier(passWORD))
    {
        cout<<"\nYour Password should have \n1.Atleast 8 character long\n2.Should have alphabet in both upper and lower case\n3.Should contain numbers\n4.Should have special characters\n";
        cout<<endl;
        goto password;
    }

    time_t t;
    time(&t);
    PROFILE_TIME=ctime(&t);

    
}

void Student::Login()
{
  ifstream fin;
  char USER[25],PASSWORD[15];
  int counter=0;
  I:
  system("CLS");
  Title("S T U D E N T   L O G I N");
  cout<<"Enter Student Mobile No./Email ID"<<endl;
  cin>>USER;
  cout<<"Enter Password"<<endl;
  fflush(stdin);

  string passWORD;
      char ch;
      while((ch=getch())!=13)
    {
        if(ch>32)
        {
            cout<<"*";
            passWORD.push_back(ch);
        }

        if(ch==8 && passWORD.size()!=0)
        {
            passWORD.pop_back();
            cout<<"\b \b";
        }
    }
  strcpy(PASSWORD,passWORD.c_str());

  fin.open("Student_lib.txt",ios::in);
  if(fin)
    {
       int flag=0;
       fin.read((char*)this,sizeof(*this));
       while(!fin.eof())
         {
           if((!strcmp(USER,mobile) || !strcmp(USER,EmailID)) && !strcmp(PASSWORD,Student_Pswd))
           {
             flag++;
             break;
           }
             fin.read((char*)this,sizeof(*this));
         }
         fin.close();

         if(flag==1)
         {
           cout<<endl<<"Login Successfull..."<<endl;
           Sleep(2000);
           system("CLS");
           StudentMenu();
         }
         else
         {
             counter++;
             cout<<"Invalid StudentId or password,try again...\n";
             if(counter==3)
             {
              cout<<"Too many attempts failed\n";
              exit(0);
             }
              if(counter==1)
              cout<<"Only 2 attempts left\n";

              if(counter==2)
              cout<<"Only 1 attempt left\n"; 

              Sleep(2000);
              system("CLS");
              goto I;
          }
    }

    else
    {
      cout<<"Student_lib.txt file missing..."<<endl;
      Sleep(2000);
      system("CLS");
      HomePage();
    }
}

void Student::Signup()
{

  GetData();

  if(StoreStudentData())
    {
        cout<<endl<<"Student data has been updated to the server..."<<endl;
        Sleep(2000);
        system("CLS");
    }
    else
    {
        cout<<"Updation failed..."<<endl;
        Sleep(2000);
        system("CLS");
    }
}
 
void StudentPortal()
{
    int choice;
    Student S;
     system("CLS");
    
    Title("S T U D E N T   P O R T A L");
    cout<<"1) Login\n\n2) Signup\n\n3) Home Page"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1: S.Login();
            break;

        case 2: S.Signup();
            break;

        case 3: HomePage();
            break;

        default: cout<<"Inavalid Choice\nEnter valid choice\n";
        Sleep(2000);
        system("CLS");
        HomePage();
    }
       if(choice==2)
        {
          cout<<"Do You Want to Login.(Y/N)"<<endl;
            if('Y' || 'y'==getchar())
              S.Login();
            else 
              HomePage();
        }
}

void HomePage()
{
    int choice;
    system("CLS");
    Title("WELCOME TO MINI LIBRARY MANAGEMENT");
    cout<<"1) Admin Portal\n\n2) Student Portal\n\n3) Exit\n\n";

    cout<<"Enter your choice\n";
    cin>>choice;

    switch(choice)
    {
    case 1: system("CLS");
            AdminPortal();
            break;

    case 2: system("CLS");
            StudentPortal();
            break;

    default: cout<<"Invalid Choice\n";
            break;
    
    case 3:system("CLS");
            Sleep(2000);
            cout<<"W E L C O M E   A G A I N\n";
            exit(0);

   
    }
}

int main()
{
    HomePage();
    return 0;
}