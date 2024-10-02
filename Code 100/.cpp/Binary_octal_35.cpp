//Program 35
//Octal to Binary convertor and vice versa

#include<iostream>
#include<string>
#include<cmath>
#include<Windows.h>
using namespace std;


void OctalToBinary()
    {
        int octal,Decimal=0;
        cout<<"Enter any Octal number  : ";
        cin>>octal;
        
        string Binary;
        
        for(int i=0;octal!=0;i++)
            {
                Decimal+=octal%10 * pow(8,i);
                octal/=10;
            }
            
        for(int i=0;Decimal!=0;i++)
            {
                if(Decimal%2==1)
                    Binary+='1';
                else
                    Binary+='0';
                Decimal/=2;
            }
        

        cout<<"Binary Value is :";
        for(int i=Binary.length()-1;i>=0;i--)
            cout<<Binary[i];
    }

void BinaryToOctal()
    {
        long long Binary,Decimal=0,Octal=0;
        cout<<"Enter any Binary number  : ";
        cin>>Binary;

        for(int i=0;Binary!=0;i++)
            {
               Decimal+= Binary%10 * pow(2,i);
               Binary/=10;
            }

            cout<<"Decimal Value is : "<<Decimal<<endl;

        for(int i=0;Decimal>0;i++)
            {
                Octal+=Decimal%8*pow(10,i);
                Decimal/=8;
            }

        cout<<"Octal No. "<<Octal;
    }

int main()
{
    int choice;
while(1)
{
    system("CLS");
    cout<<"1) Octal to Binary"<<endl;
    cout<<"2) Binary to Octal"<<endl;
    cout<<"3) Exit"<<endl;
    cin>>choice;
    
    switch(choice)
        {
            case 1: OctalToBinary();
                    break;

            case 2: BinaryToOctal();
                    break;

            case 3: exit(0);

            default:cout<<"Invalid choice..."<<endl;
        }
        cout<<endl<<endl<<"Enter 1 to continue..."<<endl;
        int num;
        cin>>num;
}  
    return 0;
}