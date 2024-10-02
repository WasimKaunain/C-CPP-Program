//Program 11
// Sum of N Natural Numbers

#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"enter value of n"<<endl;
	cin>>n;
	if(n>0)
	cout<<"sum of "<<n<<" consecutive natural numbers is : "<<n*(n-1)/2<<endl;

	return 0;
}


