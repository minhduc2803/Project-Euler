#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(i%3==0||i%5==0)
                sum=sum+i;
        }
        printf("%d\n",sum);
    }
    return 0;
}