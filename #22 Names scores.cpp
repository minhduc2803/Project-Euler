#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int compare(const void *a, const void *b)
{
    return strcmp(*(char**)(a),*(char**)(b));
}
int value(char *buff)
{
    int sum=0;
    for(int i=0;buff[i]!=0;i++)
    {
        sum+=buff[i]-'A'+1;
    }
    return sum;
}
int position(char **name, int N, char *buff)
{
    for(int i=0;i<N;i++)
    {
        if(strcmp(name[i],buff) == 0)
            return i+1;
    }
    return 0;
}
int main() {
    int N,Q;
    cin >> N;
    char **name = (char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++)
    {
        name[i]  = (char*)malloc(13*sizeof(char));
        scanf("%s",name[i]);
    }
    qsort(name,N,sizeof(char*),compare);
    cin >> Q;
    char buff[13];
    for(int i=0;i<Q;i++)
    {
        cin >> buff;
        int result = position(name,N,buff)*value(buff);
        cout << result << endl;
    }
    return 0;
}
