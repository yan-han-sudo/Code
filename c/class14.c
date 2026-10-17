#include <stdio.h>

int main()
{
    int in[3],max=0;
    for(int i=0;i<3;i++)
    {
        scanf("%d,",&in[i]);
    }
    for(int i=0;i<3;i++)
    {
        if(in[i] > max)
            max = in[i];
    }
    printf("The largest number is %d\n",max);
    return 0;
}