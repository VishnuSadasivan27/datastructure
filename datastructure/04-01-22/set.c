#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ch,n,v,i,flag=1;
    int a1[10],a2[10];
  printf("enter the number of bits:\n");
  scanf("%d",&n);
  printf("\nenter the bits:\n");
  for(i=0;i<n;i++)
  {
     scanf("%d",&v);
     if(v<0||v>1)
     {
         printf("please enter a valid bit:\n");
     }
     else
     {
        a1[i]=v;
     }
  }
  printf("enter the second bits:\n");
  for(i=0;i<n;i++)
  {
     scanf("%d",&v);
     if(v<0||v>1)
     {
         printf("please enter a valid bit:\n");
     }
     else
     {
        a2[i]=v;
     }
  }
  while(1)
  {
  printf("\n\n###########enter the choice!!!#########\n");
  printf("\n 1.Union\n 2.Intersection\n 3.Difference\n 4.Equality\n 5.Exit\n");
  printf("please select a choice!!\n");
  scanf("%d",&ch);
    switch(ch)
    {
    case 1:
          printf("\n Union of the set is: \n");
          for(i=0;i<n;i++)
          {
             if((a1[i]||a2[i])==1)
             {
               printf("1");
             }
             else
             {
                 printf("0");
             }

           }
        break;
    case 2:
         printf("\n Intersection of the set is: \n");
         for(i=0;i<n;i++)
          {
             if((a1[i]&&a2[i])==1)
             {
               printf("1");
             }
             else
             {
                printf("0");
             }

           }
           break;
    case 3:
         printf("\n Difference of the set is: \n");
        for(i=0;i<n;i++)
          {
             if(a1[i]==1&&a2[i]==0)
             {
               printf("1");
             }
             else
             {
                printf("0");
             }

           }
           break;
    case 4:
         printf("\n Equality of the set is: \n");
        for(i=0;i<n;i++)
          {
             if(a1[i]!=a2[i])
             {
              flag=0;
              printf("False__The both set are not same");
              exit(0);
             }
          }
            if(flag==1)
            {
                printf("True__Two sets are same");
            }
           break;

    case 5:
        {
        printf("exiting.......");
        break;
        }
    default:
        {
        printf("please enter a valid case");
        break;
        }

    };

  }
}







