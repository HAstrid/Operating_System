#include<stdio.h>
void main()
{
   int i,n,p[10],min,k=1;
   int bt[10],temp,j,at[10],wt[10],tat[10],tot=0,total;
   float awt=0,att=0;
   printf("Shortest Job First-Non Pre-emptive\n");
   printf("\nEnter the No. of processes :");
   scanf("%d",&n);
 
   for(i=0;i<n;i++)
   {
     printf("\tEnter the burst time of process %d :",i+1);
     scanf(" %d",&bt[i]);
     printf("\tEnter the arrival time of process %d :",i+1);
     scanf(" %d",&at[i]);
     p[i]=i+1;
   }
 
/*Sorting According to Burst Time*/
 
   for(i=0;i<n-1;i++)
  {
    for(j=0;j<(n-i-1);j++)
    {
     if(bt[j]>bt[j+1])
     {
       temp=p[j];
	   p[j]=p[j+1];
       p[j+1]=temp;
       
       temp=at[j];
       at[j]=at[j+1];
       at[j+1]=temp;
       
       temp=bt[j];
       bt[j]=bt[j+1];
       bt[j+1]=temp;
     }
    }
  }
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time*/
 
for(i=1;i<n;i++)
{
tot=tot+bt[k];
min=bt[k];
for(j=0;j<n;j++)
{
if (at[j]>at[k] && bt[j]>bt[k])
     {
	temp=p[k];
	p[k]=p[j];
	p[j]=temp;

	temp=at[k];
	at[k]=at[j];
	at[j]=temp;

	temp=bt[k];
	bt[k]=bt[j];
	bt[j]=temp;
      }
   }
k++;
}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		wt[i]+=bt[i-1];
		wt[i]-=at[i];
		total+=wt[i];
	}
 
	awt=(total/n);
	total=0;
	for(i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
		total+=tat[i];
	}
 
	att=(total/n);
 
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<n;i++)
	{
		printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tat[i]);
	}
 
	printf("\n\nAVERAGE WAITING TIME : %f",awt);
	printf("\nAVERAGE TURN AROUND TIME : %f",att);

}
