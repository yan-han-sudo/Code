#include <stdio.h>
#include <math.h>

int main()
{
    double dis,walk,bike;
    double e = 1e-8;
    scanf("%lf",&dis);
    bike = dis/3.0+27+23;
    walk = dis/1.2;
    if(fabs(walk-bike)<e)
        printf("All\n");
    else if(walk<bike)
        printf("Walk\n");
    else
        printf("Bike\n");
    return 0;
}