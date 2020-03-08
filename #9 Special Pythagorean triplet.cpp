#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int find_mn(int N, int* m, int* n)
{
    int cn=sqrt(N);
    for(*m;*m<=cn;(*m)++)
    {
        if(N%(*m)==0)
        {
            *n=N/(*m)-(*m);
            if(*n<*m)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int t,NN,N,max,cmax;
    int m,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&NN);
        int cN=sqrt(NN);
        max=0;
        for(int j=1;j<=cN;j++)
        {
            if(NN%j==0)
            {
                N=j;
                int temp=NN/j;
                if(N>=12 && (N%2==0))
                {
                    N=N/2;
                    
                    m=2;
                    n=0;
                    while(find_mn(N,&m,&n))
                    {
                        cmax=2*m*n*(m*m*m*m-n*n*n*n)*temp*temp*temp;
                        if(max<cmax)
                            max=cmax;
                        m++;
                    }
                    
                }
                
                N=NN/j;
                if(N>=12 && N%2==0)
                {
                    N=N/2;
                    
                    m=2;
                    n=0;
                    while(find_mn(N,&m,&n))
                    {
                        cmax=2*m*n*(m*m*m*m-n*n*n*n)*j*j*j;
                        if(max<cmax)
                            max=cmax;
                        m++;
                    }
                    
                }
                
            }
        
        
        }
        if(max==0)
            max=-1;
        printf("%d\n",max);
    }
    
    return 0;
}