#include<iostream>
using namespace std;

typedef struct 
 {
    char firstnode;
    char secondnode;
    int  weight;
 } Edge;


bool EdgeInMST(Edge edgeset[],string edge)
    {
        typedef struct 
        {
            int weight;
            char secondnode;
        } min;
        min minimum;

        minimum.weight=10000;
    
        for(int i=0;i<11;i++)
            {
                if(edge[0]==edgeset[i].firstnode)
                    {
                        if(edgeset[i].weight < minimum.weight)
                        {
                            minimum.weight=edgeset[i].weight;
                            minimum.secondnode=edgeset[i].secondnode;
                        }
                    }
            }

        cout<<"SecondNode :"<<minimum.secondnode<<" Minimum Weight :"<<minimum.weight<<endl;

        if (minimum.secondnode==edge[2])
            return true;
        else
            return false;
    }

 int main()
 {
    int vertexno,edgeno;
    cout<<"Enter the no. of vertex :"<<endl;
    cin>>vertexno;
    char vertexset[vertexno];

    for(int i=0;i<vertexno;i++)
        {
            vertexset[i]='A' + i;
        }

    cout<<"Enter the no. of edges :"<<endl;
    cin>>edgeno
    ;
    cout<<"Enter the edges details...: "<<endl;
    Edge edgeset[edgeno];

    for(int i=0;i<edgeno;i++)
        {
            cin>>edgeset[i].firstnode;
            cin>>edgeset[i].secondnode;
            cin>>edgeset[i].weight;
        }
    string edge;
    cout<<"Enter the edge to be check..."<<endl;
    cin>>edge;
    cout<<"The edge is present :"<<EdgeInMST(edgeset,edge);
    return 0;
 }