#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    char **c;
    char result[10];
    int pos=0,balance=0;
    scanf("%d",&n);
    c=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
    {
        c[i]=(char*)malloc(sizeof(char)*51);
        scanf("%s",c[i]);
    }
    for(int i=49;i>=0;i--)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            c[j][i]-='0';
            sum+=c[j][i];
        }
        sum+=balance;
        balance=sum/10;
        if(pos==10)
            pos=0;
        result[pos++]=(char)(sum%10);
    }
    while(balance!=0)
    {
        if(pos==10)
            pos=0;
        result[pos++]=(char)(balance%10);
        balance=balance/10;
        
    }
    for(int i=pos-1;i>=0;i--)
    {
        result[i]+='0';
        printf("%c",result[i]);
    }
    for(int i=9;i>=pos;i--)
    {
        result[i]+='0';
        printf("%c",result[i]);
    }
    return 0;
}
