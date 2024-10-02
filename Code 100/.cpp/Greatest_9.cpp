//Program 9
// Largets among three numbers

#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	
	 cout<<"Enter three numbers"<<endl;
	 cin>>a>>b>>c;
	 
	 if(a>b)
	   if(a>c)
	    cout<<a<<" is greatest among three"<<endl;
	   else
	    cout<<c<<" is greatest among three"<<endl;
	    
	 else if(b>c)
	    cout<<b<<" is greatest among three"<<endl;
	    
	 else
	 	cout<<c<<" is greatest among three"<<endl;
	 	return 0;
}


