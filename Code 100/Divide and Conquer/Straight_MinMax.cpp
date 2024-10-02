#include<iostream>
using namespace std;

typedef struct
    {
        int max;
        int min;
    } checker;

checker a;

void MaxMin(int A[],int size)
    {
        a.max=A[0];
        a.min=A[0];

        for(int i=1;i<size;i++)
            {
                if(A[i] > a.max)
                    a.max=A[i];
                else if(A[i]<a.min)
                    a.min=A[i];
            }

    }

int main()
    {   cout<<"Enter the size of array"<<endl;
        int size;
        cin>>size;
        
        int A[size];
        cout<<"Enter the values one by one"<<endl;
        for(int i=0;i<size;i++)
                cin>>A[i];
        cout<<"The array is : ";
        for(int i=0;i<size;i++)
                cout<<A[i]<<"\t";
        MaxMin(A,size);

        cout<<endl<<"Maximum Value : "<<a.max<<" Minimum Value : "<<a.min<<endl;

        return 0;
    }