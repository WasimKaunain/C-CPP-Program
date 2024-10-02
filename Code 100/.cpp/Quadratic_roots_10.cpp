//Program 10
// Roots of quadratic equation

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	float a,b,c;
	float value1,value2;
	float D;
	cout<<"Eneter valiue of a,b,c"<<endl;
	cin>>a>>b>>c;
	
	D = b*b - 4*a*c;
	cout<<"Value of D : "<<D<<endl;
	if(D>0)
		{
			value1= (-b + sqrt(D))/2*a;
			
			value2= (-b - sqrt(D))/2*a;
			cout<<"Value1	: "<<value1<<endl<<"Value2	: "<<value2<<endl; 
		}
		
	else if(D==0)
		{
			value1=-b/2*a;
			value2=value1;	
			cout<<"Value1	: "<<value1<<endl<<"Value2	: "<<value2<<endl; 
		}
		
	else
		{
			cout<<"Value1	: "<<-b/2*a<<" + i"<<sqrt(-D)/2*a<<endl;
			cout<<"Value1	: "<<-b/2*a<<" - i"<<sqrt(-D)/2*a<<endl;			
		}
	
	return 0;
}


