//Program 6
// Swap Two Numbers

#include<iostream>
using namespace std;

swap(int *a,int *b)
{
	*a=*a + *b;
	*b=*a - *b;
	*a=*a - *b;
}

int main()
{
	int a,b;
	cout<<"Enter the values of a and b"<<endl;
	cin>>a>>b;
	
	swap(&a,&b);
	cout<<"After Swapping :"<<endl<<"a	= "<<a<<endl<<"b	= "<<b;
	return 0;
}


