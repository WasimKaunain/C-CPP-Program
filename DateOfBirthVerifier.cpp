#include<iostream>
#include<string.h>
using namespace std;

bool DOB_Verifier(string DOB)
{   
   int flag=0;
if(DOB[2]=='/' && DOB[5]=='/')
 {
    int D,M,Y;
    D=(DOB[0]-'0')*10 + (DOB[1]-'0');
    M=(DOB[3]-'0')*10 + (DOB[4]-'0');
    Y=(DOB[6]-'0')*1000 + (DOB[7]-'0')*100 + (DOB[8]-'0')*10 + (DOB[9]-'0');
    
    cout<<D<<"/"<<M<<"/"<<Y<<endl;

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

int main()
{
  string DOB;
  cout<<"Enter your date of birth in dd/mm/yyyy format\n";
  cin>>DOB;
  if(!DOB_Verifier(DOB))
  cout<<"Invalid Date Of Birth\n";
  else
  cout<<"Valid date of Birth\n";
  return 0;
}