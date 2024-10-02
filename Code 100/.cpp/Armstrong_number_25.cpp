//Program 25
// Check Armstrong number

#include<iostream>
#include<cmath>
using namespace std;

	int armstrong(int n)
	{
		int temp=n,digitCount=0;
		int temp2=n;
		while(temp!=0)
			{
				temp/=10;
				digitCount++;
			}
		
		int m=0,rem=0;
			
 		while(n!=0)
		{
			rem=n%10;
			m = m + pow(rem,digitCount);
			n/=10;
		}
		
		
		if(m==temp2)
			return 1;
		else
			return 0;
	}

int main()
{
	int n;
	cout<<"Enter any number to check whether it is armstrong number or not"<<endl;
	cin>>n;
	
		int m=armstrong(n);
		
		if(m==1)
		cout<<"This is an armstrong number"<<endl;
		else
		cout<<"This is not an armstrong number"<<endl;
	return 0;
}


