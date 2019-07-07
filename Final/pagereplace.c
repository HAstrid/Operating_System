#include<stdio.h>
#include <stdlib.h>

void fifo()
{
    int req[20],i,j,count=0,nop,nof,pf=0;
    printf("Enter number of pages\n");
    scnaf("%d",&nop);
    printf("Enter the request string\n");
    for(i=0;i<nop;i++)
    {
        scanf("%d",req[i]);
    }
    printf("Enter the number of frames\n");
    scanf("%d",&nof);
    int frame[nof];
    for(i=0;i<nof;i++)
    {
        frame[i]=-1;
    }
    for(i=0;i<nop;i++)
    {
        count=0;
        for(j=0;j<nof;j++)
        {
            if(req[i]==frame[j])
            {
                count++;
                pf--;
            }
        }
        pf++;
        if(pf <= nof && count ==0)
        {
            frame[i]=req[i];
        }
        else if(count == 0)
        {
            frame[(pf-1)%nof] =req[i];
        }
        for(j=0;j<nof;j++)
         printf("%d",frame[j]);
    }
    printf("Toatl numbe of page faults: %d\n",pf);
}

int findlru(int time[],int n)
{
    int pos=0,min=time[0],i;
    for(i=1;i<n;i++)
    {
        if(min>time[i])
        {
            min=time[i];
            pos=i;
        }
    }
    return pos;
}

void lru()
{
    int nop,nof,i,j,pos=0,count=0,fault=0,page[30],frame[10],time[30],flag1,flag2;
    printf("Enter the number of pages\n");
    scanf("%d",&nop);
    printf("Enter the number of frames\n");
    scanf("%d",&nof);
    printf("Enter the pages\n");
    for(i=0;i<nop;i++)
    {
        scanf("%d",&page[i]);
    }
    for(i=0;i<nof;i++)
    {
        frame[i]=-1;
    }

    for(i=0;i<nop;i++)
    {
        flag1=flag2=0;
        for(j=0;j<nof;j++)
        {
            if(frame[j]== page[i])
            {
                count++;
                time[j]=count;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
            for(j=0;j<nof;j++)
            {
                if(frame[j] == -1)
                {
                    count++;
                    fault++;
                    frame[j]=page[i];
                    time[j]=count;
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0)
        {
            pos=findlru(time,nof);
            count++;
            fault++;
            frame[pos]=page[i];
            time[pos]=count;
        }
        for(j=0;j<nof;j++)
        {
            printf("%d\t",frame[j]);
        }
        printf("\n");
    }
    printf("Total number of page faults %d\n",fault);
}

void optimal()
{
    int i,j,k,nop,nof,page[30],frame[10],temp[30],max,pos=0,flag1,flag2,flag3,fault=0;
    printf("Enter number of pages\n");
    scanf("%d",&nop);
    printf("Enter the number of frames\n");
    scanf("%d",&nof);
    printf("Enter the number of pages\n");
    for(i=0;i<nop;i++)
    {
        scanf("%d",&page[i]);
    }
    for(i=0;i<nof;i++)
    {
        frame[i]=-1;
    }

    for(i=0;i<nop;i++)
    {
        flag1=flag2=0;
        for(j=0;j<nof;j++)
        {
            if(frame[j]==page[i])
            {
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
            for(j=0;j<nof;j++)
            {
                if(frame[j]==-1)
                {
                    fault++;
                    frame[j]=page[i];
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0)
        {
            flag3=0;
            for(j=0;j<nof;j++)
            {
                temp[j]=-1;
                for(k=i+1;k<nop;k++)
                {
                    if(frame[j]==page[k])
                    {
                        temp[j]=k;
                        break;
                    }
                }
            }
            for(j=0;j<nof;j++)
            {
                if(temp[j]==-1)
                {
                    pos=j;
                    flag3=1;
                    break;
                }
            }
            if(flag3==0)
            {
                max=temp[0];
                pos=0;
                for(j=0;j<nof;j++)
                {
                    if(max<temp[j])
                    {
                        max=temp[j];
                        pos=j;
                    }
                }
            }
            frame[pos]=page[i];
            fault++;
        }
        printf("\n");
        for(j=0;j<nof;j++)
        {
            printf("%d\t",frame[j]);
        }
        printf("\n");        
    }
    printf("Total number of page fault is %d",fault);
}

void main()
{
    int ch;
    do
    {
        printf("1.FCFS\n2.SSTF\n3.SCAN\n4.Exit\nEnter your choice: \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            fcfs();
            break;
        case 2:
            sstf();
            break;
        case 3:
            scan();
            break;
        case 4:exit(0);
        default: printf("Invalid choice\n");
            break;
        }
    } while (ch!=4);
}