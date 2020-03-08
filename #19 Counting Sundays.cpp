#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int DayOfMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int LeapYear(long long Y)
{
    return (((Y%4 == 0) && (Y%100 != 0)) || Y%400 == 0) ? 1:0;
}
int ToDay(long long Y, int M, int D)
{
    long long dayth = (Y-1)%7 + (Y-1)/4 - (Y-1)/100 + (Y-1)/400 + D-1;
    for(int i=1;i<M;i++)
        dayth+=DayOfMonth[i-1];
    if(M>2)
        dayth+=LeapYear(Y);
    dayth = dayth%7;
    return dayth;
}

void fix(long long &Y, int &M, int &D)
{
    if(D>1)
    {
        D=1;
        M++;
        if(M>12)
        {
            M=1;
            Y++;
        }
    }
}
            
int main() {
    int T;
    cin >> T;
    long long Y1,Y2;
    int M1,M2,D1,D2;
    for(int test=0;test<T;test++)
    {
        cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;
        
        int total = 0;
        fix(Y1,M1,D1);
        int today = ToDay(Y1,M1,D1);
        
        if(Y1<Y2)
        {
            for(int j=M1;j<=12;j++)
            {
                if(today == 6)
                total++;
                
                today = (today+DayOfMonth[j-1] + ((j==2) ? LeapYear(Y1):0))%7;
            }
        }
        
        for(long long i=Y1+1;i<Y2;i++)
        {
            for(int j=1;j<=12;j++)
            {
                if(today == 6)
                    total++;
                
                today = (today+DayOfMonth[j-1] + ((j==2) ? LeapYear(i):0))%7;
            }
        }
        int j=1;
        if(Y1 == Y2)
            j=M1;
        if(Y1<=Y2)
        {
            for(j;j<=M2;j++)
            {
                if(today == 6)
                    total++;
                
                today = (today+DayOfMonth[j-1] + ((j==2) ? LeapYear(Y2):0))%7;
            }
        }
        cout << total << endl;
    }
    return 0;
}
