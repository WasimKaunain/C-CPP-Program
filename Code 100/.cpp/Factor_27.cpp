//Program 27
//To list out all factors of a given number

#include<iostream>
#include "Windows.h"
using namespace std;


void factor(int n)
    {
        int factorList[n]={0},j=0;
        for(int i=1;i<=n;i++)
            {
                if(n%i==0)
                    {
                    factorList[j]=i;
                    j++;
                    }
            }
        system("CLS");
        cout<<"List of factors of "<<n<<" :"<<endl;
        for(int i=0;factorList[i]!=0;i++)
        cout<<factorList[i]<<",";
    }

int main()
{
    int n;
    cout<<"Enter any number whose factors you want :";
    cin>>n;

    factor(n);

    return 0;
}   