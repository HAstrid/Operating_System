#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199


int main(){
  int queue[20];
  int head, max, q_size, temp, sum,vis[20],i,j,diff=0;


  printf("%s\t", "Input no of disk locations");
  scanf("%d", &q_size);

  printf("%s\t", "Enter head position");
  scanf("%d", &head);

  printf("%s\n", "Input elements into disk queue");
  for(i=0; i<q_size; i++){
    scanf("%d", &queue[i]);
    vis[i]=0;
  }
  //sort the array
  for(i=0; i<q_size-1;i++){
    for(j=i; j<q_size; j++){
      if(queue[i]>queue[j]){
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  max = head;
  printf("\n%d",head);

  //locate head in the queue
  for(i=0; i<q_size; i++){
    if(max< queue[i]){
      temp=abs(max-queue[i]);
      diff+=temp;
      printf("-->%d",queue[i]);
      max=queue[i];
      vis[i]=1;
    }
  }
  printf("-->%d",HIGH);

  diff+=abs(HIGH-max);
  max=HIGH;

  for(i=q_size-1;i>=0;i--)
  {
    if(max>queue[i] && !vis[i])
    {
      temp=abs(max-queue[i]);
      diff+=temp;
      printf("-->%d",queue[i]);
      max=queue[i];
      vis[i]=1;
    }
  }

  printf("\nmovement of total cylinders %d\n", diff);
  printf("Average seek time is %.3f \n",diff/(float)q_size);

  return 0;
}