//Program 30
//Sum of N natural numbers using recursion
#include<iostream>
using namespace std;
                 
int Sum(int n)
    {
        if(n==1)
        return 1;
        
        return(n + Sum(n-1));
    }

int main()
{
    int n;
    cout<<"Enter any number : ";
    cin>>n;

    cout<<"Sum of "<<n<<" natural numbers is : "<<Sum(n);
    return 0;
}