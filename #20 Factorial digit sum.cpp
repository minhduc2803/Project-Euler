#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char* op(char *a, int b)
{
    char *c;
    c=new char[2600];
    int i=0,mul=0,result;
    for(i;a[i]!=-1;i++)
    {
        result=b*a[i]+mul;
        c[i]=result%10;
        mul=result/10;
    }
    while(mul!=0)
    {
        c[i++]=mul%10;
        mul/=10;
    }
    c[i]=-1;
    return c;
}

int main() {
    int t,*n,max=0;
    cin >> t;
    n=new int[t];
    for(int i=0;i<t;i++)
    {
        cin >> n[i];
        if(n[i]==0)
            n[i]=1;
        if(max<n[i])
            max=n[i];
    }
    char **fac;
    fac=new char*[max];
    fac[0]=new char[2];
    fac[0][0]=1; fac[0][1]=-1;
    for(int i=1;i<max;i++)
    {
        fac[i]=op(fac[i-1],(i+1));
    }
    int sum;
    for(int i=0;i<t;i++)
    {
        sum=0;
        for(int j=0;fac[n[i]-1][j]!=-1;j++)
            sum+=fac[n[i]-1][j];
        cout << sum << endl;
    }
    return 0;
}
