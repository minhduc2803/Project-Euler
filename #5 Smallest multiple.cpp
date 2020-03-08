#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37};
void detached(int a[], int m)
{
    for(int i=0;prime[i]<=m;i++)
    {
        int exponent=0;
        if(m%prime[i]==0)
        {
            do
            {
            exponent++;
            m/=prime[i];
            }while(m%prime[i]==0);
        }
        if(a[i]<exponent)
            a[i]=exponent;
    }
}
int main(){
    int t; 
    int n,*a;
    long long mul;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        mul=1;
        a=(int*)calloc(12,sizeof(int));
        scanf("%d",&n);
        for(int j=2;j<=n;j++)
        {
            detached(a,j);
        }
        for(int j=0;j<12;j++)
        {
            mul *=pow((long long)prime[j],(long long)a[j]);
        }
        printf("%lld\n",mul);
    }
    return 0;
}