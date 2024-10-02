#include<iostream>
#include<cstdlib>
using namespace std;

int main()
    {
        string s="0";
        string h="helloworld";
        char c;
        int i=0;
        while(s!=h)
            {
                while((c!=h[i]) 
                    {
                        c=(rand() % 26) + 97;
                        cout<<s;
                    }
                s=s+c;
                i++;
            }
    }

