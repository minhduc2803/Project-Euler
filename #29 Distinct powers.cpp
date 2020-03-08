#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
void exponent(int max_exponent[], int n)
{
    int qn=sqrt(n);
    for(int i=0;i<=qn-2;i++)
    {
        if(max_exponent[i]==-1)
        {
            int value=i+2;
            int product_ex=value*value;
            int ex=2;
            for(ex;product_ex<=n;ex++)
            {
                max_exponent[product_ex-2]=0;
                product_ex*=value;
            }
            max_exponent[i]=ex-1;
        }
    }
    for(int i=qn-1;i<n-1;i++)
    {
        if(max_exponent[i]==-1)
            max_exponent[i]=1;
    }
}
void create_test(int test[], int n, int maxn)
{
    for(int i=2;i<=n;i++)
        test[i]=1;
    for(int i=n+1;i<=maxn*n;i++)
        test[i]=0;
}
int adjust_test(int test[], int n, int k)
{
    int sum=0;
    int consi=k*2;
    for(int i=2;i<=n;i++)
    {
        if(test[consi]==0)
        {
            sum++;
            test[consi]=1;
        }
        consi+=k;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int *max_exponent = new int[n-1];
    for(int i=0;i<n-1;i++)
        max_exponent[i]=-1;
    exponent(max_exponent,n);
    
    int maxn=max_exponent[0];
    int *test=new int[maxn*n+2];
    create_test(test,n,maxn);
    
    long long *core=new long long[maxn+1];
    core[0]=0;
    core[1]=n-1;
    for(int i=2;i<=maxn;i++)
        core[i]=core[i-1]+adjust_test(test,n,i);
    
    long long sum=0;
    for(int i=0;i<n-1;i++)
        sum+=core[max_exponent[i]];
    cout << sum;
}
