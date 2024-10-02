#include<stdio.h>
#include<stdlib.h>

void Add(FILE *fp)
{
        char keyword[10];
        printf("Enter the keyword that you want to add\n");
        scanf("%s",&keyword);

        fp=fopen("keyword.txt","a");

        if(fp==NULL)
        {
            printf("File not opened...\n");
            exit(0);
        }

        fprintf(fp,%s,keyword);
        fclose(fp);
        
}

int Verify(FILE *fp)
{
    char keyword[10];
    char word[10];
    int flag=0;

    fp=fopen("keyword.txt","r");

    if(fp==NULL)
    {
        printf("File not opened...\n");
        exit(0);
    }

    printf("Enter the keyword that you want to verify\n");
    scanf("%s",&word);

            while(fscanf(fp,%s,keyword)!=EOF)
                {
                    if(word==keyword)
                        flag++;
                }
        fclose(fp);
    return(flag);

}

void main()
{
    FILE *fp;
    char keyword[10];
    int  choice,flag;
    
    printf("\n1) To add keywords\n2) To verify keywords\n3) To exit\n");
    scanf("%d",&choice);

    

    switch(choice)
    {
        case 1: Add(fp);
                break;

        case 2: flag=Verify(fp);
                if(flag==1)
                  printf("Keyword matched successfully...\n");
                else
                 printf("Keyword not found...\n");
                break;

        case 3: exit(0);

        default: printf("Invalid choice...\n");
    }
    }