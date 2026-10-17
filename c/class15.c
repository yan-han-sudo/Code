#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c,num;
    double out,out1,out2,delta;
    scanf("%d%d%d",&a,&b,&c);
    if(a>=-100 && a<=100 && b>=-100 && b<=100 && c>=-100 && c<=100)
    {
        if(a != 0)
        {
            delta = b*b-4*a*c;
            if(delta < 0)
                printf("wa\n");
            else if(delta == 0)
            {
                num = 1;
                out = -(double)b/(2*a);
                printf("%d %.2lf\n",num,out);
            }
            else if(delta >0)
            {
                num = 2;
                out1 = ((-1*b)-sqrt(delta))/(a*2);
                out2 = ((-1*b)+sqrt(delta))/(a*2);
                if(out1 < out2)
                    printf("%d %.2lf %.2lf\n",num,out1,out2);
                else
                    printf("%d %.2lf %.2lf\n",num,out2,out1);
            }
        }
        else
        {
            if(b != 0)
            {
                num = 1;
                out = -(double)c/b;
                printf("%d %.2lf\n",num,out);
            }
            else
            {
                if(c != 0)
                    printf("wa\n");
                else
                    printf("inf\n");
            }
        }
    }
    else 
    {
        printf("wa\n");
    }
    return 0;
}