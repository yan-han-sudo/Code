#include <stdio.h>
#include <math.h>

int main()
{
    int T,t;
    int i=0,j=0;
    scanf("%d",&T);
    t=T;
    float numlist[T];
    while(T--)
    {
        int a,b,c,S=0;
        scanf("%d,%d,%d",&a,&b,&c);
        S = (a+b+c)/2;
        numlist[i] = sqrt(S*(S-a)*(S-b)*(S-c));
        i++;
    }
    while(t--)
    {
        printf("%.2f\n",numlist[j]);
        j++;
    }
    return 0;
}