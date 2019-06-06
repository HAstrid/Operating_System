#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    int i,f1=0,f2=1,f3;
    f3=f1+f2;
    pid_t pid=fork();
    if(pid == 0)
    {
        printf("Child created\n");
        printf("Enter the value for i:\n");
        scanf("%d",i);
        if(i==0)
         printf("Values should be greater than 0\n");
        else if(i==1)
         printf("0\n");
        else if(i==2)
        {
            printf("0\t%d\n",f3);
            printf("Child ended\n");
        }
        else if(i>2)
        {
            printf("0\t%d\t",f3);
            while(i>2)
            {
                f3=f1+f2;
                printf("%d\t",f3);
                f1=f2;
                f2=f3;
                i--;
            }
        }
        printf("Child ended\n");
    }
    else
    {
        printf("Parent waiting\n");
        waitpid(pid,NULL,0);
        printf("Parent ended\n");
    }
    return 0;
}