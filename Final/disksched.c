#include<stdio.h>
#include<stdlib.h>

void fcfs()
{
    int i,j,head,seek=0,que[100],qs,diff=0;
    printf("Enter the queue size\n");
    scanf("%d",&qs);
    printf("Enter the queue elements\n");
    for(i=0;i<qs;i++)
    {
        scanf("%d",&que[i]);
    }
    printf("Enter the head position\n");
    scanf("%d",&head);
    que[0]=head;
    for(j=1;j<qs;j++)
    {
        diff=abs(que[j]-que[j+1]);
        seek+=diff;
        printf("Move from %d to %d with seek %d\n",que[j],que[j+1],diff);
    }
    printf("Total seek time is %d\n",seek);
    printf("Average seek time is %f\n",seek/(float)qs);
}

void sstf()
{
    int i,k,j=0,n,head,headc,pos,req[100],index[100],a[100],diff=0,min;
    printf("Enter the current position of head\n");
    scanf("%d",&head);
    headc=head;
    printf("Enter the queue size\n");
    scanf("%d",&n);
    printf("Enter the queue elments\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            index[i]=abs(head-req[i]);
        }
        min=index[0];
        pos=0;
        for(i=1;i<n;i++)
        {
            if(min>index[i])
            {
                min=index[i];
                pos=i;
            }
        }
        a[j]=req[pos];
        j++;
        headc=req[pos];
        req[pos]=999;
    }
    printf("Sequence is \n");
    printf("%d",headc);
    diff+=abs(headc-a[0]);
    printf("-->%d",a[0]);
    for(i=1;i<n;i++)
    {
        diff+=abs(a[i]-a[i-1]);
        printf("-->%d",a[i]);
    }
    printf("Total seek time is %d",diff);
    printf("Average seek time is %f\n",diff/(float)n);
}

#define high 199
#define low 0
void scan()
{
    int qs,que[100],vis[100],head,max,i,j,temp,diff=0;
    printf("Enter the sizze of queue\n");
    scanf("%d",&qs);
    printf("Enter the elememts to the queue\n");
    for(i=0;i<qs;i++)
    {
        scanf("%d",&que[i]);
        vis[i]=0;
    }
    printf("Enter the head position\n");
    scanf("%d",&head);

    for(i=0;i<qs-1;i++)
    {
        for(j=i;j<qs;j++)
        {
            if(que[i]>que[j])
            {
                temp=que[i];
                que[i]=que[j];
                que[j]=temp;
            }
        }
    }
    max=head;
    printf("%d",head);
    for(i=0;i<qs;i++)
    {
        if(max<que[i])
        {
            temp=abs(max-que[i]);
            diff+=temp;
            printf("-->%d",que[i]);
            max=que[i];
            vis[i]=1;
        }
        printf("-->%d",high);
        diff+=abs(high-max);
        max=high;
        for(i=qs-1;i>=0;i--)
        {
            if(max>que[i])
            {
                temp=abs(max-que[i]);
                diff+=temp;
                printf("-->%d",que[i]);
                max=que[i];
                vis[i]=1;
            }
        }
        printf("Total seek time is %d",diff);
        printf("Average seek time is %f\n",diff/(float)qs);
    }
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