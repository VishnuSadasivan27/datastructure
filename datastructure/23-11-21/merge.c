#include<stdio.h>
void main()
{
    int i,n,m,j,k,a[10],a2[20],temp=0,s,a3[20],index=0;
    printf("enter the number of values:");
    scanf("%d",&n);
    printf("\nEnter the values of first array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The first sorted array is");
     for(i=0;i<n;i++)
     {
      for(j=i+1;j<n;j++)
      {
          if(a[i]>a[j])
          {
             temp=a[i];
             a[i]=a[j];
             a[j]=temp;
          }
      }
     }
     for(i=0;i<n;i++)
     {
         printf("%3d",a[i]);
     }
       temp=0;
     printf("\nenter the number of values:");
     scanf("%d",&m);
     printf("\nenter the values of second array:");
     for(i=0;i<m;i++)
     {
         scanf("%d",&a2[i]);
     }
     printf("the second  sorted array is:\n");
     for(i=0;i<m;i++)
     {
        for(j=i+1;j<m;j++)
        {
            if(a2[i]>a2[j])
               {
                   temp=a2[i];
                   a2[i]=a2[j];
                   a2[j]=temp;
               }
        }
     }
     for(i=0;i<m;i++)
     {
         printf("%3d",a2[i]);
         s=m+n;
     }
     printf("\nThe output of the two merged sorted array is:\n");

     for(i=0;i<n;i++)
     {
         a3[i]=a[i];
     }
     k=n;
     for(i=0;i<m;i++)
     {
         a3[k]=a2[i];
         k++;

     }
     for(i=0;i<s;i++)
     {
      for(j=i+1;j<s;j++)
        {
            if(a3[i]>a3[j])
            {
                temp=a3[i];
                a3[i]=a3[j];
                a3[j]=temp;
            }
        }
     }
      for(i=0;i<s;i++)
      {
          printf("%3d",a3[i]);
      }




}
