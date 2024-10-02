//Program 24
// to check list of prime numbers between an ineterval


#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

int NoOfFactors(int n)
{

	int primeTable[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
	int count[sizeof(primeTable)/sizeof(primeTable[0])]={0};
	int tableSize=sizeof(primeTable)/sizeof(primeTable[0]);
	
	if(n<=0)
	return -1;
	
	if(n==1)
	return 1;
	
	//cout<<"In for loop..."<<endl<<endl;
	int temp=n;
	for(int i=0;i<tableSize;i++)
		{
	//		cout<<endl<<"Loop for i="<<i<<" , n ="<<n<<" , Prime number ="<<primeTable[i]<<endl;
			
			if(n==1)
			break;
			
			while(n%primeTable[i]==0)
			{
				n/=primeTable[i];
				count[i]++;
	//			cout<<n<<" count="<<count[i]<<endl;
			}	
			
	//		cout<<"Power of "<<primeTable[i]<<" : "<<count[i]<<endl<<endl;	
		}
		
	/*	cout<<"Count Array : ";
		for(int i=0;i<sizeof(count)/sizeof(count[0]);i++)
			cout<<count[i]<<" ";
			
		cout<<endl;
	*/	
		int noOfFactors=1;
		
		for(int i=0;i<sizeof(count)/sizeof(count[0]);i++)
					noOfFactors = noOfFactors*(count[i] + 1);		
					
	//	cout<<"No. of Factors of "<<temp<<" : "<<noOfFactors<<endl;
		return noOfFactors;	
}


int main()
{
	int min,max;
	cout<<"Enter the range in between you want to get prime numbers(Inclusive)"<<endl;
	cin>>min>>max;
	
	int factors=0;
	int primeNumbers[max-min]={0};
	int i=0;
	while(min<=max)
		{
			if(min==2 || min==5 || min%10==1 || min%10==3 || min%10==7 || min%10==9 )
			{
 			factors=NoOfFactors(min);
			if(factors==2)
				{
					primeNumbers[i]=min;
					i++;
				}
			min++;
			}
		    else
				  min++;
		}
		system("CLS");
		cout<<"List of Prime Numbers..."<<endl;
	for(int i=0;primeNumbers[i]!=0;i++)
		cout<<primeNumbers[i]<<" ";
	
	
	return 0;
}


