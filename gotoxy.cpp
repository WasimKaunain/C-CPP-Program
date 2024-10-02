#include<iostream>
#include<Windows.h>
#include<unistd.h>

using namespace std;
void gotoxy(int,int);

void gotoxy(int x,int y)
{
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int x_coord(string s)
{
   return(74-(s.length())/2);
}

int main()
{
    string title;
int y;
for(int i=0;i<5;i++)
{
cout<<"Enter Title\n";
getline(cin,title);
gotoxy(x_coord(title),2);
cout<<title;
gotoxy(0,3);
for(int i=0;i<150;i++)
{
    cout<<"+";
}
gotoxy(0,5);
cout<<"Hello";
Sleep(5000);
system("CLS");
}
return 0;
}







