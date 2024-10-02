#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<unistd.h>
#include<string>
using namespace std;

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
    //cout<<asctime(Time());
    gotoxy(0,3);
for(int i=0;i<162;i++)
    cout<<"+";
gotoxy(0,5);
}

int main()
{
    int A,B;
    char op;
    char choice;
    while(1)
    {
    START:
    system("CLS");
    Title("C  A  L  C  U  L  A  T  O  R");
    cout<<"\t\t\t\t\t\t\t    WELCOME   TO   MINI   CALCULATOR   PROJECT"<<endl;
    cout<<"Press 1 to start and 0 to close the program"<<endl;
    cin>>choice;
    
if(choice==49)
  {
    cout<<"Enter the first number"<<endl;
    cin>>A;
    cout<<"Enter the second number"<<endl;
    fflush(stdin);
    cin>>B;
    cout<<"Enter the operation you want to perform on these numbers"<<endl;
    cin>>op;
    fflush(stdin);
    cout<<endl;
    
    switch(op)
    {
        case '+': cout<<A+B<<endl;
                  Sleep(4000);
                  break;

        case '-': cout<<A-B<<endl;
                    Sleep(4000);
                  break;

        case '/': cout<<A/B<<endl;
                    Sleep(4000);
                  break;

        case '*': cout<<A*B<<endl;
                    Sleep(4000);
                  break;

        case '%': cout<<A%B<<endl;
                    Sleep(4000);
                  break;

        case '^': {int temp=A;
                  for(int i=1;i<B;i++)
                  A*=temp; 
                  cout<<A<<endl;
                    Sleep(4000);
                  break;}
 
        default : cout<<"Invalid operation"<<endl;
                  Sleep(2000);
                  goto START;
    }
  }
else if(choice==48)
  {
    exit(0);
  }

else
  {
      cout<<"Invalid choice"<<endl;
      Sleep(2000);
      goto START;
  }
    }
    return 0;
}