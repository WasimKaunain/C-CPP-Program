//Program 22
// Palindrom Check

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	long int m,n;
	cout<<"Enter any number to check weather it is palindrom or not :";
	cin>>n;
	
	int rem;
	cout<<fixed<<setprecision(0);
	long int temp=n;
	while(n!=0)
		{
			rem=fmod(n,10);
			m = m*10 + rem;
			n-=rem;
			n/=10;
		}
		
	cout<<endl<<"Value of Reversed n :"<<m<<endl;
	
	if(m==temp)
	cout<<"This is a Palindrome number";
	else
	cout<<"This is not a palindrome number";
	
		return 0;
}


