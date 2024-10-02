//Program 33
//binary to Decimal convertor

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
                 
void binToDecimal()
    {
        string number;
        cout<<"Enter any binary number  : ";
        cin>>number;
    
        int size=number.length();
        
        int decimal=0;
        
        for(int i=size-1;i>=0;i--)
            decimal = decimal + (number[i]-48)*pow(2,size-1-i);
                
        cout<<"Decimal Value is : "<<decimal;
    }

void decimalToBin()
    {
        int number;
        cout<<"Enter any Decimal number  : ";
        cin>>number;
        int val;
        string binary;
        while(number!=1)
            {   
                val=number%2;
                if(val==0)
                    binary +='0';
                else
                    binary +='1';
                number/=2;
            }
        binary+='1';

        char temp;
        
        for(int i=0;i<binary.length()/2;i++)
            {
                temp=binary[i];
                binary[i]=binary[binary.length()-1-i];
                binary[binary.length()-i-1]=temp;
            }

        cout<<"Binry Value is : "<<binary;
    }

int main()
{
    int choice;

    cout<<"1) Binary to Decimal"<<endl;
    cout<<"2) Decimal to Binary"<<endl;
    cin>>choice;

    switch(choice)
        {
            case 1: binToDecimal();
                    break;

            case 2: decimalToBin();
                    break;

            default:cout<<"Invalid choice..."<<endl;
        }
    
    return 0;
}