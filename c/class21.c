#include <stdio.h>

int divide(int a,int b)
{
    if(a%b==0&&b%a!=0)
        return 1;
    if(a%b!=0&&b%a==0)
        return 2;
    if(a%b==0&&b%a==0)
        return 3;
    if(a%b!=0&&b%a!=0)
        return 4;
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d\n",divide(x,y));
    return 0;
}