#include<stdio.h>
void main()
{
int ch,i,a[10],n,e,pos,temp=0,post=0,del=0;
char choice;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    printf("enter the elements: \n");
        for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
do
{
    printf("1.traversal\n2.insertion at begining\n3.insertion at end\n4.insertion at specific position\n5.deletion at begining\n6.deletion at end\n7.deletion at specific position\n8.search\n");
    printf("enter your choice: ");
    scanf("%d",&ch);

switch(ch)
{
    case 1:

            printf("the entered array is:");
            for(i=0;i<n;i++)
            {
                printf("%3d",a[i]);
            }
            break;
    case 2:
            printf("enter the element");
            scanf("%d",&e);

           for(i=n;i>=0;i--)
           {
               a[i+1]=a[i];

           }
               a[0]=e;
               n++;
           for(i=0;i<n;i++)
           {
               printf("%3d",a[i]);
           }

              break;
    case 3:
           printf("enter the number:");
           scanf("%d",&e);
           for(i=n;i>=0;i--)
           {
              a[n]=e;
           }
           n++;
             for(i=0;i<n;i++)
             {
                 printf("%3d",a[i]);
             }
             break;
    case 4:
           printf("enter the element to be inserted: ");
            scanf("%d",&e);
            printf("enter the position of the element: ");
            scanf("%d",&pos);

            for(i=n;i>=pos-1;i--)
            {

               a[i]=a[i-1];
            }
                a[pos-1]=e;
             for(i=0;i<n+1;i++)
            printf("%3d",a[i]);
            break;
    case 5:
           for(i=0;i<n;i++)
           {
               a[i]=a[i+1];
           }
            for(i=0;i<n;i++)
            {
               printf("%3d",a[i]);
            }
            break;
    case 6:
           for(i=n;i<n;i++)
           {
               a[i-1]=a[i];
           }
           n--;
            for(i=0;i<n;i++)
            {
              printf("%3d",a[i]);
            }
            break;
    case 7:
            printf("enter the position to be deleted: ");
            scanf("%d",&pos);
            for(i=pos-1;i<n;i++)
            {
                if(i==pos)
                {

                   post=1;
                }
                a[i]=a[i+1];

            }
            n--;
            if(post==1)
               {
               for(i=0;i<n;i++)
               printf("%d\n",a[i]);
               }
            else
                printf("the element is not found to delete\n");
            break;
    case 8:
        printf("enter the element to be searched:");
            scanf("%d",&e);
            for(i=0;i<n;i++)
            {
                if(a[i]==e)
                {
                temp=i;
             }   }
        printf("the element %d is found in %d\n",e,temp+1);

  }
printf("\ndo you want to continue?(y/n)");
scanf(" %c",&choice);
}while(choice=='y');
}
