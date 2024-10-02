#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
FILE *fp;
char stmnt[50];

fp=fopen("lyrics.txt","r");

if(fp==NULL)
{
  printf("File opening error...\n");
  exit(0);
}

printf("File is now open\n");

while(fgets(stmnt,50,fp)!=NULL)
{
printf("%s",stmnt);
}

fclose(fp);

}