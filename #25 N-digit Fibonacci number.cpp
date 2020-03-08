#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T,N;
    cin >> T;
    const double bias = log(sqrt(5))/log(10);
    const double g_ratio = log((1+sqrt(5))/2)/log(10);
    for(int test=0;test<T;test++)
    {
        cin >> N;
        if(N==1)
            cout << 1 << endl;
        else
        {
            int result = (N-1 + bias)/g_ratio+1;
            cout << result << endl;
        }
    }
    return 0;
}
