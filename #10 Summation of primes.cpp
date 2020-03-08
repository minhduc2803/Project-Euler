#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int find(int a[], int p, int begin, int end)
{
    if(end - begin >= 1)
    {
        int pos=(end+begin)/2+1;
        if(p<a[pos])
            return find(a,p,begin,pos-1);
        else if(p>a[pos])
            return find(a,p,pos,end);
        else
            return pos;
    }
    else
        return end;
}
int main(){
    int t,*n,max=0;
    int *prime;
    long long *sum;
    scanf("%d",&t);
    n=(int*)malloc(t*sizeof(int));
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
        if(max<n[i])
            max=n[i];
    }
    prime=(int*)malloc((max/3+5)*sizeof(int));
    int count=5;
    int flag;
    prime[0]=0; prime[1]=2; prime[2]=3; prime[3]=5; prime[4]=7;
    for(int i=11;i<=max;i++)
    {
        flag=1;
        int ci=sqrt(i);
        for(int j=1;j<=ci;j++)
        {
            if(i%prime[j]==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            prime[count]=i;
            count++;
        }
    }
    prime=(int*)realloc(prime,count*sizeof(int));
    sum=(long long*)malloc(count*sizeof(long long));
    sum[0]=0;
    for(int i=1;i<count;i++)
        sum[i]=sum[i-1]+(long long)prime[i];
    for(int i=0;i<t;i++)
    {
        printf("%lld\n",sum[find(prime,n[i],0,count-1)]);
    }
    return 0;
}