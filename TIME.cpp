#include<iostream>
#include<ctime>
#include<string>
#include<unistd.h>
#include<Windows.h>
using namespace std;

struct tm* Time()
{
   time_t t;
   time(&t);
   return(localtime(&t));
}

int main()
{
    //struct tm time1;
    while(1)
    {
    cout<<asctime(Time())<<endl;
    Sleep(1000);
    system("CLS");
    }
    return 0;
}