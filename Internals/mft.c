#include<stdio.h>

void main()
{
    int i,ms,bs,n,nob,sp[10];
    int tif=0,p=0,ef;
    printf("Enter the memeory space available\n");
    scanf("%d",&ms);
    printf("Enter the block size\n");
    scanf("%d",&bs);
    nob=ms/bs;
    ef=ms-(nob*bs);
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the size of each process\n");
    for(i=0;i<n;i++)
    {
        printf("%d:\t",i+1);
        scanf("%d",&sp[i]);
    }
    printf("Number of blocks: %d\n",nob);
    printf("\nProcess\t Memory Require\t Memory Available\t Internal Fragmentation\n");
    for(i=0;i<n && p<nob;i++)
    {
        printf("%d\t\t%d\t\t",i+1,sp[i]);
        if(sp[i]>bs)
        {
            printf("No\t\t--\n");
        }
        else
        {
            printf("Yes\t\t%d\n",bs-sp[i]);
            tif+=bs-sp[i];
            p++;
        }
    }
    if(i<n)
     printf("Memory full,process cannot be allocated\n");
    printf("Total Internal Fragmentation %d\n",tif);
    printf("External Fragmentation id %d\n",ef);
}