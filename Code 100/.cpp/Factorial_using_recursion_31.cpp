//Program 31
//Factorial using recursion
#include<iostream>
using namespace std;
                 
int fact(int n)
    {
        if(n==1)
            return 1;

        return(n*fact(n-1));
           
    }

int main()
{
    int n;
    cout<<"Enter any number to get its factorial : ";
    cin>>n;

    cout<<"Factorial of "<<n<<" is :"<<fact(n);
    return 0;
}