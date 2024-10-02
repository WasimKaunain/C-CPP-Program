//Program 34
//Octal to Decimal convertor and vice versa

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
                 
void OctalToDecimal()
    {
        string number;
        cout<<"Enter any Octal number  : ";
        cin>>number;
    
        int size=number.length();
        
        int decimal=0;
        
        for(int i=size-1;i>=0;i--)
            decimal = decimal + (number[i]-48)*pow(8,size-1-i);
                
        cout<<"Decimal Value is : "<<decimal;
    }

void decimalToOctal()
    {
        int number;
        cout<<"Enter any Decimal number  : ";
        cin>>number;
        int count=0;
        int octal=0;
        int temp;
        while(number>0)
            { 
                octal = octal + number%8 * pow(10,count);
                number/=8;
                count++;
            }
        
        cout<<"Octal Value is : 0"<<octal;
    }

int main()
{
    int choice;

    cout<<"1) Octal to Decimal"<<endl;
    cout<<"2) Decimal to Octal"<<endl;
    cin>>choice;

    switch(choice)
        {
            case 1: OctalToDecimal();
                    break;

            case 2: decimalToOctal();
                    break;

            default:cout<<"Invalid choice..."<<endl;
        }
    
    return 0;
}