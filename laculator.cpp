#include<iostream> 
#include<Windows.h>
#include<unistd.h>

using namespace std;

int main()
{
    float A,B;
    char op;
    int choice;
    while(1)
    {
    START:
    //system("CLS");
    cout<<"\t\t\t\t\t\t\t\t  C A L C U L A T O R"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\tWELCOME TO CALCULATOR PROJECT"<<endl;
    cout<<"Enter 1 to START and 0 to EXIT"<<endl;
    cin>>choice;

    if(choice==1)
    {
         cout<<"Enter First number"<<endl;
         cin>>A;
     
         cout<<"Enter second number"<<endl;
         cin>>B;
     

        cout<<"Sum is   : "<<A+B<<endl;
        cout<<"Subtract is   : "<<A-B<<endl;
        cout<<"Multiply is   : "<<A*B<<endl;
        cout<<"Divide is   : "<<A/B<<endl;

         /*cout<<"Enter operation  : ";
         cin>>op;
     
         switch(op)
         {
                 case '+': cout<<" Addition is  : "<<A+B<<endl;
                           break;
     
                 case '-': cout<<" Subtraction is  : "<<A-B<<endl;
                           break;
     
                 case '*': cout<<" Multiplication is  : "<<A*B<<endl;
                           break;
     
                 case '/': cout<<" Division is  : "<<A/B<<endl;
                           break;
     
                 default:  cout<<"Invalid operation"<<endl;
                           
         }
         //Sleep(5000);
         */
     }

     else if(choice==0)
        exit (0);

        else
        {
        cout<<"Invalid choice"<<endl;
        goto START;
        }
    }
    return 0;
}