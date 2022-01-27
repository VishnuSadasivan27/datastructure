#include<stdio.h>
struct disjoint
{
   int parent[10];
   int rank[10];
   int n;
}dis;
int main()
{
     int n,x,y;
     printf("How many elements ?\n");
     scanf("%d",&dis.n);
     makeSet();
     int ch,choice;
  while(1)
  {

     printf("\n___MENU_\n");
     printf("1. Union \n2.Find\n3.Display\n 4.Exit\n");
     printf("enter choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1:
            Union();
            break;
         case 2:
             printf("Enter elements to check if connected components");
             scanf("%d %d",&x,&y);
             if (find(x) == find(y))
                {
                 printf("Connected components\n") ;
                }
             else
             {
                printf("Not onnected components \n") ;
             }
                break;
         case 3:
              displaySet();
              break;
         case 4:
            printf("exiting....");
            break;
         default:
            printf("please enter a valid case");
     }

 }

}

void makeSet()
 {
     int i;
    for (i = 0; i < dis.n; i++)
     {
       dis.parent[i] = i;
       dis.rank[i]=0;
     }
 }
 void displaySet()
 {
     int i;
   printf("\nParent Array\n");
    for ( i = 0; i < dis.n; i++)
     {
       printf("%d ",dis.parent[i]);
     }
    printf("\nRank Array\n");
   for (int i = 0; i < dis.n; i++)
    {
      printf("%d ",dis.rank[i]);
     }
      printf("\n");
 }
 int find(int x)
 {
   if (dis.parent[x] != x)
    {
      dis.parent[x] = find(dis.parent[x]);
    }
    return dis.parent[x];
 }
 void Union()
 {
     int xset=0,yset=0,x,y;
     printf("\nEnter elements to perform union\n");
     scanf("%d %d",&x,&y);
     xset = find(x);
     yset = find(y);
  if (xset == yset)
     return;
  if (dis.rank[xset] < dis.rank[yset])
       {
          dis.parent[xset] = yset;
          dis.rank[xset]=-1;
       }
  else if (dis.rank[xset] > dis.rank[yset])
      {
         dis.parent[yset] = xset;
         dis.rank[yset]=-1;
      }
  else
      {
         dis.parent[yset] = xset;
         dis.rank[xset] = dis.rank[xset] + 1;
         dis.rank[yset]=-1;
       }
 }

