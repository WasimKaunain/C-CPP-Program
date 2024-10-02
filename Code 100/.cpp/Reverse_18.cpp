//Program 18
// Reverse a Number

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	long double n,m=0;
	cout<<"Enter any number"<<endl;
	cin>>n;
	
	int rem=0;
	cout<<fixed<<setprecision(0);
	while(n!=0)
		{
			rem=fmod(n,10);
			m = m*10 + rem;
			n-=rem;
			n/=10;
		}
		
		cout<<"Reversed number	: "<<m;
	return 0;
}


