#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int s)
{
    return(--s);
}
int signal(int s)
{
    return(++s);
}

void produce()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("Producer produces item %d\n",x);
    mutex=signal(mutex);
}

void consume()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=signal(empty);
    printf("Consumer consumes item %d\n",x);
    x--;
    mutex=signal(mutex);
}

void main()
{
    int ch;
    do
    {
     printf("1.Produce\n2.Consume\n3.Exit\nEnter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1: if((mutex == 1) && (empty!=0))
                    produce();
                else
                {
                    printf("Buffer is full\n");
                }
                break;
        case 2: if((mutex == 1) && (full!=0))
                   consume();
                else
                {
                    printf("Buffer is empty\n");
                }
                break;
        case 3:exit(0);
                break;
        default: printf("Invalid choice\n");
                break;
     }   
    } while (ch!=3);
}