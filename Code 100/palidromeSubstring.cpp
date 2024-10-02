#include<iostream>
#include<string.h>
using namespace std;

int specialPalindrome(string s1, string s2)
    {
        int s1_length=s1.length();
        int flag=0;
        for(int i=0,j=s1_length-1;i<j;i++)
            {
                if(s1[i]==s1[j])
                    continue;
                else
                    flag++;
            }
            
        if(!flag && s1.find(s2))
            return -1;
        else
         return 0;
    }

    int main()
    {
        string s1,s2;
        cout<<"Enter two strings\n";
        cin>>s1;
        fflush(stdin);
        cin.clear();
        cin>>s2;
        cout<<specialPalindrome(s1,s2);
        return 0;
    }