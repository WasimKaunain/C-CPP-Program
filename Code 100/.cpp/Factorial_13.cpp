//Program 13
// Factorial

#include<iostream>
using namespace std;

int factorial(int n)
	{
		if(n==1)
		return 1;
		
		return(n*factorial(n-1));
	}
	
int main()
{
	int n;
	cout<<"Enter any positive integer to get its factorial"<<endl;
	cin>>n;
	
	cout<<"Factorial of "<<n<<" is	: "<<factorial(n)<<endl;
	return 0;
}


