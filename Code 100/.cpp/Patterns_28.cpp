//Program 28
//This cpp code prints different types of patterns

#include<iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define UNDERLINE_ON "\033[4m"
#define UNDERLINE_OFF "\033[0m"

void HalfPyramidUsingStar()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;

        for (int i=1; i<=n; i++)
        {
            for(int j=1;j<=n;j++)
                {
                    if(j<=i)
                     cout<<"* ";
                    else
                     cout<<" ";
                }
                cout<<endl;
        }        
    }

void HalfPyramidUsingNumber()
    {
        
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;

        for (int i=1; i<=n; i++)
        {
            for(int j=1;j<=n;j++)
                {
                    if(j<=i)
                     cout<<j<<" ";
                    else
                     cout<<" ";
                }
                cout<<endl;
        }        
    
    }

void HalfPyramidUsingAlphabet()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;
        char ch;
        for (int i=1; i<=n; i++)
        {
            ch='A';
            for(int j=1;j<=n;j++)
                {
                    if(j<=i)
                    {
                     cout<<ch<<" ";
                     ch++;
                    }
                    else
                     cout<<" ";
                }
                cout<<endl;
        }        
    }

void InvertedHalfPyramidUsingStar()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;

        for (int i=1; i<=n; i++)
        {
            for(int j=1;j<=n;j++)
                {
                    if(j<=n-i)
                     cout<<"* ";
                    else
                     cout<<" ";
                }
                cout<<endl;
        }
    }

void InvertedHalfPyramidUsingNumber()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;

        for (int i=0; i<n; i++)
        {
            for(int j=1;j<=n;j++)
                {
                    if(j<=n-i)
                     cout<<j<<" ";
                    else
                     cout<<" ";
                }
                cout<<endl;
        }
    }

void FullPyramidUsingStar()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;
        int k;
        for (int i=0; i<=n; i++)
        {
            k==1;
            for(int j=0;j<=2*n;j++)
                {
                    if(j>=n-i && j<=i+n && k)
                    {
                     cout<<"*";
                     k=0;
                    }
                    else
                    {
                     cout<<" ";
                     k=1;
                    }
                }
                cout<<endl;
        }
    }

void FullPyramidUsingNumber()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;
        int k;
        for (int i=0; i<=n; i++)
        {
            k==1;
            for(int j=0;j<=2*n;j++)
                {
                    if(j>=n-i && j<=i+n && k)
                    {
                     cout<<j;
                     k=0;
                    }
                    else
                    {
                     cout<<" ";
                     k=1;
                    }
                }
                cout<<endl;
        }
    }

void InvertedFullPyramidUsingStar()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;
        int k;
        for (int i=0; i<=n; i++)
        {
            k==1;
            for(int j=0;j<=2*n;j++)
                {
                    if(j>=i && j<2*n-i && k)
                    {
                     cout<<"*";
                     k=0;
                    }
                    else
                    {
                     cout<<" ";
                     k=1;
                    }
                }
                cout<<endl;
        }
    }

void PascalsTriangle()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;
        int val;
        for (int i=0; i<n; i++)
        {
            val = 1;
            for(int j=1;j<(n-i);j++)
                {
                    cout<<"  ";
                }
            for(int k=0;k<=i;k++)
                {
                    cout<<"  "<<setw(2)<<setfill('0')<<val;
                    val=val*(i-k)/(k+1);
                }
                cout<<endl<<endl;
        }
    }

void FloydsTriangle()
    {
        int n;
        cout<<"Enter No. of Rows : ";
        cin>>n;
        int val=1;
        for (int i=1; i<=n; i++)
        {
            for(int j=1;j<=n;j++)
                {
                    if(j<=i)
                    {
                     cout<<setw(2)<<setfill('0')<<val<<"  ";
                     val++;
                    }
                    else
                     cout<<" ";
                }
                cout<<endl;
        }
    }


int main()
{   
    
    HANDLE console_color;
    int P=12,choice;
    console_color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color,P);

    system("CLS");
    
    cout<<"\t\t\t\t\t\t\tW E L C O M E   T O   P A T T E R N   W O R L D"<<endl<<endl<<endl;
    cout<<UNDERLINE_ON<<"\t\t\t\t\t\t\tCHOOSE WHAT TYPE OF PATTERN YOU WANT TO CREATE"<<endl;
    //cout<<"\t\t\t\t\t\t\t----------------------------------------------"<<endl<<endl;
    cout<<UNDERLINE_OFF;

    cout<<"1)   Print Half Pyramid using *"<<endl<<endl;
    cout<<"2)   Print Half Pyramid using Numbers"<<endl<<endl;
    cout<<"3)   Print Half Pyramid using Alphabet"<<endl<<endl;
    cout<<"4)   Print Inverted Half Pyramid using *"<<endl<<endl;
    cout<<"5)   Print Invered Half Pyramid using Numbers"<<endl<<endl;
    cout<<"6)   Print Full Pyramid using *"<<endl<<endl;
    cout<<"7)   Print Full Pyramid using Numbers"<<endl<<endl;
    cout<<"8)   Print Inverted Full Pyramid using *"<<endl<<endl;
    cout<<"9)   Print Pascal's triangle"<<endl<<endl;
    cout<<"10)  Print Floyd's triangle *"<<endl<<endl<<endl<<endl;
    cout<<endl<<"Enter 0 (Zero) to exit the program"<<endl<<endl;

    cout<<"\t\t\t\t\t\t\tE N T E R    Y O U R    C H O I C E...";

    cin>>choice;
    
    switch (choice)
     {
        case 1:system("CLS");
                HalfPyramidUsingStar();
                break;

        case 2:system("CLS");
                HalfPyramidUsingNumber();
                break;
        case 3:system("CLS");
                HalfPyramidUsingAlphabet();
                break;
        case 4:system("CLS");
                InvertedHalfPyramidUsingStar();
                break;
        case 5:system("CLS");
                InvertedHalfPyramidUsingNumber();
                break;
        case 6:system("CLS");
                FullPyramidUsingStar();
                break;
        case 7:system("CLS");
                FullPyramidUsingNumber();
                break;
        case 8:system("CLS");
                InvertedFullPyramidUsingStar();
                break;
        case 9:system("CLS");
                PascalsTriangle();
                break;
        case 10:system("CLS");
                FloydsTriangle();
                break;

        default:system("CLS");
                    cout<<"I N V A L I D   I N P U T"<<endl;

        case 0: exit(0);
     
     
     }
    

    return 0;
}