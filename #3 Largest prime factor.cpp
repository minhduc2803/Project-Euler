#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int prime(long long n)
{
    if(n<=3)
        return 1;
    else
    {
        long long cn=sqrt(n);
        for(int i=2;i<=cn;i++)
            if(n%i==0)
                return 0;
        return 1;
    }
}
int main(){
    int t; 
    long long n,max,F_1,F_2;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        long long cn=sqrt(n);
        int i,flag=0;
        max=0;
        for(i=2;i<=cn;i++)
        {
            if(n%i==0)
            {
                flag=1;
                long long ni=n/i;
                F_1=prime(i)?i:0;
                F_2=prime(ni)?ni:0;
                if(max<F_1)
                    max=F_1;
                if(max<F_2)
                    max=F_2;
            }
        }
        if(!flag)
            max=n;
        printf("%lld\n",max);
    }
    return 0;
}