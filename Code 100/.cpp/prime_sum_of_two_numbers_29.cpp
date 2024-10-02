//Program 29
//This cpp code tell whether a number can be expressed as a sum of two prime numbers or not


#include<iostream>
#include<vector>
#include<Windows.h> 
using namespace std;

typedef struct 
    {
        vector<int> pairs;
    } Pairs;

bool Prime(int n)
{

	int primeTable[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
	int count[sizeof(primeTable)/sizeof(primeTable[0])]={0};
	int tableSize=sizeof(primeTable)/sizeof(primeTable[0]);

	for(int i=0;i<tableSize;i++)
		{	
			while(n%primeTable[i]==0)
			{
				n/=primeTable[i];
				count[i]++;
			}			
		}
			
		int noOfFactors=1;
		
		for(int i=0;i<sizeof(count)/sizeof(count[0]);i++)
					noOfFactors = noOfFactors*(count[i] + 1);		
					
		if(noOfFactors==2)
            return(true);
        else
            return(false);
}


Pairs Check(int n)
    {
        Pairs p;

        for(int i=2;i<n/2;i++)
            {
                if(Prime(n-i))
                   if(Prime(i))
                   {
                    p.pairs.push_back(n-i);
                    p.pairs.push_back(i);
                   }
            }
        return p;
    }

int main()
{
    int n;
    system("CLS");
    cout<<"Enter any number : ";
    cin>>n;

    Pairs result = Check(n);

    if(result.pairs.size()==0)
        cout<<"Sorry, This number cannot be represented as a sum of two prime numbers";

    else
    {
        if(result.pairs.size()==2)
        {
            cout<<"Yes, This number can be represented as a sum of two prime numbers"<<endl;
            cout<<"("<<result.pairs[0]<<","<<result.pairs[1]<<")"<<endl;
        }
        else
            {
                int Size=result.pairs.size();
                cout<<"Yes, This number can be represented as a sum of "<<result.pairs.size()/2<<" pairs of prime numbers"<<endl;
                for(int i=0;i<Size;i++)
                {
                    cout<<"("<<result.pairs[i]<<","<<result.pairs[i+1]<<")"<<endl;
                    i++;
                }
            }
    }
    return 0;
}