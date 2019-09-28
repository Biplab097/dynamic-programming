#include<stdio.h>

void printParenthesis(int i, int j, int n, 
                      int *s) 
{ 
    
    if (i == j) 
    { 
        printf("A%d",i); 
        return; 
    } 
  
    printf("("); 
   
    printParenthesis(i, *((s+i*n)+j), n, 
                     s); 
  
    printParenthesis(*((s+i*n)+j) + 1, j, 
                     n, s); 
    printf(")"); 
} 
  

int main(int argc,char const* argv[])
{
 FILE *r;
 int n;
 r = fopen("input_matrix","r");
 fscanf(r,"%d",&n);
 int p[n];
 for(int i=0;i<=n;i++)
 {
  fscanf(r,"%d",&p[i]);
 }
 
 int m[n+1][n+1],s[n+1][n+1];
 for(int l=0;l<=n;l++){
  for(int c=0;c<=n;c++){m[l][c]=0;s[l][c]=0;}
  }
 int j,min,q;
 for(int d=1;d<n;d++)
 {
  for(int i=1;i<=n-d;i++)
  {
   j=i+d;
   min = 327670;
   for(int k=i;k<=j-1;k++)
   {
     q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
  
     if(q<min)
     {
      min = q;
      s[i][j]=k;
     }
   }
   m[i][j]=min;
  }
 }
 printf("MINIMUM cost of Matrix Multiplication is: %d ",m[1][n]);
 printf("\n");
 printf("Parenthesis matrix is:\n");
 for(int l=1;l<=n;l++){
  for(int c=1;c<=n;c++){printf("%d ",s[l][c]);}printf("\n");
  }
 printf("FINAL OPTIMAL PARENTHESIS IS:\n");
 printParenthesis(1, n, n+1, (int *)s); 
return 0;
}
