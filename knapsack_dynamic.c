#include<stdio.h>
int max(int,int);
int main(int argc[],char const * argv[])
{
    FILE *r,*w;
    r = fopen(argv[1],"r");
    w = fopen(argv[2],"w");
    int n,m;
    fscanf(r,"%d",&n);
    fscanf(r,"%d",&m);
    int p[n+1],W[n+1];
    p[0]=0;
    for(int i=1;i<=n;i++)
    {
       fscanf(r,"%d",&p[i]);
    }
    W[0]=0;
    for(int i=1;i<=n;i++)
    {
       fscanf(r,"%d",&W[i]);
    }
    int k[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int v=0;v<=m;v++)
        {
          if(i==0||v==0)
           k[i][v]=0;
          else if(W[i]<=v)
            k[i][v]=max(k[i-1][v],k[i-1][v-W[i]]+p[i]);
          else k[i][v]=k[i-1][v];   
        }
    }
    
    printf("%d ",k[n][m]);
   

return 0;
}
int max(int x,int y){
    printf("coming");
    if(x>y)return x;
    else return y;
}