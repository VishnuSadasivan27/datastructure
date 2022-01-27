#include<stdio.h>
#include<stdlib.h>
int queue[10];
int main()
{
    int i,size,n,choice=0,rear=-1,front=-1;
    printf("enter the element of queue\n");
    scanf("%d",&size);
    while(choice!=4)
    {
        printf("\nselect the operation:__________\n");
        printf("  1: insert a element to queue:\n");
        printf("  2: delete a element to queue:\n");
        printf("  3: display the element from queue:\n");
        printf("  4: exit from queue:\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(rear==size-1)
            {
                printf("queue overflow\n");
            }
            else
            {    if(front==-1)
                front=0;
                printf("enter the element to be inserted: ");
                scanf("%d",&n);
                rear=rear+1;
                queue[rear]=n;
            }
            break;
        case 2:
            if(front==-1 || front>rear)
            {
            printf("stack under flow\n");
            }
            else
            {
               printf("The element which is deleted is: %d",queue[front] );
               front=front+1;
            }
            break;
        case 3:
            if(front==-1 ||front>rear)
            {
            printf("stack under flow");
            }
            else
            {
             for(i=front;i<=rear;i++)
             {
                 printf("%3d",queue[i]);
             }
            }
            break;
        case 4:
            printf("exiting......");
            exit(0);
            break;
        };
    }
}
