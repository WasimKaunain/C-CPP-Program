//Program 15
// Fibonacci series

#include<iostream>
using namespace std;

int main()
{
	int n,t1=0,t2=1,nextTerm=0;
	cout<<"Enter a number of terms upto fibonacci series you want"<<endl;
	cin>>n;
	
	for(int i=1;i<=n;i++)
		{
			
			if(i==1)
			{			
			cout<<t1<<" ";
			continue;
		    }
		    
		    if(i==2)
			{			
			cout<<t2<<" ";
			continue;
		    }
		
			nextTerm=t1+t2;
			t1=t2;
			t2=nextTerm;
			cout<<" "<<nextTerm<<" ";
		}
	return 0;
}


