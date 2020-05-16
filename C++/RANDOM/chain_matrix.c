#include<stdio.h>
#include<limits.h>
void main()
{
    int n,i;
    printf("Enter the number of matrix available in chain:");
    scanf("%d",&n);

    int p[n+1];

    for(i=1;i<=n;i++)
    {
        printf("\nEnter dimension of matrix A%d.",i);
        printf("\nEnter no. of rows of matrix %d:",i);
        scanf("%d",&p[i-1]);
        printf("Enter no. of columns of matrix %d:",i);
        scanf("%d",&p[i]);
    }

    printf("dimension array(p[]):{");
    for(i=0;i<n;i++)
    {
        printf("%d ,",p[i]);
    }
     printf("%d}",p[n]);
     n++;
     int m[n+1][n+1],s[n+1][n+1],j,q;
     int min=INT_MAX;

     for(i=0;i<=n;i++)
     {
         for(j=0;j<=n;j++)
         {
             m[i][j]=0;
             s[i][j]=0;
         }
     }
     for(int d=1;d<n;d++)
     {
         for(i=1;i<n+1-d;i++)
         {
             j=i+d;
             m[i][j]=min;
             for(int k=1;k<=j-1;k++)
             {
                 q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                    if(q<m[i][j])
                    {
                        m[i][j]=q;
                        s[i][j]=k;
                    }
             }

         }
     }
    printf("\nMinimum number of scalar multiplication required: %d",m[1][n]);
}