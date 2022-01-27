#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};struct node*head;
void insertatbegining();
void display();
void insertatend();
void insertatspecific();
void deletebegin();
void deleteend();
void deletespecific();
void search();
void main()
{
    int choice;
    while(choice!=9)
    {
        printf("\nenter your choice\n");
        printf("\n1.insert at beginning \n2.display \n3.insert at end\n4.insert at specific position \n5.delete from beginning \n6.delete from end \n7.delete from specific position \n 8.search \n9.exit");
        printf("\nplease select a choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertatbegining();
            break;
        case 2:
            display();
            break;
        case 3:
            insertatend();
            break;
        case 4:
            insertatspecific();
            break;
        case 5:
            deletebegin();
            break;
        case 6:
            deleteend();
            break;
        case 7:
            deletespecific();
            break;
        case 8:
            search();
            break;
        case 9:
            printf("exiting....");
            exit(0);
            break;
        default:
            printf("\nplease enter a valid choice:\n");

        };
    }
}
void insertatbegining()
{
    struct node*ptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the element to be inserted\n");
    scanf("%d",&item);
    if(head==NULL)
    {
        ptr->data=item;
      ptr->next=NULL;
      head=ptr;
      printf("\nvalue inserted..\n");
    }
    else
    {
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\n value inserted\n");
    }
}
void insertatend()
{
    int item;
    struct node*temp,*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the element to be inserted\n");
    scanf("%d",&item);
    if(head==NULL)
    {
        ptr->data=item;
        ptr->next=NULL;
        head=ptr;
        printf("\nelement inserted");
    }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
               temp=temp->next;

            }

                ptr->data=item;
                ptr->next=NULL;
                temp->next=ptr;


        }

}
void insertatspecific()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value:");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the location:");
        scanf("\n%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }

        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nNode inserted");
    }
}
void deletebegin()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}
void deleteend()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\nlist is empty");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}
void deletespecific()
{
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n Enter the location:\n");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
    printf("\nDeleted node %d ",loc+1);
}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("item found at location %d ",i+1);
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("Item not found\n");
        }
    }

}

void display()
{
    struct node*temp=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }

    while(temp!=NULL)
    {
        printf("[%d]-->",temp->data);
        temp=temp->next;
    }
}
