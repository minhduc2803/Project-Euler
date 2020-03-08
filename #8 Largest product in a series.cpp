#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int find_begin(long long *a, int n, int k, int *begin)
{
    
    for(int i =*begin;i<*begin+k;i++)
    {
        if(i>=n)
            return 0;
        if(a[i]==0)
        {
            *begin=i+1;
        }
        
    }
    return 1;
}
long long find_first(long long *a, int n, int k, int *begin)
{
    if(find_begin(a,n,k,begin))
    {
        long long max=1;
        for(int i=*begin;i<*begin+k;i++)
            max*=a[i];
        return max;
    }
    else
        return 0;
}

int main(){
    int t,n,k;
    char *b;
    long long *a;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&k);
        a=(long long*)malloc(n*sizeof(long long));
        b=(char*)malloc(n*sizeof(char)+1);
        scanf("%s",b);
        for(int i=0;i<n;i++)
        {
            a[i]=b[i]-'0';
        }
        int begin = 0, end;
        long long max = find_first(a,n,k,&begin);
        long long fullmax=max;
        end=begin+k;
        for(begin,end;end<n;)
        {
            if(a[end]!=0)
            {
                max=max/a[begin]*a[end];
                begin++; end++;
            }
            else
            {
                begin=end+1;
                max=find_first(a,n,k,&begin);
                end=begin+k;
            }
            if(fullmax<max)
                fullmax=max;
        }
        free(a);
        free(b);
        printf("%lld\n",fullmax);
    }
    return 0;
}