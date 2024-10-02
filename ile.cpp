#include<iostream>
#include<string>
#include<string.h>
#include<Windows.h>
#include<unistd.h>
using namespace std;
struct Student{

char DOB[10];

public:
string charToString(char* a,int size)
    {
       
       string s="";
       for(int i=0;i<size;i++)
       {
         s=s+a[i];
       }
       return s;
    }
bool DOBVerifier(string);
void getData();
};

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

void Student::getData()
{
    cout<<"\nEnter your Date of Birth in dd/mm/yyyy format\n";
    fflush(stdin);
    cin>>DOB;
    cout<<"Date of Birth   : "<<DOB<<endl;
    string dob = charToString(DOB,strlen(DOB));
    cout<<"Date of Birth    : "<<dob<<endl;
    cout<<"Size of string is: "<<strlen(DOB);
    /*bool flag=DOBVerifier(dob);
    if(!flag)
    {
        cout<<"Invalid Date of Birth\n";
        Sleep(2000);
        system("CLS");
    
    }*/
}

int main()
{
    Student s1;
    s1.getData();
    return 0;
}