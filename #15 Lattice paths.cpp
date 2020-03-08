#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int initial(int **a, int N, int M, int i, int j)
{
    if(i<0 || j<0)
        return 1;
    if(a[i][j]!=0)
        return a[i][j];
    else
    {
        a[i][j] = (initial(a,N,M,i-1,j)+initial(a,N,M,i,j-1))%1000000007;
        return a[i][j];
    }
}
int main() {

    int t;
    int *N,*M;
    int maxN=0,maxM=0;
    scanf("%d",&t);
    N=(int*)malloc(sizeof(int)*t);
    M=(int*)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&N[i],&M[i]);
        if(maxN<N[i])
            maxN=N[i];
        if(maxM<M[i])
            maxM=M[i];
    }
    int **a;
    a=(int**)malloc(sizeof(int*)*maxN);
    for(int i=0;i<maxN;i++)
        a[i]=(int*)calloc(maxM,sizeof(int));
    a[0][0]=2;
    //a[1][0]=3;
    //a[0][1]=3;
    initial(a,maxN,maxM,maxN-1,maxM-1);
    for(int i=0;i<t;i++)
    {
        printf("%d\n",a[N[i]-1][M[i]-1]);
    }
    return 0;
}
