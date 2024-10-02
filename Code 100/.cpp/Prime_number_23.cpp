//Program 23
// To check whether a number is prime or not

#include<iostream>
using namespace std;


int NoOfFactors(int n)
{

	int primeTable[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
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
	int n;
	cout<<"Enter any natural integer to check whether it is prime or not :";
	cin>>n;
	
	int noOfFactor;
	
	noOfFactor = NoOfFactors(n);
	
	if(noOfFactor==-1)
		cout<<"Please enter a Natural number "<<endl;
	
	if(noOfFactor==1)
		{
			if(n<101)
			cout<<"It is neither a prime number nor a non-prime number"<<endl;
			else
			cout<<"Yes,It is a prime number"<<endl;
		}
		
		
	
	else if(noOfFactor==2)
		cout<<"Yes, It is a prime number"<<endl;
	else
		cout<<"No, It is not a prime number"<<endl;
	
	
	return 0;
}


