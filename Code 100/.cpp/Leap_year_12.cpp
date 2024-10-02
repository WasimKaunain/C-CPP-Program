//Program 12
// Check Leap Year

#include<iostream>
using namespace std;

int main()
{
	int year;
	cout<<"Enter any year"<<endl;
	cin>>year;
	
	if (year%4==0 )
		if(year%400!=0 && year%100==0)
			cout<<"It is not a Leap year"<<endl;
		else
			cout<<"It is a Leap year"<<endl;
	
		
	else
	cout<<"It is not a Leap Year"<<endl;
	return 0;
}


