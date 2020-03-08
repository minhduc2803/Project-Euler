#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t,*n,max=0;
    int *result,*sum;
    scanf("%d",&t);
    n=(int*)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
        if(max<n[i])
            max=n[i];
    }
    result=(int*)malloc(3012*sizeof(int));
    sum=(int*)malloc(sizeof(int)*max);
    
    
    
    sum[0]=2; sum[1]=4; sum[2]=8;
    result[0]=8;result[1]=-1;
    int balance=0;
    for(int i=3;i<max;i++)
    {
        int j;
        sum[i]=0;
        balance=0;
        for(j=0;result[j]!=-1;j++)
        {
            result[j]=result[j]*2+balance;
            balance=result[j]/10;
            result[j]=result[j]%10;
            sum[i]+=result[j];
        }
        if(balance>0)
        {
            result[j]=balance;
            sum[i]+=result[j];
            j++;
        }
        result[j]=-1;
    }
    for(int i=0;i<t;i++)
    {
        printf("%d\n",sum[n[i]-1]);
    }
    return 0;
}
