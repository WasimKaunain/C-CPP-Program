//Program 16
// GCD

#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter two numbers to find their GCD"<<endl;
	cin>>a>>b;
	if(a<0 || b<0)
	{
		cout<<"Please enter Non-Negative number"<<endl;
		return 0;
	}
	
	for(int i=a<b?a:b;i>0;i--)
		{
			if(a%i==0 && b%i==0)
			{
				cout<<"G.C.D is  : "<<i<<endl;
				break;
			}			
		}
	return 0;
}


