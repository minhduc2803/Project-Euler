#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int t,*n,maxn=0;
    int *maxcollatz;
    int *collatz;
    scanf("%d",&t);
    n=(int*)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
        if(maxn<n[i])
            maxn=n[i];
    }
    
    
    
    
    collatz=(int*)malloc(sizeof(int)*maxn);
    maxcollatz=(int*)malloc(maxn*sizeof(int));
    maxcollatz[0]=1;
    collatz[0]=1;
    for(int j=2;j<=maxn;j++)
    {
        maxcollatz[j-1]=1;
        for(long long pos=j;pos!=1;)
        {
            if(pos<j)
            {
                maxcollatz[j-1]+=(maxcollatz[pos-1]-1);
                break;
            }
            if(pos%2==0)
            {
                pos/=2;
                maxcollatz[j-1]++;
            }
            else
            {
                pos=(pos*3+1)/2;
                maxcollatz[j-1]+=2;
            }
        }
    }
    for(int i=1;i<maxn;i++)
    {
        if(maxcollatz[i-1]>maxcollatz[i])
        {
            maxcollatz[i]=maxcollatz[i-1];
            collatz[i]=collatz[i-1];
        }
        else
            collatz[i]=i+1;
    }
    for(int i=0;i<t;i++)
    {
        printf("%d\n",collatz[n[i]-1]);
    }
    return 0;
}