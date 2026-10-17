#include <stdio.h>
#include <limits.h>

int main()
{
    int list[3];
    int m1=INT_MIN,m2=INT_MIN,m3=INT_MIN;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&list[i]);
    }
    for(int i=0;i<3;i++)
    {
        if(list[i]>m1)
            m1 = list[i];
    }
    for(int i=0;i<3;i++)
    {
        if(list[i]<m1 && list[i]>m2)
            m2 = list[i];
    }
    for(int i=0;i<3;i++)
    {
        if(list[i]<m2 && list[i]>m3)
            m3 = list[i];
    }
    printf("%d %d %d\n",m3,m2,m1);
    return 0;
}