#include<iostream>
#include<Windows.h>
using namespace std;


void gotoxy(short int x,short int y)
{
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
        int xPoint =1;
        int yPoint =15;
        system("CLS");
          for(int i=0; i<7; i++)
            {
                for(int j=0; j<28;j++)
                 {
                     if(i==1 || i==4)
                     cout<<"#";
                     else if((i==2 || i==3 || i==5 || i==6 || i==7) && (j==1 || j==27))
                     cout<<"#";
                     else
                     cout<<" ";
                 }
                gotoxy(xPoint,yPoint++);
            }
    return 0;
}