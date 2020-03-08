#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t,n;
    long long sum,mul_sum;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        sum=0;
        mul_sum=0;
        for(int i=n;i>1;i--)
        {
            sum+=(long long)i;
            mul_sum+=sum*(i-1);
        }
        printf("%lld\n",2*mul_sum);
    }
    return 0;
}