//Program No.
// Enter Program Title

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
			int min,max;
			cout<<"Enter an interval in which you have to find armstrong numbers : ";
			cin>>min>>max;
			
			int temp=min;
			int result;
			int i=0;
			int list[max-min]={0};
			while(min<=max)
				{
					result=-1;
					result=armstrong(min);	
					if(result==1)
						{
							list[i]=min;
							i++;
						}
					min++;
				}
			system("CLS");
			cout<<"List of armstrong numbers between "<<temp<<" and "<<max<<endl;
			for(int i=0;list[i]!=0;i++)
			cout<<list[i]<<" ";
				
			return 0;
		}


