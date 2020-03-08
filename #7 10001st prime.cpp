#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int test_prime(long long m, long long a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(m%a[i]==0)
            return 0;
    }
    return 1;
}
int main(){
    int t,max=0,*n;
    long long *a;
    scanf("%d",&t);
    n=(int*)malloc(t*sizeof(int));
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
        if(max<n[i])
            max=n[i];
    }
    a=(long long*)malloc(max*sizeof(long long));
    a[0]=2;
    a[1]=3;
    for(int i=2;i<max;i++)
    {
        for(long long j=a[i-1]+2;;j++,j++)
        {
            if(test_prime(j,a,i))
            {
                a[i]=(long long)j;
                break;
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        printf("%lld\n",a[n[i]-1]);
    }
    return 0;
}