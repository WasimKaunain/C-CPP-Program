#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct number
{
  int num1,num2,num3;
};

void main()
{
    FILE *fp;
    int i;
    struct number num;

    if(fp=fopen("Num.txt","wb")==NULL)
    {
      printf("File opening error\n");
      exit(1);
    }

    
    for(i=1;i<5;++i)
     {
         number.num1=i;
         number.num2=5*i;
         number.num3=5*i + 1;
     
        fwrite(&number,sizeof(struct num),1,fp);
     }

     fclose(fp);
     

}