#include <stdio.h>
#include <math.h>

int main()
{
    double pi = 3.1415926;
    double r,s;
    int n;
    scanf("%lf,%d",&r,&n);
    s = n*r*r*sin(2*pi/n)/2;
    printf("Area=%.2lf\n",s);
    return 0;
}