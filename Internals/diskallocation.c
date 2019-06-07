#include<stdio.h>
#include<stdlib.h>
void fcfs()
{
    int q[50],head,qsize,i,diff,seek=0;
    printf("Enter the size of the queue\n");
    scanf("%d",&qsize);
    printf("Enter the elementa to the queue\n");
    for(i=0;i<qsize;i++)
    {
        scanf("%d",&q[i]);
    }
    printf("Enter the head position\n");
    scanf("%d",&head);
    q[0]=head;
    for(i=0;i<qsize-1;i++)
    {
        diff=abs(q[i]-q[i+1]);
        seek+=diff;
        printf("Move from %d to %d with seek %d",q[i],q[i+1],diff);
    }
    printf("Toatal seek time is %d\n",seek);
    printf("Average seek time is %f\n",seek/(float)qsize);
}

void sstf()
{
    int req[50],index[50],a[50],head,hc,min,mini,i,k,mov=0,j=0,n;
    printf("Enter the current position\n");
    scanf("%d",&head);
    hc=head;
    printf("Enter the size of the queue\n");
    scanf("%d",&n);
    printf("Enter the elements \n");
    for(i=0;i<n;i++)
     scanf("%d",&req[i]);
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            index[i]=abs(head-req[i]);
        }
        min=index[0];
        mini=0;
        for(i=1;i<n;i++)
        {
            if(min>index[i])
            {
                min=index[i];
                mini=i;
            }
        }
        a[j]=req[mini];
        j++;
        head=req[mini];
        req[mini]=999;
    }
    printf("Resulting sequence\n");
    printf("%d",hc);
    mov+=abs(hc-a[0]);
    printf("-->%d",a[0]);
    for(i=1;i<n;i++)
    {
        mov+=abs(a[i]-a[i-1]);
        printf("-->%d",a[i]);
    }
    printf("Total seek time is %d",mov);
    printf("Average seek time is %f\n",mov/(float)n);
}

#define high 199
#define low 0

void scan()
{
    int q[50],vis[50],head,max,i,j,qsize,temp,diff=0;
    printf("Enter the size\n");
    scanf("%d",&qsize);
    printf("Enter the elements to the queue\n");
    for(i=0;i<qsize;i++)
    {
        scanf("%d",&q[i]);
        vis[i]=0;
    }
    printf("Enter the head position\n");
    scanf("%d",&head);
    for(i=0;i<qsize-1;i++)
    {
        for(j=i;j<qsize;i++)
        {
            if(q[i]>q[j])
            {
                temp=q[i];
                q[i]=q[j];
                q[j]=temp;
            }
        }
    }
    max=head;
    printf("%d",head);
    for(i=0;i<qsize;i++)
    {
        if(max<q[i])
        {
            temp=abs(max-q[i]);
            diff+=temp;
            printf("-->%d",q[i]);
            max=q[i];
            vis[i]=1;
        }
    }
    printf("-->%d",high);
    diff+=abs(max-high);
    max=high;
    for(i=qsize-1;i>=0;i++)
    {
        if(max>q[i] && !vis[i])
        {
            temp=abs(max-q[i]);
            diff+=temp;
            printf("-->%d",q[i]);
            max=q[i];
            vis[i]=1;
        }
    }
    printf("Total seek time is %d\n",diff);
    printf("Average seek time is %f\n",diff/(float)qsize);
}

void main()
{
    int ch;
    do
    {
        printf("\n1.FCFS\n2.SSTF\n3.SCAN\n4.Exit\nEnter your choice\n");
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
        default: exit(0);
            break;
        }
    } while (ch!=4);
}