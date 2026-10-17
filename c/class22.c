#include <stdio.h>

int divide(int a)
{
    if(a%2==0)
        return a/2;
    else
        return a/2+a%2;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",divide(n));
    return 0;
}