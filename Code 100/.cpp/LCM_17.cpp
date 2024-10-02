//Program 17
// LCM

#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter two numbers to find their L.C.M"<<endl;
	cin>>a>>b;
	if(a<0 || b<0)
	{
		cout<<"Please enter Non-Negative number"<<endl;
		return 0;
	}
	
	for(int i=a>b?a:b;i<=a*b;i++)
		{
			if(i%a==0 && i%b==0)
			{
				cout<<"L.C.M is  : "<<i<<endl;
				break;
			}			
		}
	return 0;
}


