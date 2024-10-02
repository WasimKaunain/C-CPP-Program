//Program 8
// Vowel or consonant

#include<iostream>
using namespace std;

int main()
{
	char ch;
	cout<<"Enter any alphabet"<<endl;
	cin>>ch;
	
	if(ch>=65 && ch<=122)
	{
		if(ch=='A' || ch=='a'  || ch=='E' || ch=='e' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='U' || ch=='u')
			cout<<"It is a Vowel alphabet"<<endl;
		else
			cout<<"It is a consonant alphabet"<<endl;
    }

	else
	cout<<"Invalid alphabet"<<endl;
	
	return 0;
}


