
#include<stdio.h>
#include<stdlib.h>
void enqueue();
void display();
void dequeue();
void peek();
struct node
{
    int data;
    struct node *next;
};
struct node *front=-1;
struct node *rear=-1;

void main()
{
    int ch=0;
    printf("\n***********///stack using linked************\\\\\ \n");
    while(ch!=6)
    {

        printf("\n please select a choice from below?????????\n");
        printf("\n 1.enqueue \n 2. display\n 3. dequeue \n 4.peek \n5.exit \n");
        printf("\nEnter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
           {
               enqueue();
               break;
            }
        case 2:
            {
                display();
                break;
            }
        case 3:
            {
                dequeue();
                break;
            }
        case 4:
            {
                peek();
                break;
            }
        case 5:
           {
               printf("exiting...");
               exit(0);
               break;

            }
        default:
            {
                printf("enter a valid choice");
                break;
            }
        };
    }
}

void enqueue()
{
    int item;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the element to be inserted");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=0;
    if(rear==-1)
    {
        front=rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
        free(temp);
    }
    else
    {
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void peek()
{
    if((front==-1) &&(rear==-1))
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe front element is %d", front->data);
    }
}

void display()
{
    struct node *temp;
    temp=front;
    printf("\n The elements in a Queue are : ");
    if((front==-1) && (rear==-1))
    {
        printf("Queue is empty");
    }

    else
    {
        while(temp->next!=front)
        {
            printf("%d->", temp->data);
            temp=temp->next;
        }
        printf("%d", temp->data);
    }
}
