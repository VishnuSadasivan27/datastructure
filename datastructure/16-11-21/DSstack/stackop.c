#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

    int stack[10],top=-1;
    int main()
 {
     int choice,n,i,size;
     printf("enter the size 0f array:");
     scanf("%d",&size);

    while(1)
    {

        printf("\nselect the operation\n");
        printf("1: push\n");
        printf("2: pop\n");
        printf("3: display\n");
        printf("4: exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
     case 1:
           if(top==size-1)
           {
               printf("stack overflow\n");
           }
           else
           {
               printf("enter the elements to be inserted: ");
               scanf("%d",&n);
               top=top+1;
               stack[top]=n;
               break;
           }
     case 2:
        if(top== -1)
        {
            printf("stack underflow\n");
        }
        else
        {
            printf("the popped element is : %d\n",stack[top]);
            top=top-1;
            break;
        }
     case 3:
        if(top== -1)
        {
            printf("stack underflow");

        }
        else
        {
            printf("elements present in the stack is:\n");
            for(i=top;i>=0;--i)

                printf("%3d",stack[i]);
                break;
        }
     case 4:
        {
            printf("exiting.....");
            exit(0);
            break;
        }
     default:
        {
            printf("enter valid choice");
        }

      };

    }

  }





