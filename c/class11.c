#include <stdio.h>

int main()
{
    int num,a,b,c,out;
    scanf("%d",&num);
    a = num/100;
    b = (num/10)%10;
    c = num%10;
    int temp = a;
    a = c;
    c = temp;
    out = a*100+b*10+c;
    printf("%d\n",out);
    return 0;
}