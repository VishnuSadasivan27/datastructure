#include<stdio.h>
#include<stdlib.h>
void push();
void display();
void pop();
void search();
struct node
{
    int data;
    struct node*next;
};
struct node*head;

void main()
{
    int ch=0;
   
    while(ch!=5)
    {

        printf("\n please select a choice from below?????????\n");
        printf("\n 1.push \n 2. display\n 3. pop \n 4.search\n");
        printf("\nEnter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
           {
               push();
               break;
            }
        case 2:
            {
                display();
                break;
            }
        case 3:
            {
                pop();
                break;
            }
        case 4:
            {
                search();
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
void push()
{
    int e;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("the value cannot be inserted");
    }
    else
    {
       printf("enter the value to be inserted");
       scanf("%d",&e);
    }
      if(head==NULL)
      {
           ptr->data=e;
           ptr->next=NULL;
           head=ptr;

      }
      else
      {
          ptr->data=e;
          ptr->next=head;
          head=ptr;
      }
      printf("item pushed");

 }
 void display()
 {

     struct node *ptr;
     ptr=head;
     if(ptr==NULL)
     {
         printf("the stack is empty");

     }
     else
     {
         printf("the stack is");
         while(ptr!=NULL)
         {
             printf("%d-->",ptr->data);
             ptr=ptr->next;

         }
     }
 }
void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = head->data;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");

    }
}
void search()
{
    struct node*ptr;
    int item,i=0,flag=1;
    ptr = head;
    if(ptr==NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data==item)
            {
                printf("\n item found at location %d\n",i+1);
                flag=0;
            }

            i++;
            ptr = ptr->next;
        }
        if(flag==1)
        {
            printf("\nItem not found\n");
        }
    }

}


