#include<iostream>
#include<cstdlib>
#include<Windows.h>
using namespace std;

int main()
    {
        string s;
        string h="helloworld";
        char c;
        int i=0;
        while(s!=h)
            {
                while(c!=h[i])
                    {
                        c=(rand() % 26) + 97;
                        cout<<s<<endl;
                        Sleep(10);
                    }
                s=s+c;
                i++;
            }
    }

