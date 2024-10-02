#include<iostream>
#include<stdlib.h>
#include<string>
#include<Windows.h>
#include<fstream>
#include<iomanip>
using namespace std;

void HomePage();
void Login();

int x_coord(string s)
{
   return(74-(s.length())/2);
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
    gotoxy(0,3);
for(int i=0;i<149;i++)
    cout<<"+";
gotoxy(0,5);
}

class Student
{
  string name;
  string DOB;
  char gender;
  string mobile;
  string emailID;
  string Student_Pswd;

  public:
  friend class ADMIN;

  void GetData();
  bool EmailVerifier(string);
  bool Password_Verifier(string);
  bool Gender_Verifier(char);
  bool Mobile_Verifier(string);
  bool DOB_Verifier(string);
  void ViewProfile();
  void StudentMenu();
  void BorrowBook();
  void ReturnBook();

};

void Student::ViewProfile()
{

}

class Admin
{
 string userID;
 string password;

 public:
 void AdminMenu();
 void DeleteStudent();
 void StudentRecord();
 void DeleteBook();
 void AddBook();
 void SearchStudent();
 

 void set_ID_PSWD(string UID,string PASSWORD)
 {
     userID=UID;
     password=PASSWORD;
 }

 bool ID_Pswd_Verifier(string UID,string PSWD)
 {
    if(UID==userID && PSWD==password)
    return true;
    else
    return false;
 }
};

void Admin::StudentRecord()
{
    Title("S T U D E N T   R E C O R D");
    ifstream fin;
    fin.open("Student_lib.dat",ios::in);
    if(fin.is_open())
    {
        char data;
        fin>>data;
        while(!fin.eof())
        cout<<data;
        fin.close();
    }
    else
    {
    cout<<"File not found...\n";
    Sleep(2000);
    system("CLS");
    }  
}

void Admin::SearchStudent()
{
    int choice;
    S:
  Title ("S E A R C H  S T U D E N T");
  cout<<"SEARCH BY :"<<endl;
  cout<<"1) Name\n2) Date Of Birth\n3) Mobile Number\n\n";
  cout<<"Enter your choice\n";
  cin>>choice;

  switch(choice)
  {
      case 1:cout<<"Under maintenance\n";
      break;

      case 2:cout<<"Under maintenance\n";
      break;


      case 3:cout<<"Under maintenance\n";
      break;

      default:cout<<"Invalid choice...\n";
      Sleep(2000);
      system("CLS");
      goto S;
  }
}

void Admin::DeleteStudent()
{
  fstream fin;
  int choice;
  S:
  Title ("D E L E T E   S T U D E N T");
   cout<<"SEARCH BY :"<<endl;
  cout<<"1) Name\n2) Date Of Birth\n3) Mobile Number\n\n";
  cout<<"Enter your choice\n";
  cin>>choice;

  switch(choice)
  {
      case 1:cout<<"Under maintenance\n";
      break;

      case 2:cout<<"Under maintenance\n";
      break;


      case 3:cout<<"Under maintenance\n";
      break;

      default:cout<<"Invalid choice...\n";
      Sleep(2000);
      system("CLS");
      goto S;
  }
}

class Book
{
string BookName;
string BookAuthor;
string BookGenre;
int BookID;

public:
friend class ADMIN;
friend class Student;
void SetBookData();
};

void MainMenu()
{
    HomePage();
}

void Book::SetBookData()
{  
    fstream fout;

   cout<<"Enter book name\n";
   getline(cin,BookName);
   fflush(stdin);
   cout<<"Enter Book Genre\n";
   cin>>BookGenre;
   fflush(stdin);
   cout<<"Enter Book Author\n";
   getline(cin,BookAuthor);
   fflush(stdin);
   cout<<"Enter BookId\n";
   cin>>BookID;
   fflush(stdin);
   
   fout.open("BookData.txt",ios::app);
   fout<<BookName<<setw(10)<<BookGenre<<setw(15)<<BookAuthor<<setw(10)<<BookID<<endl<<endl;
   fout.close();
}

void Admin::AddBook()
{
    Title("A D D   B O O K S");
   Book *B = new Book;
   B->SetBookData();
   
   cout<<"Book added successfully...";
   Sleep(2000);
   system("CLS");
   delete B;
}

void ListOfBooks()
{
    Title (" L I S T   O F   B O O K S");
  fstream fin;
  fin.open("BookData.txt",ios::in);

  if(fin.is_open())
  {
  while(!fin.eof())
    cout<<(char)fin.get();
  fin.close();
  cin.get();
  }
  else
  {
      cout<<"Error 404... Unable to open file";
      Sleep(2000);
      system("CLS");
  }
}

void Student::ReturnBook()
{

}

void SearchBook()
{
    int choice;
    S:
  Title("S E A R C H   B O O K S");
  cout<<"Search by:"<<endl<<endl;
  cout<<"1) Book Name\n2) Book Genre\n3) Book Author\n4) Book ID";
  cout<<endl<<endl;

  cout<<"Enter your choice\n";
  cin>>choice;

  switch(choice)
  {
      case 1:cout<<"Under maintenance\n";
      break;

      case 2:cout<<"Under maintenance\n";
      break;


      case 3:cout<<"Under maintenance\n";
      break;

      case 4:cout<<"Under maintenance\n";
      break;

      default:cout<<"Invalid choice...\n";
      Sleep(2000);
      system("CLS");
      goto S;
  }
}

