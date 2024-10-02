#include<iostream>
#include<string.h>
using namespace std;

int main()
{
string email;
int index1=0,index2=0,flag=0,count1=0,count2=0;
cout<<"Enter an email ID\n";
cin>>email;
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
           exit(0);
       }
       i++;
    }

    if(flag==1 && index1!=0 && index2!=0 && index1<index2 && count1==1 && count2==1)
    cout<<"This is a valid email ID\n";
    else
    cout<<"This is an invalid email ID\n";
 return 0;
}