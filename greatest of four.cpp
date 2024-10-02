#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four(int a,int b,int c,int d)
    {
        int max;
        
        if(a>b)
            {
                if(a>c)
                    {
                        if(a>d)
                        max=a;
                        else 
                        max=d;
                    }
                    printf("First if block passed\n");
            }
            
        else if(b>c)
            {
                if(b>d)
                max=b;
                else 
                max=d;
                
                printf("Second if block passed\n");
            }
            
        else if(c>d)
        {
        max=c;
        printf("Third if block passed\n");
        }
        
        else
        { 
        max=d;
        }
        
        return(max);
     }
     
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}̥