#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsAbundant(int N)
{
    if(N<=1)
        return false;
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
        return sum>N;
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
    
    bool *abundant = (bool*)malloc(max*sizeof(bool));
    
    for(int i=0;i<max;i++)
    {
        abundant[i]= IsAbundant(i+1);
    }
    
    for(int test=0;test<T;test++)
    {
        bool result = false;
        int half = N[test]/2;
        for(int i=0;i<half;i++)
        {
            if(abundant[i] && abundant[N[test]-2-i])
            {
                result=true;
                break;
            }
        }
        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
