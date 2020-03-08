#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int SumOfDivisor(int N)
{
    if(N<=1)
        return 0;
    else
    {
        int qn = sqrt(N);
        int sum=1;
        for(int i=2;i<=qn;i++)
        {
            if(N%i == 0)
            {
                sum+=i;
                int bigDivisor = N/i;
                if(bigDivisor != i)
                    sum+=bigDivisor;
            }
            
        }
        return sum;
    }
}
int main() {
    int T;
    int *N;
    cin >> T;
    N=(int*)malloc(T*sizeof(int));
    int max=0;
    for(int test=0;test<T;test++)
    {
        cin >> N[test];
        if(max < N[test])
            max = N[test];
    }
    
    int *sum = (int*)malloc(max*sizeof(int));
    
    for(int i=0;i<max;i++)
    {
        sum[i]= SumOfDivisor(i+1);
    }
    
    int *result = (int*)malloc(max*sizeof(int));
    result[0]=0;
    for(int i=1;i<max;i++)
    {
        result[i] = result[i-1];
        if(  (sum[i] < max)  && ((i+1) == sum[sum[i]-1])  && (sum[i] != i+1))
            result[i] += i+1;
    }
    
    for(int test=0;test<T;test++)
    {
        cout << result[N[test]-1] << endl;
    }
    return 0;
}
