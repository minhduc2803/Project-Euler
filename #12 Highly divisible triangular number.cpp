#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int divisor(int n)
{
    int cn=sqrt(n);
    int sum=0;
    for(int i=1;i<=cn;i++)
    {
        if(n%i==0)
            sum+=2;
    }
    if(cn*cn==n)
        sum-=1;
    return sum;
}
int triangle(int n)
{
    int a,b;
    if(n%2==0)
    {
        a=divisor(n/2);
        b=divisor(n+1);
    }
    else
    {
        a=divisor(n);
        b=divisor((n+1)/2);
    }
    return a+b-1+(a-1)*(b-1);
}
int main() {
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(int j=1;;j++)
        {
            int div=triangle(j);
            if(div>n)
            {
                int tri=(j+1)*j/2;
                printf("%d\n",tri);
                break;
            }
        }
    }
    return 0;
}
