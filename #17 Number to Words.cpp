#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void printword0(int a)
{
    switch(a)
    {
        case 0: break;
        case 1: printf("One "); break;
        case 2: printf("Two "); break;
        case 3: printf("Three "); break;
        case 4: printf("Four "); break;
        case 5: printf("Five "); break;
        case 6: printf("Six "); break;
        case 7: printf("Seven "); break;
        case 8: printf("Eight "); break;
        case 9: printf("Nine "); break;
    }
}
void printword2(int a)
{
    switch(a)
    {
        case 2: printf("Twenty "); break;
        case 3: printf("Thirty "); break;
        case 4: printf("Forty "); break;
        case 5: printf("Fifty "); break;
        case 6: printf("Sixty "); break;
        case 7: printf("Seventy "); break;
        case 8: printf("Eighty "); break;
        case 9: printf("Ninety "); break;
    }
}

void printword1(int a)
{
    switch(a)
    {
        case 0: printf("Ten "); break;
        case 1: printf("Eleven "); break;
        case 2: printf("Twelve "); break;
        case 3: printf("Thirteen "); break;
        case 4: printf("Fourteen "); break;
        case 5: printf("Fifteen "); break;
        case 6: printf("Sixteen "); break;
        case 7: printf("Seventeen "); break;
        case 8: printf("Eighteen "); break;
        case 9: printf("Nineteen "); break;
    }
}
int word(char a, char b, char c)
{
    if(a!=0)
    {
        printword0(a);
        printf("Hundred ");
    }
    if(b==1)
    {
        printword1(c);
    }
    else
    {
        if(b>1)
            printword2(b);
        printword0(c);
    }
    if(a!=0 || b!=0 || c!=0)
        return 1;
    return 0;
}
void input(char *n)
{
	do
	{
		gets(n, 14);
	} while (n[0] == 0 || n[0] == ' ');
}
int main() {
    int t;
    char n[14];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        input(n);
        int l=strlen(n);
        char w[14]={0};
        for(int i=13-l,j=0;j<l;i++,j++)
            w[i]=n[j]-'0';
        if(l==13)
                printf("One Thousand Billion");
         else
         {
                if(word(w[1],w[2],w[3]))
                    printf("Billion ");
                if(word(w[4],w[5],w[6]))
                    printf("Million ");
                if(word(w[7],w[8],w[9]))
                    printf("Thousand ");
                word(w[10],w[11],w[12]);
         } 
        printf("\n");
    }
    return 0;
}
