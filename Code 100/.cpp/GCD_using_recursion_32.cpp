//Program 32
//GCD using recursion
#include<iostream>
using namespace std;

int GCD(int a,int b)
    {
        if(b!=0)
            return GCD(b,a%b);

        else
            return a;
    }
         
int main()
{
    int a,b;
    cout<<"Enter two numbers to get their G.C.D : ";
    cin>>a>>b;

    cout<<"G.C.D of "<<a<<" and "<<b<<" is : "<<GCD(a,b);

    return 0;
}