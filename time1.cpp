#include<iostream>
#include<ctime>
#include<string>
using namespace std;

int main()
{
    time_t t=time(0);
    struct tm* now=localtime(&t);
    cout<<now->tm_mday<<"-"<<now->tm_mon<<"-"<<now->tm_year<<" "<<now->tm_hour<<":"<<now->tm_min<<":"<<now->tm_sec;
    return 0;
}