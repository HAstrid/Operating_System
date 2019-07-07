#include<stdio.h>
#include<stdlib.h>
#define max 10

void main()
{
    int f[max],index[max],start,count,i,j,k,c,n;
    for(i=0;i<max;i++)
    {
        f[i]=0;
    }
    x:printf("Enter the starting block of file:\n");
    scanf("%d",&start);
    if(f[start]!=1)
    {
        printf("Enter the number of blocks\n");
        scanf("%d",&n);
        if(n>=max)
        {
            printf("Number of blocks exceed the size\n");
            exit(0);
        }
    }
    else
    {
        printf("Starting block has already been allocated, enter valid bllock\n");
        goto x;
    }
    f[start]=1;
    y:count=0;
    for(i=0;i<n;i++)
    {
        printf("Enter the blocks for %d\n",i+1);
        scanf("%d",&index[i]);
        if(f[index[i]]==0)
         count++;
    }
    if(count==n)
    {
        for(j=0;j<n;j++)
        {
            f[index[j]]=1;
        }
        printf("File has been allocated\n");
        printf("Indexes are: \n");
        printf("\nstart>>%d",start);
        for(k=0;k<n;k++)
        {
            printf("-->%d",index[k]);
        }
        printf(">>end\n");
    }
    else
    {
        printf("The block cannot be allocated as it is already been allocated\n");
        printf("Enter again\n");
        goto y;
    }
    printf("Do you want to add files?(Yes-1/No-0)\n");
    scanf("%d",&c);
    if(c==1)
     goto x;
    else
    {
        exit(0);
    }
}