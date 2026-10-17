#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float e = 0.001;
    float arealist[n];
    int typelist[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        float a,b,c;
        scanf("%f%f%f",&a,&b,&c);
        if(a+b>c&&a+c>b&&b+c>a)
        {
            float s = (a+b+c)/2;
            float A = sqrt(s*(s-a)*(s-b)*(s-c));
            arealist[i] = A;

            float x1 = a*a+b*b-c*c;
            float x2 = a*a+c*c-b*b;
            float x3 = b*b+c*c-a*a;
            if(fabs(a-b)<e||fabs(a-c)<e||fabs(b-c)<e)
            {
                if(fabs(a-b)<e&&fabs(a-c)<e&&fabs(b-c)<e)
                    typelist[i] = 4;
                else if (fabs(x1)<e||fabs(x2)<e||fabs(x3)<e)
                    typelist[i] = 3;
                else
                    typelist[i] = 1;
            }
            else if(fabs(x1)<e||fabs(x2)<e||fabs(x3)<e)
            {
                typelist[i] = 2;
            }
            else {
                typelist[i] = 5;
            }
        }
        else{
            typelist[i] = 6;
        }
    }

    for(int i=0;i<n;i++)
    {
        switch (typelist[i]) 
        {
            case 1:
                printf("isosceles triangle, %.1f\n",arealist[i]);
                break;
            case 2:
                printf("right triangle, %.1f\n",arealist[i]);
                break;
            case 3:
                printf("isosceles right triangle, %.1f\n",arealist[i]);
                break;
            case 4:
                printf("equilateral triangle, %.1f\n",arealist[i]);
                break;
            case 5:
                printf("general triangle, %.1f\n",arealist[i]);
                break;
            case 6:
                printf("no triangle\n");
                break;
        }
    }
    return 0;
}