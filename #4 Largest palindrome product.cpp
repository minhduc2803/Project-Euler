#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int test_divide(int n)
{
    for(int i=100;i<=999;i++)
    {
        if(n%i==0 && n/i<1000)
        {
            
            return 1;
        }
    }
    return 0;
}
int rotate(int m)
{
    int a[3];
    a[2]=m%10;
    m=m/10;
    a[1]=m%10;
    a[0]=m/10;
    return a[2]*100+a[1]*10+a[0];
}
int main(){
    int t,n,m,l;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        m=n/1000;
        l=rotate(m);
        if(l>=n%1000)
            m--;
        n=m*1000+rotate(m);
        do
        {
            if(test_divide(n))
                break;
            m--;
            n=m*1000+rotate(m);
        }while(m>=101);
            printf("%d\n",n);
    }
    return 0;
}