#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t;
    long long n,F_1,F_2,F,sum;
    scanf("%d",&t);
    for(int i=0;i < t;i++)
    {
        scanf("%lld",&n);
        if(n<=1)
            printf("0\n");
        else if(n==2)
            printf("2\n");
        else
        {
            F_1=1,F_2=2,F=0;
            sum=2;
            while(F<=n)
            {
                if(F%2==0)
                    sum+=F;
                F=F_1+F_2;
                F_1=F_2;
                F_2=F;
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}