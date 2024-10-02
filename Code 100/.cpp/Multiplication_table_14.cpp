//Program 14
// Generate Multiplication Table

#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter any no. whose multiplication table you want "<<endl;
	cin>>n;
	
	cout<<"M U L T I P L I C A T I O N    T A  B L  E    O F   "<<n<<endl<<endl;
	for(int i=1;i<11;i++)
	cout<<n<<"	*	"<<i<<"	=	"<<n*i<<endl;
	return 0;
}


