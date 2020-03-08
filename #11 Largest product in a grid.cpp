#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int maxrow(int **a, int row, int maxrow, int maxcolumn)
{
    int max=a[row][0]*a[row][1]*a[row][2]*a[row][3];
    for(int i=1;i<=maxcolumn-4;i++)
    {
        int cmax=a[row][i]*a[row][i+1]*a[row][i+2]*a[row][i+3];
        if(max<cmax)
            max=cmax;
    }
    return max;
}
int maxcolumn(int **a, int column, int maxrow, int maxcolumn)
{
    int max=a[0][column]*a[1][column]*a[2][column]*a[3][column];
    for(int i=1;i<=maxrow-4;i++)
    {
        int cmax=a[i][column]*a[i+1][column]*a[i+2][column]*a[i+3][column];
        if(max<cmax)
            max=cmax;
    }
    return max;
}
int main()
{
    int **a;
    int **left1;
    int **right1;
    int **left2;
    int **right2;
    int **left3;
    int **right3;
    int **left4;
    int **right4;
    int **left5;
    int **right5;
    a=(int**)malloc(sizeof(int)*20);
    left1=(int**)malloc(sizeof(int*)*20);
    right1=(int**)malloc(sizeof(int*)*20);
    left2=(int**)malloc(sizeof(int*)*20);
    right2=(int**)malloc(sizeof(int*)*20);
    left3=(int**)malloc(sizeof(int*)*20);
    right3=(int**)malloc(sizeof(int*)*20);
    left4=(int**)malloc(sizeof(int*)*20);
    right4=(int**)malloc(sizeof(int*)*20);
    left5=(int**)malloc(sizeof(int*)*20);
    right5=(int**)malloc(sizeof(int*)*20);

    for(int i=0;i<20;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*20);
        left1[i]=(int*)calloc(39,sizeof(int));
        right1[i]=(int*)calloc(39,sizeof(int));
        left2[i]=(int*)calloc(58,sizeof(int));
        right2[i]=(int*)calloc(58,sizeof(int));
        left3[i]=(int*)calloc(77,sizeof(int));
        right3[i]=(int*)calloc(77,sizeof(int));
        left4[i]=(int*)calloc(96,sizeof(int));
        right4[i]=(int*)calloc(96,sizeof(int));
        left5[i]=(int*)calloc(115,sizeof(int));
        right5[i]=(int*)calloc(115,sizeof(int));
        for(int j=0,l1=19-i,r1=i,l2=38-i*2,r2=i*2,l3=57-i*3,r3=i*3,l4=76-i*4,r4=i*4,l5=95-i*5,r5=i*5;j<20;)
        {
            scanf("%d",&a[i][j]);
            left1[i][l1]=a[i][j];
            right1[i][r1]=a[i][j];
            left2[i][l2]=a[i][j];
            right2[i][r2]=a[i][j];
            left3[i][l3]=a[i][j];
            right3[i][r3]=a[i][j];
            left4[i][l4]=a[i][j];
            right4[i][r4]=a[i][j];
            left5[i][l5]=a[i][j];
            right5[i][r5]=a[i][j];
            j++,l1++,r1++,l2+=2,r2+=2,l3+=3,r3+=3,l4+=4,r4+=4,l5+=5,r5+=5;
        }
    }
    int max=0;
    for(int i=0;i<20;i++)
    {
        int cmax;
        cmax=maxrow(a,i,20,20);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(a,i,20,20);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(left1,i,20,39);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(right1,i,20,39);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(left2,i,20,58);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(right2,i,20,58);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(left3,i,20,77);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(right3,i,20,77);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(left4,i,20,96);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(right4,i,20,96);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(left5,i,20,115);
        if(max<cmax)
            max=cmax;
        cmax=maxcolumn(right5,i,20,115);
        if(max<cmax)
            max=cmax;
    }
    printf("%d",max);
    return 0;
}