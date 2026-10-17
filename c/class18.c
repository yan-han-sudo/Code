#include <stdio.h>

int main()
{
    int day;
    scanf("%d",&day);
    if(day==1||day==3||day==5)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}