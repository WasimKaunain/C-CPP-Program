#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

void gotoxy(short int x,short int y)
{
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void A(int letterWidth,int letterHeight,int xPoint,int yPoint)
 {
     if(letterHeight==7)
      {
          for(int i=0; i<letterHeight; i++)
            {
                for(int j=0; j<letterWidth;j++)
                 {
                     if(i==1 || i==4)
                     cout<<"#";
                     else if((i==2 || i==3 || i==5 || i==6 || i==7) && (j==1 || j==letterWidth-1))
                     cout<<"#";
                     else
                     cout<<" ";
                 }
                gotoxy(xPoint,yPoint++);
            }
      }

      else
      {
          for(int i=1; i<=letterWidth; i++)
            {
                for(int j=1; j<=letterHeight;j++)
                 {
                     if(i==1 || i==3)
                     cout<<"#";
                     else if((i==2 || i==4 || i==5) && (j==1 || j==letterWidth))
                     cout<<"#";
                     else
                     cout<<" ";
                 }
            }
      }
 }

void B(int letterWidth,int letterHeight,int xPoint,int yPoint)
 {
     if(letterHeight==7)
      {
          for(int i=0; i<letterHeight; i++)
            {
                for(int j=0; j<letterWidth;j++)
                 {
                     if(i==1 || i==4 || i==7)
                     cout<<"#";
                     else if((i==2 || i==3 || i==5 || i==6) && (j==1 || j==letterWidth-1))
                     cout<<"#";
                     else
                     cout<<" ";
                 }
                gotoxy(xPoint,yPoint++);
            }
      }

      else
      {
          for(int i=0; i<letterWidth; i++)
            {
                for(int j=0; j<letterHeight;j++)
                 {
                     if(i==1 || i==3 || i==5)
                     cout<<"#";
                     else if((i==2 || i==4) && (j==1 || j==letterWidth-1))
                     cout<<"#";
                     else
                     cout<<" ";
                 }
            }
      }
 }

void Decoration(string S)
{
  int letterWidth=0;
  int space=0;

  for(space=1;space<11;space++)
  {
   if( (162 -(162%S.length()) -((S.length() -1)*space)) % S.length() ==0)
   {
    letterWidth = (162 -(162%S.length()) -(S.length() -1)*space)/S.length();
    break;
   }
  }

  int letterHeight;
  letterHeight = S.length()>10?5:7;
  int xPoint,yPoint;

  xPoint = (162%S.length())/2;
  yPoint = (36-letterHeight)/2;
  

for(int i=0;i<S.length();i++)
  {
    gotoxy(xPoint,yPoint);

    if(S[i]=='A') A(letterWidth,letterHeight,xPoint,yPoint);
    if(S[i]=='B') B(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='C') C(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='D') D(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='E') E(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='F') F(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='G') G(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='H') H(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='I') I(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='J') J(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='K') K(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='L') L(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='M') M(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='N') N(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='O') O(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='P') P(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='Q') Q(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='R') R(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='S') S(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='T') T(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='U') U(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='V') V(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='W') W(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='X') X(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='Y') Y(letterWidth,letterHeight,xPoint,yPoint);
    // if(S[i]=='Z') Z(letterWidth,letterHeight,xPoint,yPoint);  

    xPoint+= letterWidth + space;
    
  }

}
int main()
{
    system("CLS");
    Decoration("BBBBBBB");
    return 0;
}