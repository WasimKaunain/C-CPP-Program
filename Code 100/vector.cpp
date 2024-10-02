#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
    {
        vector <int> A;
        set <int> B;
        
        A.push_back(2);
        A.push_back(3);
        A.push_back(4);
        A.push_back(2);
        A.push_back(0);
        A.push_back(0);
        A.push_back(4);
        A.push_back(5);
        A.push_back(10);

        for(int i=0;i<A.size();i++)
            cout<<A[i];
            cout<<endl;

        for(int i=0;i<A.size();i++)
            B.insert(A[i]);

            cout<<"Number of unique elements :"<<B.size();

    }