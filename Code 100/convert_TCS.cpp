
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int Conversion(int n,string A,string B)
    {
        vector<int> index;
        string substr=" ";
        int flag,opCount=0,sub_str_size;
        char temp;

        for(int i=0;i<n;i++)
            {
                flag=0;
                for(int j=0;j<n;j++)
                    {
                        if(A[i]==B[j])
                            flag++;
                    }
                if(flag==0)
                return -1;
            }

        for(int i=0;i<n;i++)
            {
                flag=0;
                for(int j=0;j<n;j++)
                    {
                        if(B[i]==A[j])
                            flag++;
                    }
                if(flag==0)
                return -1;
            }

        while(A!=B)
            {
                substr=" ";
                index.clear();
                
                cout<<"Loop started for operation"<<opCount<<"..."<<endl;
                for(int i=0;i<n;i++)
                    {
                        if(A[i]!=B[i])
                        {
                            index.push_back(i);
                            substr+=A[i];
                        }
                    }

                temp=substr[0];

                for(int i=1;i<substr.size();i++)
                    {
                        if(temp>substr[i])
                            temp=substr[i];
                    }
                    
                sub_str_size=substr.size();
                substr=" ";

                substr.insert(0,sub_str_size,temp);

                int j=0;
                while(sub_str_size--)
                    {
                        A[index[j]]=substr[j];
                        j++;
                    }

                 opCount++;
            }

            return opCount;
    }       


int main()
{
    int N;
    string A,B;

    cout<<"enter size of string\n";
    cin>>N;
    cout<<endl<<"Enter first string\n";
    cin>>A;
    cout<<endl<<"Enter second string\n";
    cin>>B;
    cout<<endl;

    int result=Conversion(N,A,B);

    if(result==-1)
        cout<<"These strings can't be matched...\n";
    else if(result==0)
        cout<<"Strings are already same...\n";
    else
        cout<<"Minimum no. of operations to match these strings is : "<<result;

    return 0;
}


