#include<stdio.h>
#include<stdlib.h>

int bt[10],at[10],wt[10],tat[10],rt[10];
int i,flag=0,remain,temp,time,ct,num,tq;
float sumWT=0,sumTAT=0,awt=0,atat=0;

void takeInput()
{
    printf("Enter the number of process\n");
    scanf("%d",&num);
    remain=num;
    for(i=0;i<num;i++)
    {
        printf("Enter the burst time for the processes\n");
        scanf("%d",&bt[i]);
        printf("Enter the arrival time of the processes\n");
        scanf("%d",&at[i]);
        rt[i]=bt[i];
    }
}

void fcfs()
{
    wt[0]=0;
    temp=at[0];
    for(i=1;i<num;i++)
    {
        temp+=bt[i-1];
        wt[i]=temp-at[i];
        sumWT+=wt[i];
    }    
    ct=at[0];
    printf("\nProcess\t AT\t BT\t CT\t TAT\t WT\n");
    for(i=0;i<num;i++)
    {
        ct+=bt[i];
        tat[i]=ct-at[i];
        sumTAT+=tat[i];
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",i+1,at[i],bt[i],ct,tat[i],wt[i]);
    }
    awt=sumWT/num;
    atat=sumTAT/num;
    printf("Average Waiting time is %f\n",awt);
    printf("Average turnaround time is %f\n",atat);
}

void rr()
{
    printf("Enter the time quantum\n");
    scanf("%d",&tq);
    printf("\nProcess\t AT\t BT\t TAT\t WT\n");

    for (time=0,i=0;remain!=0;)
    {
        if(rt[i]<=tq && rt[i]>0)
        {
            time+=rt[i];
            rt[i]=0;
            flag=1;
        }
        else if(rt[i]>0)
        {
            rt[i]-=tq;
            time+=tq;
        }
        if(rt[i] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],time-at[i],time-at[i]-bt[i]);
            awt=time-at[i]-bt[i];
            atat=time-at[i];
            flag=0;
        }
        if (i== num -1)
        {
            i=0;
        }
        else if(at[i+1]<=time)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    printf("Average waiting time %f\n",awt*1.0/num);
    printf("Average tuenaround time %f\n",atat);
}

void main()
{
    int ch;
    do
    {
        printf("1.FCFS\n2.RR\n3.Exit\nEnter your choice: \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            takeInput();
            fcfs();
            break;
        case 2:
            takeInput();
            rr();
            break;
        case 3:exit(0);
        default: printf("Invalid choice\n");
            break;
        }
    } while (ch!=3);
}