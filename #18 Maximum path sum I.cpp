#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int *a, int len, int i, int t)
{
    if(i>=len)
        return 0;
    else
    {
        int maxl=max(a,len,t+i,t+1);
        int maxr=max(a,len,t+i+1,t+1);
        if(maxl>maxr)
            return a[i]+maxl;
        else
            return a[i]+maxr;
    }
}
int main() {
    int t,n;
    int *a;
    scanf("%d",&t);
    for(int count=0;count<t;count++)
    {
        scanf("%d",&n);
        int len=(1+n)*n/2;
        a=(int*)malloc(sizeof(int)*len);
        for(int i=0;i<len;i++)
            scanf("%d",&a[i]);
        int m=max(a,len,0,1);
        printf("%d\n",m);
    }
    return 0;
}
