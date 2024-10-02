#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    string name;
    string password;
    char ch;
    

    cout<<"Enter your name"<<endl;
    cin>>name;


    cout<<"Enter your Password"<<endl;
    while((ch=getch())!=13)
    {
        if(ch>32)
        {
            cout<<"*";
            password.push_back(ch);
        }

        if(ch==8 && password.size()!=0)
        {
            password.pop_back();
            cout<<"\b \b";
        }

    }

    cout<<endl<<"Name : "<<name<<endl;
    cout<<"Password : "<<password<<endl;

}