#include<stdio.h>
#define newp 10
#define _CRT_Secure_No_Warning

int main()
{
 int i,np,pro[newp]={1,2,3,4,5,6,7,8,9,10};
 int min,k=1,btm=0;
 int bt[newp],temp,j,at[newp];
 int atwi[newp],wt[newp];
 int tat[newp],ta=0,sum=0,itime=0;
 float wavg=0,tavg=0,tsum=0,wsum=0;
 printf("SJF Non Preemptive\n");
 printf("Enter the number of process(<10)\n");
 scanf("%d",&np);
 for(i=0;i<np;i++)
 {
  printf("Enter the Burst Time and Arrival Time for Process%d : \n",i+1);
  scanf("%d",&bt[i]);
  scanf("%d",&at[i]);
  atwi[i]=at[i];
 }
 printf("Enter the idle time: ");
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
    temp=pro[j];
    pro[j]=pro[i];
    pro[i]=temp;

    temp=at[j];
    at[j]=at[i];
    at[i]=temp;

    temp=bt[j];
    bt[j]=bt[i];
    bt[i]=temp;

    temp=atwi[j];
    atwi[j]=atwi[i];
    atwi[i]=temp;
   }
   else if((atwi[i]==atwi[j]) && (bt[i]<bt[j]))
   {
    temp=pro[j];
    pro[j]=pro[i];
    pro[i]=temp;

    temp=at[j];
    at[j]=at[i];
    at[i]=temp;

    temp=bt[j];
    bt[j]=bt[i];
    bt[i]=temp;

    temp=atwi[j];
    atwi[j]=atwi[i];
    atwi[i]=temp;
   }
  }
 }

 btm=at[0];
 for(j=0;j<np;j++)
 {
  btm=btm+bt[j];
  min=bt[k];
  for(i=k;i<np;i++)
  {
   if((btm>=atwi[i]) && (bt[i]<min))
   {
    temp=pro[k];
    pro[k]=pro[i];
    pro[i]=temp;

    temp=at[k];
    at[k]=at[i];
    at[i]=temp;

    temp=bt[k];
    bt[k]=bt[i];
    bt[i]=temp;

    temp=atwi[k];
    atwi[k]=atwi[i];
    atwi[i]=temp;
   }
  }
  k++;
 }
 wt[0]=0;
 sum=at[0];
 for(i=1;i<np;i++)
 {
  sum+=bt[i-1];
  wt[i]=sum-at[i];
  if(wt[i]<0)
   wt[i]=0;
  wsum+=wt[i];
 }
 wavg=wsum/np;
 ta=at[0];
 for(i=0;i<np;i++)
 {
  ta+=bt[i];
  tat[i]=ta-at[i];
  tsum+=tat[i];
 }
 tavg=tsum/np;
 printf("Process\t\t Arrival Time\t\t Burst Time\t\t Turnaround Time\t\t Wait Time\t\n");
 for(i=0;i<np;i++)
  printf("P%d\t\t\t %d\t\t\t %d\t\t\t %d\t\t\t %d\t\n",pro[i],at[i],bt[i],tat[i],wt[i]);
 printf("Average Waiting Time is %f\n",wavg);
 printf("Average Turnaround Time is %f\n",tavg);
}
