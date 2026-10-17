#include <stdio.h>

int main()
{
    double a,b,c,average;
    scanf("%lf%lf%lf",&a,&b,&c);
    average = (a+b+c)/3;
    printf("%.2lf\n",average);
    return 0;
}