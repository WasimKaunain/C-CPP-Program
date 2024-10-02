
#include<iostream>
#include<windows.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;
int main()
{
   char name[25];
   cin.getline(name,25);
   cout<<name<<endl;
   return 0;  
}