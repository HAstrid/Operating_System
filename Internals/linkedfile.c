#include<stdio.h>
#include<stdlib.h>
#define max 20
void main()
{
    int f[max],index[max],i,j,k,in,n,c,count=0;
    for(i=0;i<max;i++)
    {
        f[i]=0;
    }
    x:printf("Enter the index of the file\n");
    scanf("%d",&in);
    if(f[in]!=1)
    {
        printf("Enter the number of blocks to allocate\n");
        scanf("%d",&n);
        if(n>=max)
        {
            printf("Block value exceeds the size\n");
            exit(0);
        }
    }
    else
    {
        printf("File index is already allocated\n");
        goto x;
    }
    f[in]=1;
    y:count=0;
    for(i=0;i<n;i++)
    {
        printf("Enter for block %d \t",i+1);
        scanf("%d",&index[i]);
        if(f[index[i]]==0)
        {
            count++;
        }
    }
    if(count==n)
    {
        for(j=0;j<n;j++)
        {
            f[index[j]]=1;
        }
        printf("Allocated\n");
        printf("File indexed\n");
        printf("start>>\t%d",in);
        for(k=0;k<n;k++)
        {
            printf("-->%d",index[k]);
        }
        printf(">>end\n");
    }
    else
    {
        printf("File index already allocated\n");
        printf("Enter new index\n");
        goto y;
    }
    printf("Do you want to enter more files?(yes 1/no 0)");
    scanf("%d",&c);
    if(c==1)
     goto x;
    else
    {
        exit(0);
    }
}