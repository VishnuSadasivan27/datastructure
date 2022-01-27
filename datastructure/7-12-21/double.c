#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*prev;
    int data;
    struct node*next;
};
    struct node*head;
    void insertatbegining();
    void insertatend();
    void insertatspecific();
    void display();
    void deleteatbegining();
    void deleteatend();
    void deleteatspecific();
    void search();
    void main()
    {
        int choice;
        while(choice!=9)
        {


            printf("\n*********main menu********\n");
            printf("choose any of the option given below!!!!!!!!\n");
            printf("\n1.insert at begining \n2. insert at end \n3.insert at specific position\n4.display the list \n5.delete from begining \n6.delete from end \n7.delete from specific position \n8.serach \n9.exit\n ");
            printf("which one you choose????");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                insertatbegining();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                insertatspecific();
                break;
            case 4:
                display();
                break;
            case 5:
                deleteatbegining();
                break;
            case 6:
                deleteatend();
                break;
            case 7:
                deleteatspecific();
                break;
            case 8:
                search();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("please enter a valid choice");

            }
       }
    }
    void insertatbegining()
    {
        int item;
        struct node*ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter the item to be inserted");
        scanf("%d",&item);
        if(head==NULL)
        {
            ptr->prev=NULL;
            ptr->data=item;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->prev=NULL;
            ptr->data=item;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
    }
    void insertatend()
    {
        int item;
        struct node*ptr,*temp;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter the item to be inserted");
        scanf("%d",&item);
         ptr->data=item;
        if(head==NULL)
        {
            ptr->prev=NULL;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=NULL;

        }
    }
    void insertatspecific()
    {
        int item,loc,i;
        struct node*ptr,*temp;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter the value to be inserted");
        scanf("%d",&item);
        printf("enter the position to be inserted");
        scanf("%d",&loc);
        ptr->data=item;
        temp=head;
        for(i=0;i<loc;i++)
           {

             temp=temp->next;
           }
            if(temp==NULL)
            {
             printf("there are less element than %d",loc);
            }
            else
            {
              ptr->next=temp->next;
              ptr->prev=temp;
              temp->next=ptr;
              temp->next->prev=ptr;
              printf("\nnode inserted\n");
            }
    }
    void display()
    {
        struct node*temp;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
    }
    void deleteatbegining()
    {
        struct node*temp;
        temp=head;
        if(head==NULL)
        {
            printf("there is no element to delete");
        }

        else if(temp->next==NULL)
        {

            head=NULL;
            free(temp);
        }
        else
        {
           temp->next->prev=NULL;
           head=temp->next;
           free(temp);
        }
    }
void deleteatend()
{
    struct node *temp;
    temp=head;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        temp = head;
        if(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> prev -> next = NULL;
        free(temp);
        printf("\nnode deleted\n");
    }
}
void deleteatspecific()
{
    struct node *temp2, *temp;
    int val;
    printf("\n Enter the position: ");
    scanf("%d", &val);
    temp = head;
    while(temp -> data != val)
    temp = temp -> next;
    if(temp -> next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(temp -> next -> next == NULL)
    {
        temp ->next = NULL;
    }
    else
    {
        temp2 = temp -> next;
        temp -> next = temp2 -> next;
        temp2 -> next -> prev = temp;
        free(temp2);
        printf("\nnode deleted\n");
    }
}

void search()
{
    struct node *temp;
    int item,i=0,flag;
    temp = head;
    if(temp == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (temp!=NULL)
        {
            if(temp->data == item)
            {
                printf("\nitem found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            temp = temp -> next;
        }
        if(flag==1)
        {
            printf("\nItem not found\n");
        }
    }

}
