#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
FILE *fp;
char stmnt[100];

fp=fopen("first_file.txt","w");

if(fp==NULL)
{
  printf("File opening error...\n");
  exit(0);
}

printf("File is now open\n");
printf("Enter what you want to write in file within 100 words\n");
gets(stmnt);

if(strlen(stmnt)>0)
{
fputs(stmnt,fp);
fputs("\n",fp);
}

fclose(fp);
printf("Statement has been saved in disk file\n");
char ch;
printf("Enter any key to exit...");
scanf("%c",&ch);
}