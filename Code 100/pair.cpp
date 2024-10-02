#include<iostream>
using namespace std;

int main()
{
    int x,y;
    pair <int,int> points[5];
    for(int i=0;i<5;i++)
        {
            cin>>x>>y;
            points[i]=make_pair(x,y);
        }

    for(int i=0;i<5;i++)
        cout<<"("<<points[i].first<<","<<points[i].second<<")   ";

}