#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void fix(char *word, int position)
{
    for(int i=position;i<12;i++)
    {
        word[i]=word[i+1];
    }
}
int main() {
    int T;
    cin >> T;
    long long N;
    int order[12];
    order[11]=1;
    for(int i=10;i>=0;i--)
    {
        order[i]=order[i+1]*(12-i);
    }

    for(int test=0;test<T;test++)
    {
        cin >> N;
        char word[]="abcdefghijklm";
        char result[14];
        result[13]=0;
        for(int i=0;i<12;i++)
        {
            int socket = (N-1)/order[i];
            N=N-socket*order[i];
            result[i]=word[socket];
            fix(word,socket);
        }
        result[12]=word[0];
        cout << result << endl;
    }
    return 0;
}
