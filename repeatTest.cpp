#include<iostream>
using namespace std;

int main()
{   int x;
    int arr[10];
    cout<<"Enter the array values :"<<endl;
    for(int i=0;i<10;i++)
    cin>>arr[i];
    
    int temp[10];
    
    temp[0]=arr[0];
    for(int i=1;i<10;i++)
    {
        temp[i]=arr[i];
      for(int j=i;j>0;j--)
        if(temp[i]==arr[j-1])
        {
            cout<<"First repeated element is : "<<arr[j-1]<<" and its occurences are : "<<j-1<<" and "<<i<<endl;
            return 0;
        }
    }
    return 0;
}