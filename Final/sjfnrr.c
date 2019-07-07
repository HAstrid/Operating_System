#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sjf()
{
    int i,j,k=1,n,at[10],bt[10],wt[10],tat[10],p[10]={1,2,3,4,5,6,7,8,9,10};
    int btime=0,min,ct;
    float awt=0,atat=0,sumwt=0,sumtat=0;

    printf("Enter the number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time %d\n",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the arrival time %d\n",i+1);
        scanf("%d",&at[i]);
    }

    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(&bt[j],&bt[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&p[j],&p[j]);
            }
        }
    }

    btime=at[0];
    for(j=0;j<n;j++)
    {
        btime+=bt[i];
        min=bt[k];
        for(i=k;i<n;i++)
        {
            if(btime>at[i] && bt[i]<min)
            {
                swap(&p[i],&p[k]);
                swap(&at[i],&at[k]);
                swap(&bt[i],&bt[k]);
            }
        }
        k++;
    }
    wt[0]=0;
    ct=at[0];
    printf("\nProcess\t AT\t BT\t CT\t TAT\t WT\n");
    for(i=0;i<n;i++)
    {
        ct+=bt[i];
        tat[i]=ct-at[i];
        wt[i]=tat[i]-bt[i];
        sumwt+=wt[i];
        sumtat+=tat[i];
        printf("p[%d]\t %d\t %d\t %d\t %d\t %d\n",p[i],at[i],bt[i],ct,tat[i],wt[i]);
    }
    awt=sumwt/n;
    atat=sumtat/n;
    printf("Average waiting time is %f\n",awt);
    printf("Average turnaround time is %f\n",atat);
}

void fk()
{
    int i,j,k=1,at[10],bt[10],wt[10],tat[10],pro[10]={1,2,3,4,5,6,7,8,9,10},np,atwi[10];
    int btime=0,min,ct=0,itime=0;
    float sumwt=0,sumtat=0,avgwt=0,avgtat=0;

    printf("Enter the number of process\n");
    scanf("%d",&np);
    for(i=0;i<np;i++)
    {
        printf("Enter the burst time %d\n",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the arrival time %d\n",i+1);
        scanf("%d",&at[i]);
        atwi[i]=at[i];
    }
    printf("Enter the idle time\n");
    scanf("%d",&itime);
    for(i=0;i<np;i++)
    {
        if(at[i]<itime)
        {
            atwi[i]=itime;
        }
    }

    for(i=0;i<np;i++)
    {
        for(j=0;j<np;j++)
        {
            if(atwi[i]<atwi[j])
            {
                swap(&pro[i],&pro[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&atwi[i],&atwi[j]);
            }
            else if(atwi[i]==atwi[j] && bt[i]<bt[j])
            {
                swap(&pro[i],&pro[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&atwi[i],&atwi[j]);   
            }
        }
    }
    btime=at[0];
    for(j=0;j<np;j++)
    {
        btime+=bt[i];
        min=bt[k];
        for(i=k;i<np;i++)
        {
            if(btime>= atwi[i] && bt[i]<min)
            {
                swap(&pro[i],&pro[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&atwi[i],&atwi[j]);
            }
        }
        k++;
    }

    wt[0]=0;
    ct=at[0];
    printf("\nProcess\t AT\t BT\t Ct\t TAT\t Wt\n");
    for(i=0;i<np;i++)
    {
        ct+=bt[i];
        tat[i]=ct-at[i];
        wt[i]=tat[i]-bt[i];
        sumwt+=wt[i];
        sumtat+=tat[i];
        printf("p[%d]\t %d\t %d\t %d\t %d\t %d\n",pro[i],at[i],bt[i],ct,tat[i],wt[i]);
    }
    avgwt=sumwt/np;
    avgtat=sumtat/np;
    printf("Average wait time %f\n",avgwt);
    printf("Average turnarounf time %f\n",avgtat);
}

void main()
{
    int ch;
    do
    {
        printf("1.SJF\n2.Fk\n3.Exit\nEnter your choice:\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            sjf();
            break;
        case 2:
            fk();
            break;
        case 3:
            exit(0);
        default:printf("Invalid choice");
            break;
        }
    } while (ch!=3);
}