void Admin::DeleteBook()
{

}

void Student::BorrowBook()
{

}

bool Student::Mobile_Verifier(string mobile)
   {
       int count=0;
        if(mobile.length()==10)
        {
             if(mobile[0]=='6' || mobile[0]=='7' || mobile[0]=='8' || mobile[0]=='9')
            {
                for(int i=1;i<10;i++)
                {
                    if(mobile[i]<58 && mobile[i]>47)
                     count++;
                }
            }
        }

    if(count!=9)
    return false;
    else
    return true;

   }

bool Student::Gender_Verifier(char gender)
{
    if(gender=='M' || gender=='F' || gender=='f' || gender=='m')
       return true;
    else
       return false;
}

bool Student::DOB_Verifier(string DOB)
{   
   int flag=0;
if(DOB[2]=='/' && DOB[5]=='/' && DOB.length()==10)
 {
    int D,M,Y;
    D=(DOB[0]-'0')*10 + (DOB[1]-'0');
    M=(DOB[3]-'0')*10 + (DOB[4]-'0');
    Y=(DOB[6]-'0')*1000 + (DOB[7]-'0')*100 + (DOB[8]-'0')*10 + (DOB[9]-'0');
    
   if((D>=1 && D<=31) && (M>=1 && M<=12) && (Y>=1900 && Y<=2016))
    {
        if(M==1 && D>=1 && D<=31)
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
        

        if(M==3 && D>=1 && D<=31)
        flag=1;

        if(M==4 && D>=1 && D<=30)
        flag=1;

        if(M==5 && D>=1 && D<=31)
        flag=1;

        if(M==6 && D>=1 && D<=30)
        flag=1;

        if(M==7 && D>=1 && D<=31)
        flag=1;

        if(M==8 && D>=1 && D<=31)
        flag=1;

        if(M==9 && D>=1 && D<=30)
        flag=1;

        if(M==10 && D>=1 && D<=31)
        flag=1;

        if(M==11 && D>=1 && D<=30)
        flag=1;

        if(M==12 && D>=1 && D<=31)
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

bool Student::Password_Verifier(string Password)
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

void Admin::AdminMenu()
{
    int choice;
    system("CLS");
  Title("A D M I N   P O R T A L");
  cout<<"1) Display All Students Record\n2) Search a specific student\n3) Delete student Record\n4) Add Book\n5) Diplay All Books\n6) Search Book\n7) Delete Book\n8) Main Menu\n";
  cout<<endl<<"Enter your choice\n";
  fflush(stdin);
  cin>>choice;
  fflush(stdin);
  int option;
  switch(choice)
  {
    case 1: system("CLS");
            this->StudentRecord();
            break;

    case 2: system("CLS");
            this->SearchStudent();
            break;

    case 3: system("CLS");
            this->DeleteStudent();
            break;

    case 4: system("CLS");
            this->AddBook();
            break;

    case 5: system("CLS");
            ListOfBooks();
            break;

    case 6: system("CLS");
            SearchBook();
            break;

    case 7: system("CLS");
            this->DeleteBook();
            break;

    case 8: system("CLS");
            MainMenu();
            break;

    case '\n':cout<<"Pakda gaya\n";
    Sleep(2000);
           break;

    default:system("CLS");
            cout<<"Invalid Choice\n";
            Sleep(2000);
            system("CLS");
    } 
     
}

void Student::StudentMenu()
{
  int choice;
  M:
  Title("S T U D E N T   P O R T A L");
  cout<<"1) View Profile\n2) List Of Books\n3) Borrow Book\n4) Return book\n5) Search book\n6) Main Menu\n";
  cout<<endl<<"Enter your choice\n";
  cin>>choice;
  fflush(stdin);
  switch(choice)
  {
    case 1: system("CLS");
            this->ViewProfile();
            break;

    case 2: system("CLS");
            ListOfBooks();
            break;

    case 3: system("CLS");
            this->BorrowBook();
            break;

    case 4: system("CLS");
            this->ReturnBook();
            break;

    case 5: system("CLS");
            SearchBook();
            break;

    case 6: system("CLS");
            MainMenu();
            break;

    default:system("CLS");
            cout<<"Invalid Choice\n";
            Sleep(2000);
            system("CLS");
            goto M;
    
  }
}

void Student::GetData()
{
    int count=0;
    cout<<"Enter your full name\n";
    cin>>name;

    G:
    cout<<"\nMale[M] or Female[F]\n";
    cin.clear();
    cin>>gender;
    
    if(!Gender_Verifier(gender))
    {
        cout<<"Entered value is incorrect\n";
        cout<<"PLease Enter in correct format as mentioned above\n";
        Sleep(2000);
        system("CLS");
        goto G;
    }
    

    mobile_no:
    cout<<"\nEnter your mobile no. without ISD code\n";
    cin>>mobile;

    if(!Mobile_Verifier(mobile))
    {
      cout<<"Enter a valid mobile number\n";
      Sleep(2000);
      system("CLS");
      goto mobile_no;
    }

   
    
    int flag=0;

    dob:
    cout<<"\nEnter your Date of Birth in dd/mm/yyyy format\n";
    cin>>DOB;
    if(!DOB_Verifier(DOB))
    {
         cout<<"Invalid Date of Birth\n";
        Sleep(2000);
        system("CLS");
        goto dob;
    }

    
    EMAIL:
    cout<<"\nEnter your email Id\n";
    cin>>emailID;
    
    if(!EmailVerifier(emailID))
    {
        cout<<"Please enter a valid email ID\n";
        goto EMAIL;
    }

    password:
    cout<<"\nEnter your password\n";
    cin>>Student_Pswd;
    if(!Password_Verifier(Student_Pswd))
    {
        cout<<"\nYour Password should have \n1.Atleast 8 character long\n2.Should have alphabet in both upper and lower case\n3.Should contain numbers\n4.Should have special characters\n";
        cout<<endl;
        goto password;
    }
    
}


void Login(Student *S)
{
    string SID;
    string S_PASSWORD;
    int counter=0;
    string StudentId = "SAM";
    string Student_Pswd   = "SAM@123";

    I:
    cout<<"Enter Student ID\n";
    cin>>SID;
    cout<<"Enter Password\n";
    cin>>S_PASSWORD;
    
    if(SID==StudentId && S_PASSWORD==Student_Pswd)
      {
        cout<<"Successfully logged in...\n";
        Sleep(2000);
        system("CLS");
        Title("S T U D E N T    P O R T A L");
        S->StudentMenu();
      } 
    else
    {
        counter++;
        if(counter==3)
        {
            cout<<"Too many attempts failed\n";
            exit(0);
        }
        cout<<"Invalid StudentId or password,try again...\n";
        if(counter==1)
        cout<<"Only 2 attempts left\n";

        if(counter==2)
        cout<<"Only 1 attempt left\n"; 

        Sleep(2000);
        system("CLS");
        goto I;
    }
}

void Signup(Student *S)
{
    fstream fout;
    system("CLS"); 
    S->GetData(); 
    cout<<endl;
    cout<<"Processing...\n";
    Sleep(2000);
    fout.open("Student_lib.dat",ios::app);
    fout.write((char *)S,sizeof(*S));
    fout.close();
    system("CLS");
    cout<<"Account created successfully...\n";
    Sleep(2000);
    system("CLS");
    delete S;
}

void AdminPortal()
{
    ofstream fout;
    string UID;
    string PASSWORD;
    Admin *A = new Admin;
    
    Title("A D M I N   P O R T A L");
    cout<<"Enter Admin ID\n";
    cin>>UID;
    cout<<"Enter Admin Password\n";
    cin>>PASSWORD;
    ifstream fin;   
    fin.open("Admin_lib.txt");
    if(fin)
    {
        char ch;
        string UID_PSWD = UID + ' ' + PASSWORD;

        cout<<"Admin is already created...";
        Sleep(2000);
        system("CLS");
        fin.open("Admin_lib.txt",ios::binary);
        string credential;

        istreambuf_iterator<char> inputIt(fin),emptyInputIt;
        back_insert_iterator<string> stringInsert(credential);
        copy(inputIt, emptyInputIt,stringInsert);
        
        if(credential == UID_PSWD)
        {
            cout<<"Login successfull..."<<endl;
            Sleep(5000);
            system("CLS");
            A->AdminMenu();
        }
        else
        {
            cout<<"Invalid User ID or Password"<<endl;
            exit(0);
        }
    }
    else
       {
        A->set_ID_PSWD(UID,PASSWORD);
        fout.open("Admin_lib.txt",ios::app);
        fout<<UID<<" "<<PASSWORD;
        fout.close();
        cout<<"File Admin_lib.txt created successfully ...\n";
        Sleep(2000);
        system("CLS");
        cout<<"Logging you in...\n";
        Sleep(5000);
        system("CLS");
        A->AdminMenu();
       }
}

void StudentPortal()
{
    int choice;
    char ask;
    Student *S = new Student;
    Title("S T U D E N T   P O R T A L");
    cout<<"1) Login\n\n2) Signup\n";
    again:
    cin>>choice;
    switch(choice)
    {
        case 1: Login(S);
            break;

        case 2: Signup(S);
    
            cout<<"Do you want to go to HomePage or Student LoginPage\n";
            cout<<"Enter H for HomePage and L for Student LoginPage\n";
            cin>>ask;
        if(ask=='H' || ask=='h')
            HomePage();
        if(ask=='L' || ask=='l')
            Login(S);
        else
           cout<<"Invalid choice\n";
            break;

        default: cout<<"Inavalid Choice\nEnter valid choice\n";
                   goto again;
    }
}

void HomePage()
{
    int choice;
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
    
    case 3: cout<<"Thanks for using it\n";
            exit(0);

   
    }
}
int main()
{
   HomePage();
   return 0;
}